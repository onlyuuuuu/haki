@echo off
setlocal EnableDelayedExpansion

echo ============================================================
echo  Windows System Update
echo ============================================================
echo.

:: ── winget ──────────────────────────────────────────────────
where winget >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo [winget] Updating all packages...
    winget upgrade --all --include-unknown --silent --accept-source-agreements --accept-package-agreements
    echo [winget] Done.
) else (
    echo [winget] Not found, skipping.
)
echo.

:: ── Scoop ───────────────────────────────────────────────────
where scoop >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo [scoop] Updating scoop itself...
    scoop update
    echo [scoop] Updating all installed apps...
    scoop update *
    echo [scoop] Cleaning up old versions...
    scoop cleanup *
    echo [scoop] Done.
) else (
    echo [scoop] Not found, skipping.
)
echo.

:: ── Chocolatey ──────────────────────────────────────────────
where choco >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo [choco] Updating all packages...
    choco upgrade all -y
    echo [choco] Done.
) else (
    echo [choco] Not found, skipping.
)
echo.

:: ── npm (global packages) ───────────────────────────────────
where npm >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo [npm] Updating global packages...
    npm update -g
    echo [npm] Done.
) else (
    echo [npm] Not found, skipping.
)
echo.

:: ── pip (global packages) ───────────────────────────────────
where pip >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo [pip] Updating pip itself...
    python -m pip install --upgrade pip --quiet
    echo [pip] Updating outdated global packages...
    for /f "skip=2 tokens=1" %%p in ('pip list --outdated 2^>nul') do (
        pip install --upgrade %%p --quiet
    )
    echo [pip] Done.
) else (
    echo [pip] Not found, skipping.
)
echo.

:: ── cargo (Rust) ────────────────────────────────────────────
where cargo >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    where cargo-install-update >nul 2>&1
    if %ERRORLEVEL% EQU 0 (
        echo [cargo] Updating installed binaries via cargo-update...
        cargo install-update -a
        echo [cargo] Done.
    ) else (
        echo [cargo] cargo-update not installed. Run: cargo install cargo-update
        echo [cargo] Skipping binary updates.
    )
) else (
    echo [cargo] Not found, skipping.
)
echo.

:: ── rustup ──────────────────────────────────────────────────
where rustup >nul 2>&1
if %ERRORLEVEL% EQU 0 (
    echo [rustup] Updating Rust toolchains...
    rustup update
    echo [rustup] Done.
) else (
    echo [rustup] Not found, skipping.
)
echo.

echo ============================================================
echo  All updates complete.
echo ============================================================

endlocal
