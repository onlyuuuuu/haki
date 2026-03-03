@echo off
setlocal enabledelayedexpansion

:: Parse command line arguments
set "AUTO_MODE=0"
if /i "%1"=="-y" set "AUTO_MODE=1"
if /i "%1"=="--auto" set "AUTO_MODE=1"
if /i "%1"=="--silent" set "AUTO_MODE=1"

echo ========================================
echo NeoVim Windows Setup Script
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
    echo [INFO] Symlink creation may fail, will use file copy instead
)
echo.

:: Determine script directory (where this batch file is located)
set "SCRIPT_DIR=%~dp0"
set "CONFIG_SOURCE=%SCRIPT_DIR%.config\nvim"
set "NVIM_CONFIG_DIR=%LOCALAPPDATA%\nvim"

echo [INFO] Script directory: %SCRIPT_DIR%
echo [INFO] Config source: %CONFIG_SOURCE%
echo [INFO] Target config directory: %NVIM_CONFIG_DIR%
echo.

:: Check if config source exists
if not exist "%CONFIG_SOURCE%" (
    echo [ERROR] Config source directory not found: %CONFIG_SOURCE%
    echo Please ensure the nvim config exists in scripts/workflow/.config/nvim
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

:: Install NeoVim
echo [STEP 2] Installing NeoVim...
where nvim >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] NeoVim already installed
    nvim --version 2>nul | findstr /C:"NVIM v" 2>nul
    if errorLevel 1 (
        echo [INFO] NeoVim found in PATH
    )
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            echo Installing via winget...
            winget install --id=Neovim.Neovim -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [WARNING] Silent install failed, trying interactive mode...
                winget install --id=Neovim.Neovim -e --accept-package-agreements --accept-source-agreements
                if errorLevel 1 (
                    echo [WARNING] Automatic installation failed
                    echo [INFO] Please install NeoVim manually from https://neovim.io/
                ) else (
                    echo [OK] NeoVim installed successfully
                )
            ) else (
                echo [OK] NeoVim installed successfully
            )
        ) else (
            echo Installing via chocolatey...
            choco install neovim -y
            if errorLevel 1 (
                echo [WARNING] Automatic installation failed
                echo [INFO] Please install NeoVim manually from https://neovim.io/
            ) else (
                echo [OK] NeoVim installed successfully
            )
        )
    ) else (
        echo [SKIP] No package manager available
        echo [INFO] Please install NeoVim manually from https://neovim.io/
        echo [INFO] Configuration will still be copied
    )
)
echo.

:: Install Git (required for LazyVim plugin manager)
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

:: Install ripgrep (for telescope)
echo [STEP 4] Installing ripgrep...
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

:: Install fd (for file finding)
echo [STEP 5] Installing fd...
where fd >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] fd already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=sharkdp.fd -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [SKIP] fd installation failed ^(optional^)
            ) else (
                echo [OK] fd installed
            )
        ) else (
            choco install fd -y
            if errorLevel 1 (
                echo [SKIP] fd installation failed ^(optional^)
            ) else (
                echo [OK] fd installed
            )
        )
    ) else (
        echo [SKIP] No package manager - fd installation skipped
    )
)
echo.

:: Install fzf (for fuzzy finding)
echo [STEP 6] Installing fzf...
where fzf >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] fzf already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            winget install --id=junegunn.fzf -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [SKIP] fzf installation failed ^(optional^)
            ) else (
                echo [OK] fzf installed
            )
        ) else (
            choco install fzf -y
            if errorLevel 1 (
                echo [SKIP] fzf installation failed ^(optional^)
            ) else (
                echo [OK] fzf installed
            )
        )
    ) else (
        echo [SKIP] No package manager - fzf installation skipped
    )
)
echo.

:: Install Node.js (for LSP servers)
echo [STEP 7] Installing Node.js...
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

:: Install GCC (for treesitter compilation)
echo [STEP 8] Installing GCC/C++ compiler...
where gcc >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] GCC already installed
) else (
    where cl >nul 2>&1
    if errorLevel 1 (
        if defined PKG_MGR (
            echo [INFO] Installing MinGW/GCC for treesitter compilation...
            if "!PKG_MGR!"=="winget" (
                winget install --id=MSYS2.MSYS2 -e --silent --accept-package-agreements --accept-source-agreements 2>nul
                if errorLevel 1 (
                    winget install --id=mingw -e --silent --accept-package-agreements --accept-source-agreements 2>nul
                    if errorLevel 1 (
                        echo [WARNING] Compiler installation failed
                        echo [INFO] Treesitter may not work without a C compiler
                    ) else (
                        echo [OK] Compiler installed
                    )
                ) else (
                    echo [OK] MSYS2 installed
                    echo [INFO] After MSYS2 installation, run: pacman -S mingw-w64-ucrt-x86_64-gcc
                )
            ) else (
                choco install mingw -y
                if errorLevel 1 (
                    echo [WARNING] Compiler installation failed
                    echo [INFO] Treesitter may not work without a C compiler
                ) else (
                    echo [OK] Compiler installed
                )
            )
        ) else (
            echo [SKIP] No package manager - Compiler installation skipped
            echo [WARNING] Treesitter requires a C compiler ^(GCC/Clang/MSVC^)
        )
    ) else (
        echo [INFO] MSVC compiler found, skipping GCC
    )
)
echo.

:: Install GNU Make
echo [STEP 9] Installing GNU Make...
where make >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] GNU Make already installed
) else (
    if defined PKG_MGR (
        if "!PKG_MGR!"=="winget" (
            echo Installing via winget...
            winget install --id=GnuWin32.Make -e --silent --accept-package-agreements --accept-source-agreements 2>nul
            if errorLevel 1 (
                echo [WARNING] GNU Make installation failed
                echo [INFO] Please install manually from https://gnuwin32.sourceforge.net/packages/make.htm
            ) else (
                echo [OK] GNU Make installed
            )
        ) else (
            choco install make -y
            if errorLevel 1 (
                echo [WARNING] GNU Make installation failed
            ) else (
                echo [OK] GNU Make installed
            )
        )
    ) else (
        echo [SKIP] No package manager - GNU Make installation skipped
    )
)
echo.

:: Install GNU sed
echo [STEP 10] Installing GNU sed...
where sed >nul 2>&1
if %errorLevel% equ 0 (
    echo [SKIP] GNU sed already installed
) else (
    set "SED_INSTALLED=0"
    :: Prefer scoop (most reliable GNU sed on Windows)
    where scoop >nul 2>&1
    if not errorLevel 1 (
        echo Installing via scoop...
        scoop install sed
        if not errorLevel 1 (
            set "SED_INSTALLED=1"
            echo [OK] GNU sed installed via scoop
        )
    )
    :: Try choco next
    if "!SED_INSTALLED!"=="0" (
        where choco >nul 2>&1
        if not errorLevel 1 (
            echo Installing via chocolatey...
            choco install sed -y
            if not errorLevel 1 (
                set "SED_INSTALLED=1"
                echo [OK] GNU sed installed via chocolatey
            )
        )
    )
    :: Winget GnuWin32 as last resort
    if "!SED_INSTALLED!"=="0" (
        if defined PKG_MGR (
            if "!PKG_MGR!"=="winget" (
                echo Installing via winget...
                winget install --id=GnuWin32.Sed -e --silent --accept-package-agreements --accept-source-agreements 2>nul
                if not errorLevel 1 (
                    set "SED_INSTALLED=1"
                    echo [OK] GNU sed installed via winget
                )
            )
        )
    )
    if "!SED_INSTALLED!"=="0" (
        echo [SKIP] GNU sed installation failed ^(optional^)
        echo [INFO] Install manually with: scoop install sed  OR  choco install sed
    )
)
echo.

:: Install a Nerd Font (optional but recommended for icons)
echo [STEP 11] Installing Nerd Font...
if defined PKG_MGR (
    if "!PKG_MGR!"=="winget" (
        echo [INFO] Installing CascadiaCode Nerd Font...
        winget install --id=Microsoft.CascadiaCode -e --silent --accept-package-agreements --accept-source-agreements 2>nul
        if errorLevel 1 (
            echo [SKIP] Font installation failed ^(optional^)
        ) else (
            echo [OK] CascadiaCode font installed
        )
    ) else (
        echo [SKIP] Font installation via chocolatey ^(install manually if needed^)
        echo [INFO] Download from: https://www.nerdfonts.com/
    )
) else (
    echo [SKIP] No package manager - Font installation skipped
)
echo.

:: Refresh PATH
echo [STEP 12] Refreshing environment variables...
call :RefreshPath
echo [OK] PATH refreshed
echo.

:: Setup NeoVim config
echo [STEP 13] Setting up NeoVim configuration...

:: Check if existing config is a symlink
set "IS_SYMLINK=0"
if exist "%NVIM_CONFIG_DIR%" (
    dir "%NVIM_CONFIG_DIR%" | findstr /C:"<SYMLINKD>" >nul 2>&1
    if not errorLevel 1 (
        set "IS_SYMLINK=1"
        echo [INFO] Existing config is a symlink
    )
    dir "%NVIM_CONFIG_DIR%" | findstr /C:"<JUNCTION>" >nul 2>&1
    if not errorLevel 1 (
        set "IS_SYMLINK=1"
        echo [INFO] Existing config is a junction
    )
)

:: Backup existing config if it exists and is not a symlink
if exist "%NVIM_CONFIG_DIR%" (
    if "!IS_SYMLINK!"=="0" (
        if "%AUTO_MODE%"=="1" (
            set "BACKUP=y"
        ) else (
            set /p "BACKUP=Existing NeoVim config found. Create backup? (y/n): "
        )
        if /i "!BACKUP!"=="y" (
            set "BACKUP_DIR=%NVIM_CONFIG_DIR%.backup.%date:~-4,4%%date:~-10,2%%date:~-7,2%_%time:~0,2%%time:~3,2%%time:~6,2%"
            set "BACKUP_DIR=!BACKUP_DIR: =0!"
            echo Creating backup at !BACKUP_DIR!
            move "%NVIM_CONFIG_DIR%" "!BACKUP_DIR!" >nul 2>&1
            if errorLevel 1 (
                echo [WARNING] Backup failed, removing existing config
                rmdir /s /q "%NVIM_CONFIG_DIR%" 2>nul
            )
        ) else (
            echo Removing existing config...
            rmdir /s /q "%NVIM_CONFIG_DIR%" 2>nul
        )
    ) else (
        echo [INFO] Existing symlink will be recreated
        rmdir "%NVIM_CONFIG_DIR%" >nul 2>&1
    )
)

:: Try to create symbolic link (requires admin) or copy as fallback
set "LINK_CREATED=0"
if "%IS_ADMIN%"=="1" (
    echo Creating symbolic link to config...
    mklink /D "%NVIM_CONFIG_DIR%" "%CONFIG_SOURCE%" >nul 2>&1
    if errorLevel 1 (
        echo [WARNING] Symbolic link creation failed despite admin rights
    ) else (
        set "LINK_CREATED=1"
        echo [OK] Symbolic link created successfully
        echo     Source: %CONFIG_SOURCE%
        echo     Target: %NVIM_CONFIG_DIR%
        echo [INFO] Config changes will sync automatically^!
    )
)

:: Fallback to copy if symlink failed
if !LINK_CREATED!==0 (
    echo [INFO] Creating junction point ^(alternative to symlink^)...
    mklink /J "%NVIM_CONFIG_DIR%" "%CONFIG_SOURCE%" >nul 2>&1
    if errorLevel 1 (
        echo [WARNING] Junction creation also failed
        echo [INFO] Copying config files instead...
        xcopy "%CONFIG_SOURCE%" "%NVIM_CONFIG_DIR%" /E /I /H /Y /Q >nul 2>&1
        if errorLevel 1 (
            echo [ERROR] Failed to copy config files
            if "%AUTO_MODE%"=="0" pause
            exit /b 1
        ) else (
            echo [OK] Config files copied successfully
            echo [NOTE] Changes to source config will not auto-sync
            echo [NOTE] Re-run this script to update: %~f0
        )
    ) else (
        echo [OK] Junction point created successfully
        echo [INFO] Config changes will sync automatically^!
    )
)
echo.

:: Create CP templates directory
echo [STEP 14] Creating competitive programming templates directory...
set "CP_TEMPLATES=%USERPROFILE%\cp_templates"
if not exist "%CP_TEMPLATES%" (
    mkdir "%CP_TEMPLATES%" 2>nul
    if errorLevel 1 (
        echo [WARNING] Failed to create templates directory
    ) else (
        echo [OK] Templates directory created at %CP_TEMPLATES%
    )
) else (
    echo [SKIP] Templates directory already exists
)
echo.

:: Final verification
echo [STEP 15] Verifying installation...
echo.

:: Check if nvim can be found
where nvim >nul 2>&1
if %errorLevel% equ 0 (
    echo [OK] NeoVim is in PATH
    nvim --version 2>nul | findstr /C:"NVIM v" 2>nul
    if errorLevel 1 (
        echo [INFO] NeoVim version information unavailable
    )
) else (
    echo [WARNING] NeoVim not found in PATH
    echo [INFO] You may need to restart your terminal or install NeoVim manually
)

:: Check if config exists
if exist "%NVIM_CONFIG_DIR%\init.lua" (
    echo [OK] NeoVim configuration found at %NVIM_CONFIG_DIR%
) else (
    echo [ERROR] NeoVim init.lua not found^!
)

:: Check if it's a symlink/junction
dir "%NVIM_CONFIG_DIR%" 2>nul | findstr /C:"<SYMLINKD> <JUNCTION>" >nul 2>&1
if errorLevel 1 (
    echo [INFO] Config is copied ^(re-run script to update^)
) else (
    echo [OK] Config is linked ^(changes will auto-sync^)
)
echo.

:: Final instructions
echo ========================================
echo Setup Complete^!
echo ========================================
echo.
echo Configuration locations:
echo   Source:  %CONFIG_SOURCE%
echo   Target:  %NVIM_CONFIG_DIR%
echo   Templates: %CP_TEMPLATES%
echo.
echo ========================================
echo Next Steps
echo ========================================
where nvim >nul 2>&1
if errorLevel 1 (
    echo 1. Install NeoVim from https://neovim.io/ if automatic install failed
    echo.
)
echo 1. Close and reopen your terminal to refresh PATH
echo 2. Run 'nvim' to start NeoVim
echo 3. LazyVim will automatically install plugins on first launch ^(be patient^!^)
echo 4. Mason will handle LSP server installations
echo.
echo ========================================
echo Competitive Programming
echo ========================================
echo Your NeoVim now has CP tools (like VSCode CPH / CLion AutoCP):
echo.
echo Quick Start:
echo   F5              - Run test cases
echo   F6              - Add test case
echo   Space+cr        - Run all tests
echo   Space+ca        - Add test case
echo.
echo Browser Extension (Optional):
echo   Install "Competitive Companion" to parse problems from Codeforces/AtCoder
echo   Chrome: https://chrome.google.com/webstore
echo   Firefox: https://addons.mozilla.org
echo   Port: 27121 (already configured)
echo.
echo Documentation:
echo   CP Guide: %CONFIG_SOURCE%\CP_README.md
echo   Quick Ref: %CONFIG_SOURCE%\CP_QUICK_REFERENCE.md
echo.
echo ========================================
echo Configuration Updates
echo ========================================
dir "%NVIM_CONFIG_DIR%" 2>nul | findstr /C:"<SYMLINKD> <JUNCTION>" >nul 2>&1
if errorLevel 1 (
    echo [INFO] Your config is copied
    echo To update after editing source:
    echo   1. Edit: %CONFIG_SOURCE%\init.lua
    echo   2. Run: %~f0
    echo   3. Restart NeoVim
) else (
    echo [INFO] Your config is linked^!
    echo Changes to %CONFIG_SOURCE% will apply immediately
    echo Just restart NeoVim to see updates
)
echo.
echo ========================================
echo Troubleshooting
echo ========================================
echo If you encounter issues:
echo   - Ensure all programs are in PATH (close/reopen terminal)
echo   - For treesitter errors, ensure gcc/mingw is in PATH
echo   - For plugin errors, run :checkhealth in NeoVim
echo   - For LSP issues, run :Mason and install missing servers
echo   - For CP features, see %CONFIG_SOURCE%\CP_README.md
echo.
echo Recommended: Set terminal font to "CascadiaCode NF" for proper icons
echo.
if "%AUTO_MODE%"=="0" pause
exit /b 0

:: Function to refresh PATH without restarting
:RefreshPath
for /f "skip=2 tokens=2*" %%a in ('reg query "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment" /v PATH 2^>nul') do set "SysPath=%%b"
for /f "skip=2 tokens=2*" %%a in ('reg query "HKCU\Environment" /v PATH 2^>nul') do set "UsrPath=%%b"
if defined SysPath if defined UsrPath (
    set "PATH=%SysPath%;%UsrPath%"
) else if defined SysPath (
    set "PATH=%SysPath%"
) else if defined UsrPath (
    set "PATH=%UsrPath%"
)
exit /b 0
