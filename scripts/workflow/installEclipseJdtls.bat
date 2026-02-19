@echo off
setlocal enabledelayedexpansion

set "AUTO_MODE=0"
set "FORCE=0"
for %%a in (%*) do (
    if /i "%%a"=="-y"      set "AUTO_MODE=1"
    if /i "%%a"=="--auto"  set "AUTO_MODE=1"
    if /i "%%a"=="--force" set "FORCE=1"
)

echo ========================================
echo  Eclipse JDT.LS Java Language Server
echo       Build from Source (Windows)
echo ========================================
echo.

:: Check if running as administrator
net session >nul 2>&1
set "IS_ADMIN=0"
if %errorLevel% equ 0 (
    set "IS_ADMIN=1"
    echo [INFO] Running with administrator privileges
) else (
    echo [INFO] Not running as administrator
)
echo.

:: Paths - mirrors the Unix /tools/ convention
:: SOURCE_DIR : git clone location
:: BUILD_OUTPUT: where mvnw puts the repository (mirrors langServerUp path)
:: JUNCTION_DIR: eclipse-java-ls -> BUILD_OUTPUT  (mirrors setup's ln -sf)
:: DATA_DIR    : jdtls workspace data (mirrors langServerUp -data flag)
if "!IS_ADMIN!"=="1" (
    set "TOOLS_DIR=C:\tools"
) else (
    set "TOOLS_DIR=%USERPROFILE%\tools"
)
set "SOURCE_DIR=!TOOLS_DIR!\eclipse.jdt.ls"
set "BUILD_OUTPUT=!SOURCE_DIR!\org.eclipse.jdt.ls.product\target\repository"
set "JUNCTION_DIR=!TOOLS_DIR!\eclipse-java-ls"
set "DATA_DIR=%USERPROFILE%\tools\java-lang-server-data"

echo [INFO] Source:    !SOURCE_DIR!
echo [INFO] Built at:  !BUILD_OUTPUT!
echo [INFO] Linked as: !JUNCTION_DIR!
echo [INFO] Data dir:  !DATA_DIR!
echo.

:: ----------------------------------------
:: STEP 1: Check git
:: ----------------------------------------
echo [STEP 1] Checking for git...
where git >nul 2>&1
if errorLevel 1 (
    echo [ERROR] git not found in PATH
    echo [INFO] Install from: https://git-scm.com/download/win
    echo [INFO] Or via winget: winget install --id=Git.Git
    if "%AUTO_MODE%"=="0" pause
    exit /b 1
)
for /f "tokens=3" %%v in ('git --version') do echo [OK] git %%v
echo.

:: ----------------------------------------
:: STEP 2: Check Java
:: ----------------------------------------
echo [STEP 2] Checking for Java...
where java >nul 2>&1
if errorLevel 1 (
    echo [ERROR] java not found in PATH. Java 21+ is required to build eclipse.jdt.ls.
    echo [INFO] Install via: winget install --id=Microsoft.OpenJDK.21
    if "%AUTO_MODE%"=="0" pause
    exit /b 1
)
for /f "tokens=3" %%v in ('java -version 2^>^&1 ^| findstr /i "version"') do set "JAVA_VER=%%~v"
echo [OK] Java %JAVA_VER% found
echo.

:: ----------------------------------------
:: STEP 3: Detect JAVA_HOME (required by mvnw)
:: ----------------------------------------
echo [STEP 3] Detecting JAVA_HOME...
if not defined JAVA_HOME (
    set "JAVA_EXE="
    for /f "tokens=*" %%j in ('where java 2^>nul') do if not defined JAVA_EXE set "JAVA_EXE=%%j"
    if defined JAVA_EXE (
        rem java.exe is in JAVA_HOME\bin\ - go up one level from bin\
        for %%j in ("!JAVA_EXE!") do set "JAVA_HOME_TMP=%%~dpj.."
        for %%j in ("!JAVA_HOME_TMP!") do set "JAVA_HOME=%%~fj"
        echo [OK] JAVA_HOME detected: !JAVA_HOME!
    ) else (
        echo [WARNING] Could not detect JAVA_HOME automatically
        echo [INFO] Set JAVA_HOME manually if the Maven build fails
    )
) else (
    echo [OK] JAVA_HOME already set: !JAVA_HOME!
)
echo.

:: ----------------------------------------
:: STEP 4: Clone or verify source repo
:: ----------------------------------------
echo [STEP 4] Setting up eclipse.jdt.ls source...
if not exist "!TOOLS_DIR!" mkdir "!TOOLS_DIR!" >nul 2>&1

set "FIRST_CLONE=0"
if not exist "!SOURCE_DIR!\.git" (
    echo [INFO] Cloning eclipse.jdt.ls repository ^(shallow clone^)...
    git clone --depth 1 https://github.com/eclipse-jdtls/eclipse.jdt.ls.git "!SOURCE_DIR!"
    if errorLevel 1 (
        echo [ERROR] Git clone failed
        goto :failed
    )
    set "FIRST_CLONE=1"
    echo [OK] Cloned to !SOURCE_DIR!
) else (
    echo [INFO] Repository already exists at !SOURCE_DIR!
)
echo.

:: ----------------------------------------
:: STEP 5: Check for updates / decide whether to build
:: ----------------------------------------
echo [STEP 5] Checking for updates...
set "NEED_BUILD=0"

if "!FIRST_CLONE!"=="1" (
    set "NEED_BUILD=1"
    echo [INFO] First clone - build required
    goto :do_build
)

if "!FORCE!"=="1" (
    set "NEED_BUILD=1"
    echo [INFO] --force specified - pulling and rebuilding
    git -C "!SOURCE_DIR!" pull
    goto :do_build
)

:: Fetch remote HEAD to compare with local
echo [INFO] Fetching remote HEAD for comparison...
git -C "!SOURCE_DIR!" fetch --depth 1 origin >nul 2>&1
for /f %%h in ('git -C "!SOURCE_DIR!" rev-parse HEAD 2^>nul') do set "LOCAL_HEAD=%%h"
for /f %%h in ('git -C "!SOURCE_DIR!" rev-parse FETCH_HEAD 2^>nul') do set "REMOTE_HEAD=%%h"

echo [INFO] Local HEAD:  !LOCAL_HEAD!
echo [INFO] Remote HEAD: !REMOTE_HEAD!

if "!LOCAL_HEAD!"=="!REMOTE_HEAD!" (
    if exist "!BUILD_OUTPUT!\plugins" (
        echo [SKIP] eclipse.jdt.ls is up-to-date and already built
        echo [INFO] Run with --force to rebuild
        goto :create_junction
    ) else (
        echo [INFO] Source is up-to-date but build output is missing - building now
        set "NEED_BUILD=1"
    )
) else (
    echo [INFO] Updates available - pulling and rebuilding
    git -C "!SOURCE_DIR!" pull
    set "NEED_BUILD=1"
)

:do_build
echo.

:: ----------------------------------------
:: STEP 6: Build with Maven Wrapper
:: ----------------------------------------
if "!NEED_BUILD!"=="1" (
    echo [STEP 6] Building eclipse.jdt.ls ^(this will take several minutes^)...
    echo [INFO] JAVA_HOME: !JAVA_HOME!
    echo [INFO] Threads:   %NUMBER_OF_PROCESSORS% ^(NUMBER_OF_PROCESSORS^)
    echo.

    if not exist "!SOURCE_DIR!\mvnw.cmd" (
        echo [ERROR] mvnw.cmd not found in !SOURCE_DIR!
        echo [INFO] The Maven Wrapper should be part of the repository
        goto :failed
    )

    pushd "!SOURCE_DIR!"
    call mvnw.cmd -T %NUMBER_OF_PROCESSORS% clean verify -U -DskipTests=true
    set "BUILD_ERR=!errorLevel!"
    popd

    if "!BUILD_ERR!" neq "0" (
        echo.
        echo [ERROR] Maven build failed ^(exit code !BUILD_ERR!^)
        echo [INFO] Check output above for details
        goto :failed
    )
    echo.
    echo [OK] Build succeeded

    rem Clear stale jdtls cache so Neovim picks up the new server
    if exist "%USERPROFILE%\.cache\jdtls\config" (
        move /y "%USERPROFILE%\.cache\jdtls\config" "%USERPROFILE%\.cache\jdtls\config-OLD" >nul 2>&1
        echo [INFO] Rotated old jdtls config cache to config-OLD
    )
    if exist "%USERPROFILE%\.cache\jdtls\workspace" (
        move /y "%USERPROFILE%\.cache\jdtls\workspace" "%USERPROFILE%\.cache\jdtls\workspace-OLD" >nul 2>&1
        echo [INFO] Rotated old jdtls workspace cache to workspace-OLD
    )
    echo.
)

:create_junction
:: ----------------------------------------
:: STEP 7: Create junction eclipse-java-ls -> build output
:: Mirrors: ln -sf org.eclipse.jdt.ls.product/target/repository /tools/eclipse-java-ls
:: mklink /J does NOT require administrator privileges
:: ----------------------------------------
echo [STEP 7] Linking eclipse-java-ls to build output...

if not exist "!BUILD_OUTPUT!\plugins" (
    echo [ERROR] Build output not found: !BUILD_OUTPUT!
    echo [INFO] Run with --force to trigger a fresh build
    goto :failed
)

:: Remove existing junction or directory if present
if exist "!JUNCTION_DIR!" (
    rem rmdir without /s removes a junction without deleting its contents
    rmdir "!JUNCTION_DIR!" >nul 2>&1
    rem If it was a real directory (not a junction), remove it properly
    if exist "!JUNCTION_DIR!" rmdir /s /q "!JUNCTION_DIR!" >nul 2>&1
)

mklink /J "!JUNCTION_DIR!" "!BUILD_OUTPUT!" >nul 2>&1
if not errorLevel 1 (
    echo [OK] Junction created:
    echo      !JUNCTION_DIR!
    echo      -^> !BUILD_OUTPUT!
) else (
    echo [WARNING] mklink /J failed - using build output path directly
    echo [INFO] Configure your editor to use: !BUILD_OUTPUT!
)
echo.

:: ----------------------------------------
:: STEP 8: Create workspace data directory
:: ----------------------------------------
echo [STEP 8] Creating workspace data directory...
if not exist "!DATA_DIR!" (
    mkdir "!DATA_DIR!" >nul 2>&1
    echo [OK] Created: !DATA_DIR!
) else (
    echo [SKIP] Already exists: !DATA_DIR!
)
echo.

:: ----------------------------------------
:: STEP 9: Verify
:: ----------------------------------------
echo [STEP 9] Verifying installation...

set "REPO_DIR=!JUNCTION_DIR!"
if not exist "!JUNCTION_DIR!\plugins" set "REPO_DIR=!BUILD_OUTPUT!"

if exist "!REPO_DIR!\plugins" (
    echo [OK] Installation verified at !REPO_DIR!
) else (
    echo [ERROR] plugins\ not found - installation may have failed
)

set "LAUNCHER_FOUND=0"
for %%f in ("!REPO_DIR!\plugins\org.eclipse.equinox.launcher_*.jar") do (
    echo [OK] Launcher jar: %%~nxf
    set "LAUNCHER_FOUND=1"
)
if "!LAUNCHER_FOUND!"=="0" echo [WARNING] Launcher jar not found in plugins\

if exist "!REPO_DIR!\config_win" (
    echo [OK] Windows config: config_win\
) else (
    echo [WARNING] config_win\ not found
)

echo.
echo ========================================
echo  Eclipse JDT.LS Installation Complete
echo ========================================
echo.
echo Source:    !SOURCE_DIR!
echo Built at:  !BUILD_OUTPUT!
echo Linked as: !JUNCTION_DIR!
echo Data dir:  !DATA_DIR!
echo.
echo ========================================
echo  Neovim / nvim-jdtls Configuration
echo ========================================
echo.
echo In ftplugin/java.lua, update the cmd path for Windows:
echo.
echo   local project = vim.fn.fnamemodify(vim.fn.getcwd(), ':p:h:t'^)
echo   local workspace = '!DATA_DIR:\=/!' .. '/' .. project
echo   local config = {
echo     cmd = { '!JUNCTION_DIR:\=/!/bin/jdtls', '-data', workspace },
echo     root_dir = vim.fs.dirname(vim.fs.find(
echo       {'gradlew', 'gradlew.bat', '.git', 'mvnw'}, { upward = true }^)[1]^),
echo   }
echo.
echo Or reference the build output directly:
echo   cmd path: !BUILD_OUTPUT!\bin\jdtls
echo.
echo ========================================
echo  Next Steps
echo ========================================
echo.
echo 1. Restart your terminal
echo 2. Update ftplugin/java.lua with Windows paths ^(see above^)
echo 3. To update later, re-run this script ^(will skip build if up-to-date^)
echo 4. Run with --force to force a clean rebuild
echo.
if "%AUTO_MODE%"=="0" pause
exit /b 0

:failed
echo.
echo ========================================
echo  Installation Failed
echo ========================================
echo.
echo Troubleshooting:
echo   - Ensure git is installed and in PATH
echo   - Ensure Java 21+ is installed and JAVA_HOME is set
echo   - Check network connectivity for git clone
echo   - Check the Maven build output above for errors
echo   - Try running: cd !SOURCE_DIR! ^&^& mvnw.cmd clean verify -U -DskipTests=true
echo.
if "%AUTO_MODE%"=="0" pause
exit /b 1
