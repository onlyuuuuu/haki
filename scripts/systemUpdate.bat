@echo off
setlocal

:: ============================================================
::  systemUpdate.bat — Upgrade all packages via choco + winget
:: ============================================================

net session >nul 2>&1
if %errorlevel% neq 0 (
    echo [ERROR] Please run this script as Administrator.
    pause
    exit /b 1
)

echo.
echo ============================================================
echo  System Update — %date% %time%
echo ============================================================
echo.

:: -- Chocolatey -----------------------------------------------
where choco >nul 2>&1
if %errorlevel% == 0 (
    echo [CHOCO] Upgrading all Chocolatey packages...
    echo --------------------------------------------
    choco upgrade all -y
    echo.
    echo [CHOCO] Done.
) else (
    echo [CHOCO] Chocolatey not found, skipping.
)

echo.

:: -- Winget ---------------------------------------------------
where winget >nul 2>&1
if %errorlevel% == 0 (
    echo [WINGET] Upgrading all winget packages...
    echo --------------------------------------------
    winget upgrade --all --silent --accept-package-agreements --accept-source-agreements
    echo.
    echo [WINGET] Done.
) else (
    echo [WINGET] winget not found, skipping.
)

echo.
echo ============================================================
echo  All updates complete — %date% %time%
echo ============================================================
echo.
pause
endlocal