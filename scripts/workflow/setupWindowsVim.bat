@echo off
setlocal enabledelayedexpansion

:: Parse command line arguments
set "AUTO_MODE=0"
if /i "%1"=="-y" set "AUTO_MODE=1"
if /i "%1"=="--auto" set "AUTO_MODE=1"
if /i "%1"=="--silent" set "AUTO_MODE=1"

echo ========================================
echo Vim Windows Setup Script
echo ========================================
echo.

:: Check if running as administrator
net session >nul 2>&1
set "IS_ADMIN=0"
if %errorLevel% equ 0 (
    set "IS_ADMIN=1"
    echo [INFO] Running with administrator privileges
) else (
    echo [WARNING] Not running as administrator
    echo Some operations may require manual intervention
)
echo.

:: Determine script directory
set "SCRIPT_DIR=%~dp0"
set "VIMRC_SOURCE=%SCRIPT_DIR%_vimrc"

echo [INFO] Script directory: %SCRIPT_DIR%
echo [INFO] Vim config source: %VIMRC_SOURCE%
echo.

:: Check if source _vimrc exists
if not exist "%VIMRC_SOURCE%" (
    echo [ERROR] Source _vimrc not found: %VIMRC_SOURCE%
    if "%AUTO_MODE%"=="0" pause
    exit /b 1
)

:: Check for package manager (winget preferred, chocolatey as fallback)
echo [STEP 1] Checking for package managers...
set "PKG_MGR="
where winget >nul 2>&1
if %errorLevel% equ 0 (
    set "PKG_MGR=winget"
    echo [OK] Found winget package manager
) else (
    where choco >nul 2>&1
    if errorLevel 1 (
        echo [WARNING] Neither winget nor chocolatey found
        echo [INFO] Will attempt manual installation if needed
        echo.
        echo To install a package manager:
        echo   - winget: Built into Windows 10 1809+ and Windows 11
        echo   - choco: Visit https://chocolatey.org/install
        echo.
    ) else (
        set "PKG_MGR=choco"
        echo [OK] Found chocolatey package manager
    )
)
echo.

:: Install Vim
echo [STEP 2] Installing Vim...
where vim >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] Vim already installed
    vim --version 2>nul | findstr /C:"VIM -" 2>nul
    if errorLevel 1 (
        echo [INFO] Vim found in PATH
    )
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            echo Installing via winget...
            winget install --id=vim.vim -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [WARNING] Winget installation failed, trying without silent mode...
                winget install --id=vim.vim -e --accept-package-agreements --accept-source-agreements
                if errorLevel 1 (
                    echo [WARNING] Automatic installation failed
                    echo [INFO] Please install Vim manually from https://www.vim.org/download.php
                ) else (
                    echo [OK] Vim installed successfully
                )
            ) else (
                echo [OK] Vim installed successfully
            )
        ) else (
            echo Installing via chocolatey...
            choco install vim -y
            if errorLevel 1 (
                echo [WARNING] Automatic installation failed
                echo [INFO] Please install Vim manually from https://www.vim.org/download.php
            ) else (
                echo [OK] Vim installed successfully
            )
        )
    ) else (
        echo [SKIP] No package manager available
        echo [INFO] Please install Vim manually from https://www.vim.org/download.php
        echo [INFO] Configuration will still be copied
    )
)
echo.

:: Install Git (required for vim-plug and plugins)
echo [STEP 3] Installing Git...
where git >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] Git already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=Git.Git -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                winget install --id=Git.Git -e --accept-package-agreements --accept-source-agreements
                if errorLevel 1 (
                    echo [WARNING] Git installation failed
                ) else (
                    echo [OK] Git installed
                )
            ) else (
                echo [OK] Git installed
            )
        ) else (
            choco install git -y
            if errorLevel 1 (
                echo [WARNING] Git installation failed
            ) else (
                echo [OK] Git installed
            )
        )
    ) else (
        echo [SKIP] No package manager - Git installation skipped
    )
)
echo.

:: Install Python (for some plugins)
echo [STEP 4] Installing Python...
where python >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] Python already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=Python.Python.3.12 -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                winget install --id=Python.Python.3.11 -e --accept-package-agreements --accept-source-agreements 2>nul
                if errorLevel 1 (
                    echo [WARNING] Python installation failed
                ) else (
                    echo [OK] Python installed
                )
            ) else (
                echo [OK] Python installed
            )
        ) else (
            choco install python -y
            if errorLevel 1 (
                echo [WARNING] Python installation failed
            ) else (
                echo [OK] Python installed
            )
        )
    ) else (
        echo [SKIP] No package manager - Python installation skipped
    )
)
echo.

:: Install Node.js (for some language servers)
echo [STEP 5] Installing Node.js...
where node >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] Node.js already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=OpenJS.NodeJS.LTS -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                winget install --id=OpenJS.NodeJS -e --accept-package-agreements --accept-source-agreements 2>nul
                if errorLevel 1 (
                    echo [WARNING] Node.js installation failed
                ) else (
                    echo [OK] Node.js installed
                )
            ) else (
                echo [OK] Node.js installed
            )
        ) else (
            choco install nodejs-lts -y
            if errorLevel 1 (
                echo [WARNING] Node.js installation failed
            ) else (
                echo [OK] Node.js installed
            )
        )
    ) else (
        echo [SKIP] No package manager - Node.js installation skipped
    )
)
echo.

:: Install ctags (for code navigation)
echo [STEP 6] Installing Universal Ctags...
where ctags >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] Ctags already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=UniversalCtags.Ctags -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [SKIP] Ctags installation failed ^(optional^)
            ) else (
                echo [OK] Ctags installed
            )
        ) else (
            choco install universal-ctags -y 2>nul
            if errorLevel 1 (
                echo [SKIP] Ctags installation failed ^(optional^)
            ) else (
                echo [OK] Ctags installed
            )
        )
    ) else (
        echo [SKIP] No package manager - Ctags installation skipped
    )
)
echo.

:: Install ripgrep (for better grep in CtrlP)
echo [STEP 7] Installing ripgrep...
where rg >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] ripgrep already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=BurntSushi.ripgrep.MSVC -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [SKIP] ripgrep installation failed ^(optional^)
            ) else (
                echo [OK] ripgrep installed
            )
        ) else (
            choco install ripgrep -y
            if errorLevel 1 (
                echo [SKIP] ripgrep installation failed ^(optional^)
            ) else (
                echo [OK] ripgrep installed
            )
        )
    ) else (
        echo [SKIP] No package manager - ripgrep installation skipped
    )
)
echo.

:: Refresh PATH
echo [STEP 8] Refreshing environment variables...
call :RefreshPath
echo [OK] PATH refreshed
echo.

:: Setup vim-plug (plugin manager)
echo [STEP 9] Setting up vim-plug...
set "VIM_AUTOLOAD=%USERPROFILE%\vimfiles\autoload"
set "VIM_PLUG=%VIM_AUTOLOAD%\plug.vim"

if not exist "%VIM_AUTOLOAD%" (
    mkdir "%VIM_AUTOLOAD%" 2>nul
)

if exist "!VIM_PLUG!" (
    echo [SKIP] vim-plug already installed
) else (
    echo Downloading vim-plug...
    set "PLUG_DOWNLOADED=0"

    :: Try curl first (built into Windows 10 1803+)
    where curl >nul 2>&1
    if not errorLevel 1 (
        curl -fLo "!VIM_PLUG!" --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim 2>nul
        if not errorLevel 1 set "PLUG_DOWNLOADED=1"
    )

    if "!PLUG_DOWNLOADED!"=="1" (
        echo [OK] vim-plug installed via curl
    ) else (
        echo [INFO] Trying PowerShell download...
        powershell -NoProfile -ExecutionPolicy Bypass -Command "& {[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -Uri 'https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim' -OutFile '!VIM_PLUG!' -UseBasicParsing}" 2>nul
        if not errorLevel 1 (
            echo [OK] vim-plug installed via PowerShell
        ) else (
            echo [ERROR] Failed to download vim-plug
            echo [INFO] Please download manually from:
            echo https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
            echo Save to: !VIM_PLUG!
        )
    )
)
echo.

:: Copy _vimrc configuration
echo [STEP 10] Copying Vim configuration...

:: Backup existing _vimrc files if they exist
set "TIMESTAMP=%date:~-4,4%%date:~-10,2%%date:~-7,2%_%time:~0,2%%time:~3,2%%time:~6,2%"
set "TIMESTAMP=%TIMESTAMP: =0%"

:: User home directory _vimrc
if exist "%USERPROFILE%\_vimrc" (
    echo [INFO] Backing up existing %USERPROFILE%\_vimrc
    move /y "%USERPROFILE%\_vimrc" "%USERPROFILE%\_vimrc.backup.%TIMESTAMP%" >nul 2>&1
)

:: Vim installation directory _vimrc (try common locations)
set "VIM_INSTALL_FOUND=0"
for %%d in ("C:\Program Files\Vim" "C:\Program Files (x86)\Vim" "%ProgramFiles%\Vim") do (
    if exist "%%~d\_vimrc" (
        set "VIM_INSTALL_FOUND=1"
        echo [INFO] Backing up existing %%~d\_vimrc
        if "%IS_ADMIN%"=="1" (
            move /y "%%~d\_vimrc" "%%~d\_vimrc.backup.%TIMESTAMP%" >nul 2>&1
        )
    )
)

:: Copy to user home directory (primary location)
echo Copying _vimrc to %USERPROFILE%\_vimrc
copy /y "%VIMRC_SOURCE%" "%USERPROFILE%\_vimrc" >nul 2>&1
if errorLevel 1 (
    echo [ERROR] Failed to copy _vimrc to user home directory
    if "%AUTO_MODE%"=="0" pause
    exit /b 1
) else (
    echo [OK] _vimrc copied to user home directory
)

:: Try to copy to Vim installation directory (optional, requires admin)
if "%IS_ADMIN%"=="1" (
    for %%d in ("C:\Program Files\Vim" "C:\Program Files (x86)\Vim" "%ProgramFiles%\Vim") do (
        if exist "%%~d" (
            copy /y "%VIMRC_SOURCE%" "%%~d\_vimrc" >nul 2>&1
            if not errorLevel 1 (
                echo [OK] _vimrc copied to %%~d
            )
        )
    )
) else (
    echo [INFO] Skipping system-wide install ^(requires admin^)
)
echo.

:: Create necessary directories
echo [STEP 11] Creating Vim directories...
if not exist "%USERPROFILE%\.vim\undodir" (
    mkdir "%USERPROFILE%\.vim\undodir" 2>nul
)
if not exist "%USERPROFILE%\vimfiles\plugged" (
    mkdir "%USERPROFILE%\vimfiles\plugged" 2>nul
)
echo [OK] Vim directories created
echo.

:: Install plugins
echo [STEP 12] Installing Vim plugins...
echo This may take a few minutes...
echo.

if exist "%VIM_PLUG%" (
    :: Check if vim is available
    where vim >nul 2>&1
    if errorLevel 1 (
        echo [SKIP] Vim not found, skipping plugin installation
        echo [INFO] Run :PlugInstall manually after installing Vim
    ) else (
        :: Run vim non-interactively to install plugins
        echo [INFO] Running Vim plugin installation, please wait...
        vim --not-a-term -N -u "%USERPROFILE%\_vimrc" --cmd "set nomore" -c "silent! PlugInstall --sync" -c "qall!"

        if errorLevel 1 (
            echo [WARNING] Plugin installation may have encountered issues
            echo [INFO] You can manually run :PlugInstall in Vim
        ) else (
            echo [OK] Plugins installed successfully
        )
    )
) else (
    echo [SKIP] vim-plug not installed, skipping plugin installation
)
echo.

:: Install language-specific tools (optional)
echo [STEP 13] Installing language-specific tools...
echo.

:: Refresh PATH again to pick up newly installed tools
call :RefreshPath

:: Python tools
where python >nul 2>&1
if errorLevel 1 (
    echo [SKIP] Python not found
) else (
    echo Installing Python tools...
    python -m pip install --upgrade pip --quiet --disable-pip-version-check 2>nul
    python -m pip install flake8 pylint black autopep8 --quiet --disable-pip-version-check 2>nul
    if errorLevel 1 (
        echo [SKIP] Python tools installation failed
    ) else (
        echo [OK] Python tools installed
    )
)

:: Node.js tools
where npm >nul 2>&1
if errorLevel 1 (
    echo [SKIP] npm not found
) else (
    echo Installing Node.js tools...
    call npm install -g eslint typescript ts-node prettier --loglevel=error 2>nul
    if errorLevel 1 (
        echo [SKIP] Node.js tools installation failed
    ) else (
        echo [OK] Node.js tools installed
    )
)
echo.

:: Verify installation
echo [STEP 14] Verifying installation...
echo.

:: Check if vim can be found
where vim >nul 2>&1
if %errorLevel% equ 0 (
    echo [OK] Vim is in PATH
    vim --version 2>nul | findstr /C:"VIM -" | findstr /C:"version" 2>nul
    if errorLevel 1 (
        echo [INFO] Vim version information unavailable
    )
) else (
    echo [WARNING] Vim not found in PATH
    echo [INFO] You may need to restart your terminal or install Vim manually
)

:: Check if _vimrc exists
if exist "%USERPROFILE%\_vimrc" (
    echo [OK] _vimrc configuration found at %USERPROFILE%\_vimrc
) else (
    echo [ERROR] _vimrc not found^!
)

:: Check if vim-plug exists
if exist "%VIM_PLUG%" (
    echo [OK] vim-plug installed at %VIM_PLUG%
) else (
    echo [WARNING] vim-plug not found
)
echo.

:: Final instructions
echo ========================================
echo Setup Complete^!
echo ========================================
echo.
echo Configuration locations:
echo   Primary:  %USERPROFILE%\_vimrc
echo   Plugins:  %USERPROFILE%\vimfiles\plugged
echo   Source:   %VIMRC_SOURCE%
echo.
echo ========================================
echo Next Steps
echo ========================================
if not exist "%VIM_PLUG%" (
    echo 1. Download vim-plug manually if automatic download failed
    echo    URL: https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
    echo    Save to: %VIM_PLUG%
    echo.
)
where vim >nul 2>&1
if errorLevel 1 (
    echo 1. Install Vim from https://www.vim.org/download.php
    echo.
)
echo 1. Close and reopen your terminal
echo 2. Run 'vim' to start Vim
echo 3. Inside Vim, run :PlugInstall if plugins weren't auto-installed
echo.
echo For language support, ensure compilers/interpreters are installed:
echo   - C/C++: GCC/MinGW, MSVC, or Clang
echo   - Python: python.org
echo   - Java: OpenJDK or Oracle JDK
echo   - Node.js: nodejs.org
echo.
echo To update configuration later:
echo   1. Edit: %VIMRC_SOURCE%
echo   2. Run: %~f0
echo   3. Restart Vim
echo.
if "%AUTO_MODE%"=="0" pause
exit /b 0

:: Function to refresh PATH without restarting
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
