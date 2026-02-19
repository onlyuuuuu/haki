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
echo  Clangd C/C++ Language Server
echo   Install / Update
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

:: Install directory used only for manual (non-winget) installs
if "!IS_ADMIN!"=="1" (
    set "INSTALL_DIR=C:\tools\clangd"
    set "TOOLS_DIR=C:\tools"
) else (
    set "INSTALL_DIR=%USERPROFILE%\tools\clangd"
    set "TOOLS_DIR=%USERPROFILE%\tools"
)

:: ----------------------------------------
:: STEP 1: Check current state
:: ----------------------------------------
echo [STEP 1] Checking current clangd installation...
set "CLANGD_INSTALLED=0"
set "INSTALLED_VER="
where clangd >nul 2>&1
if %errorLevel% equ 0 (
    set "CLANGD_INSTALLED=1"
    for /f "tokens=3" %%v in ('clangd --version 2^>nul ^| findstr /i "version"') do set "INSTALLED_VER=%%v"
    echo [INFO] clangd is installed: version !INSTALLED_VER!
) else (
    echo [INFO] clangd not found in PATH
)
echo.

:: ----------------------------------------
:: STEP 2: Check package managers
:: ----------------------------------------
echo [STEP 2] Checking package managers...
set "PKG_MGR="
where winget >nul 2>&1
if %errorLevel% equ 0 (
    set "PKG_MGR=winget"
    echo [OK] Found winget
) else (
    rem chocolatey requires admin - only use if we have it
    if "!IS_ADMIN!"=="1" (
        where choco >nul 2>&1
        if not errorLevel 1 (
            set "PKG_MGR=choco"
            echo [OK] Found chocolatey
        )
    ) else (
        echo [INFO] chocolatey requires administrator - skipping
    )
    if not defined PKG_MGR echo [INFO] No package manager found, will use manual download
)
echo.

:: ----------------------------------------
:: STEP 3: Install or update via winget (preferred)
:: Running the script again upgrades automatically.
:: ----------------------------------------
if "!PKG_MGR!"=="winget" (
    if "!CLANGD_INSTALLED!"=="1" (
        rem Already installed - try to upgrade
        echo [STEP 3] Upgrading LLVM/clangd via winget...
        winget upgrade --id=LLVM.LLVM --accept-package-agreements --accept-source-agreements
        if not errorLevel 1 (
            echo [OK] winget upgrade complete
            call :RefreshPath
            goto :verify
        )
        echo [INFO] winget upgrade returned non-zero ^(may already be latest^)
        call :RefreshPath
        where clangd >nul 2>&1
        if not errorLevel 1 goto :verify
        rem winget upgrade failed and clangd is gone - fall through to install
    )

    rem Not installed (or upgrade cleared it) - do a fresh install
    echo [STEP 3] Installing LLVM/clangd via winget...
    if "!IS_ADMIN!"=="1" (
        winget install --id=LLVM.LLVM -e --accept-package-agreements --accept-source-agreements
    ) else (
        echo [INFO] Attempting user-scope install ^(no elevation required^)...
        winget install --id=LLVM.LLVM -e --scope user --accept-package-agreements --accept-source-agreements
    )
    if not errorLevel 1 (
        echo [OK] LLVM/clangd installed via winget
        call :RefreshPath
        goto :verify
    )
    echo [WARNING] winget install failed, falling back to manual download...
    echo.
)

if "!PKG_MGR!"=="choco" (
    echo [STEP 3] Installing/updating LLVM/clangd via chocolatey...
    choco upgrade llvm -y
    if not errorLevel 1 (
        echo [OK] LLVM/clangd installed/updated via chocolatey
        call :RefreshPath
        goto :verify
    )
    echo [WARNING] chocolatey failed, falling back to manual download...
    echo.
)

:: ----------------------------------------
:: STEP 4: Manual download from GitHub
:: Skips download if already on latest version (unless --force).
:: ----------------------------------------
echo [STEP 4] Manual clangd install/update via GitHub releases...

where powershell >nul 2>&1
if errorLevel 1 (
    echo [ERROR] PowerShell not found - required for manual download
    echo [INFO] Get clangd manually: https://github.com/clangd/clangd/releases
    goto :failed
)

:: Check latest version on GitHub and compare with installed version
set "PS=!TEMP!\clangd_ver.ps1"
echo $ErrorActionPreference = 'Stop' > "!PS!"
echo try { >> "!PS!"
echo     $r = Invoke-RestMethod -Uri 'https://api.github.com/repos/clangd/clangd/releases/latest' -UseBasicParsing >> "!PS!"
echo     Write-Host $r.tag_name >> "!PS!"
echo } catch { Write-Host 'ERROR'; exit 1 } >> "!PS!"
for /f "tokens=*" %%v in ('powershell -NoProfile -ExecutionPolicy Bypass -File "!PS!" 2^>nul') do set "LATEST_VER=%%v"
del "!PS!" 2>nul

if "!LATEST_VER!"=="ERROR" (
    echo [WARNING] Could not query GitHub API for latest version
    set "LATEST_VER="
)

if defined LATEST_VER (
    echo [INFO] Installed version: !INSTALLED_VER!
    echo [INFO] Latest version:    !LATEST_VER!
    if "!INSTALLED_VER!"=="!LATEST_VER!" (
        if "!FORCE!"=="0" (
            echo [SKIP] clangd !INSTALLED_VER! is already the latest version
            echo [INFO] Run with --force to reinstall
            goto :verify
        )
        echo [INFO] --force specified, reinstalling !LATEST_VER!...
    ) else (
        if not defined INSTALLED_VER (
            echo [INFO] Downloading clangd !LATEST_VER!...
        ) else (
            echo [INFO] Updating clangd !INSTALLED_VER! -^> !LATEST_VER!...
        )
    )
)

:: Proceed with download and install
if not exist "!TOOLS_DIR!" mkdir "!TOOLS_DIR!" >nul 2>&1

set "PS=!TEMP!\clangd_dl.ps1"
echo $ErrorActionPreference = 'Stop' > "!PS!"
echo try { >> "!PS!"
echo     $r = Invoke-RestMethod -Uri 'https://api.github.com/repos/clangd/clangd/releases/latest' -UseBasicParsing >> "!PS!"
echo     $asset = $null >> "!PS!"
echo     foreach ($a in $r.assets) { >> "!PS!"
echo         if ($a.name -match 'windows.*\.zip$') { $asset = $a; break } >> "!PS!"
echo     } >> "!PS!"
echo     if ($null -eq $asset) { throw 'No Windows zip asset found in release' } >> "!PS!"
echo     Write-Host "[INFO] Downloading clangd $($r.tag_name)..." >> "!PS!"
echo     $zip = "$env:TEMP\clangd.zip" >> "!PS!"
echo     Invoke-WebRequest -Uri $asset.browser_download_url -OutFile $zip -UseBasicParsing >> "!PS!"
echo     $tmp = "$env:TEMP\clangd_extract" >> "!PS!"
echo     if (Test-Path $tmp) { Remove-Item $tmp -Recurse -Force } >> "!PS!"
echo     Expand-Archive -Path $zip -DestinationPath $tmp -Force >> "!PS!"
echo     $items = Get-ChildItem $tmp >> "!PS!"
echo     if ($items.Count -eq 0) { throw 'Archive extracted but produced no files' } >> "!PS!"
echo     if ($items.Count -eq 1 -and $items[0].PSIsContainer) { >> "!PS!"
echo         $src = $items[0].FullName >> "!PS!"
echo     } else { >> "!PS!"
echo         $src = $tmp >> "!PS!"
echo     } >> "!PS!"
echo     $dst = '!INSTALL_DIR!' >> "!PS!"
echo     if (Test-Path $dst) { Remove-Item $dst -Recurse -Force } >> "!PS!"
echo     $parent = Split-Path $dst >> "!PS!"
echo     if (-not (Test-Path $parent)) { $null = New-Item -ItemType Directory -Path $parent -Force } >> "!PS!"
echo     Move-Item -Path $src -Destination $dst >> "!PS!"
echo     Remove-Item $zip -Force -ErrorAction SilentlyContinue >> "!PS!"
echo     if ($src -ne $tmp) { Remove-Item $tmp -Recurse -Force -ErrorAction SilentlyContinue } >> "!PS!"
echo     Write-Host "[OK] clangd installed to $dst" >> "!PS!"
echo } catch { >> "!PS!"
echo     Write-Host "[ERROR] $($_.Exception.Message)" >> "!PS!"
echo     exit 1 >> "!PS!"
echo } >> "!PS!"

powershell -NoProfile -ExecutionPolicy Bypass -File "!PS!"
set "PS_ERR=!errorLevel!"
del "!PS!" 2>nul

if "!PS_ERR!" neq "0" (
    echo [ERROR] Download/install failed
    echo [INFO] Get clangd manually: https://github.com/clangd/clangd/releases
    goto :failed
)

:: Add install dir bin to user PATH (only needed for manual install)
set "CLANGD_BIN=!INSTALL_DIR!\bin"
if not exist "!CLANGD_BIN!" set "CLANGD_BIN=!INSTALL_DIR!"

echo [INFO] Updating user PATH...
for /f "skip=2 tokens=2*" %%a in ('reg query "HKCU\Environment" /v PATH 2^>nul') do set "USER_PATH=%%b"
echo !USER_PATH! | findstr /i "!INSTALL_DIR!" >nul 2>&1
if errorLevel 1 (
    if defined USER_PATH (
        setx PATH "!CLANGD_BIN!;!USER_PATH!" >nul 2>&1
    ) else (
        setx PATH "!CLANGD_BIN!" >nul 2>&1
    )
    if not errorLevel 1 (
        echo [OK] Added !CLANGD_BIN! to user PATH ^(restart terminal to apply^)
        set "PATH=!CLANGD_BIN!;!PATH!"
    ) else (
        echo [WARNING] Could not update PATH - add manually: !CLANGD_BIN!
    )
) else (
    echo [SKIP] !CLANGD_BIN! already in user PATH
    set "PATH=!CLANGD_BIN!;!PATH!"
)

:verify
call :RefreshPath
echo.
echo [STEP 5] Verifying clangd...
where clangd >nul 2>&1
if %errorLevel% equ 0 (
    for /f "tokens=3" %%v in ('clangd --version 2^>nul ^| findstr /i "version"') do set "FINAL_VER=%%v"
    echo [OK] clangd !FINAL_VER! is ready
) else (
    echo [WARNING] clangd not found in PATH yet - restart your terminal
)

echo.
echo ========================================
echo  Done
echo ========================================
echo.
echo clangd provides C/C++ language features:
echo   - Code completion and signatures
echo   - Jump to definition / Find references
echo   - Diagnostics and clang-format
echo.
echo Run this script again anytime to check for updates.
echo.
if "%AUTO_MODE%"=="0" pause
exit /b 0

:failed
echo.
echo ========================================
echo  Installation Failed
echo ========================================
echo.
echo Get clangd manually:
echo   https://github.com/clangd/clangd/releases
echo   Extract to: !INSTALL_DIR!
echo   Add !INSTALL_DIR!\bin to your PATH
echo.
if "%AUTO_MODE%"=="0" pause
exit /b 1

:: Refresh PATH from registry without restarting terminal
:RefreshPath
set "SysPath="
set "UsrPath="
for /f "skip=2 tokens=2*" %%a in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v PATH 2^>nul') do set "SysPath=%%b"
for /f "skip=2 tokens=2*" %%a in ('reg query "HKCU\Environment" /v PATH 2^>nul') do set "UsrPath=%%b"
if defined SysPath if defined UsrPath (
    set "PATH=!SysPath!;!UsrPath!"
) else if defined SysPath (
    set "PATH=!SysPath!"
) else if defined UsrPath (
    set "PATH=!UsrPath!"
)
exit /b 0
