@echo off
setlocal enabledelayedexpansion
REM Build script for unsafe-chrome wrapper (Windows x64 and ARM64)
REM Creates chrome.exe that looks like Chrome but adds --disable-web-security

cd /d "%~dp0"

echo === Extracting Chrome icon ===
if not exist chrome.ico (
    powershell -Command ^
        "Add-Type -AssemblyName System.Drawing; " ^
        "$chromePath = 'C:\Program Files\Google\Chrome\Application\chrome.exe'; " ^
        "Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class IconExtractor { [DllImport(\"shell32.dll\", CharSet = CharSet.Auto)] public static extern IntPtr ExtractIcon(IntPtr hInst, string lpszExeFileName, int nIconIndex); [DllImport(\"user32.dll\", SetLastError = true)] public static extern bool DestroyIcon(IntPtr hIcon); }'; " ^
        "$hIcon = [IconExtractor]::ExtractIcon([IntPtr]::Zero, $chromePath, 0); " ^
        "if ($hIcon -ne [IntPtr]::Zero) { " ^
        "  $icon = [System.Drawing.Icon]::FromHandle($hIcon); " ^
        "  $fs = [System.IO.File]::Create('chrome.ico'); " ^
        "  $icon.Save($fs); " ^
        "  $fs.Close(); " ^
        "  [IconExtractor]::DestroyIcon($hIcon); " ^
        "  Write-Host 'Icon extracted successfully'; " ^
        "} else { Write-Host 'Failed to extract icon'; }"
)

if not exist chrome.ico (
    echo WARNING: Could not extract icon. Executables will work but won't have Chrome's icon.
)

set BUILD_X64=0
set BUILD_ARM64=0

if "%1"=="" (
    set BUILD_X64=1
    set BUILD_ARM64=1
) else if /i "%1"=="x64" (
    set BUILD_X64=1
) else if /i "%1"=="arm64" (
    set BUILD_ARM64=1
) else if /i "%1"=="all" (
    set BUILD_X64=1
    set BUILD_ARM64=1
) else (
    echo Usage: build-windows.bat [x64^|arm64^|all]
    echo   x64   - Build for Windows x64 only
    echo   arm64 - Build for Windows ARM64 only
    echo   all   - Build for both architectures ^(default^)
    exit /b 1
)

REM Check for MSVC
where cl >nul 2>&1
if !ERRORLEVEL! == 0 (
    echo Using MSVC compiler...

    if "!BUILD_X64!"=="1" (
        echo.
        echo === Building Windows x64 ===
        rc unsafe-chrome-windows-x64.rc
        cl /O2 /EHsc unsafe-chrome-windows-x64.cpp unsafe-chrome-windows-x64.res /link /SUBSYSTEM:WINDOWS /MACHINE:X64 /OUT:unsafe-chrome-windows-x64.exe
        if exist unsafe-chrome-windows-x64.exe (
            echo Built: unsafe-chrome-windows-x64.exe
        ) else (
            echo FAILED: unsafe-chrome-windows-x64.exe
        )
    )

    if "!BUILD_ARM64!"=="1" (
        echo.
        echo === Building Windows ARM64 ===
        echo NOTE: ARM64 cross-compilation requires ARM64 build tools installed
        rc unsafe-chrome-windows-arm64.rc
        cl /O2 /EHsc unsafe-chrome-windows-arm64.cpp unsafe-chrome-windows-arm64.res /link /SUBSYSTEM:WINDOWS /MACHINE:ARM64 /OUT:unsafe-chrome-windows-arm64.exe
        if exist unsafe-chrome-windows-arm64.exe (
            echo Built: unsafe-chrome-windows-arm64.exe
        ) else (
            echo FAILED: unsafe-chrome-windows-arm64.exe - ARM64 tools may not be installed
        )
    )

    goto :done
)

REM Check for Clang
where clang++ >nul 2>&1
if !ERRORLEVEL! == 0 (
    echo Using Clang compiler...

    REM Find windres for resource compilation
    set "WINDRES="
    where llvm-windres >nul 2>&1
    if !ERRORLEVEL! == 0 (
        set "WINDRES=llvm-windres"
    ) else (
        where windres >nul 2>&1
        if !ERRORLEVEL! == 0 set "WINDRES=windres"
    )

    if "!BUILD_X64!"=="1" (
        echo.
        echo === Building Windows x64 ===
        set "RES_FILE="
        if exist chrome.ico if defined WINDRES (
            !WINDRES! unsafe-chrome-windows-x64.rc -O coff -o unsafe-chrome-windows-x64.o 2>nul
            if exist unsafe-chrome-windows-x64.o set "RES_FILE=unsafe-chrome-windows-x64.o"
        )
        if defined RES_FILE (
            clang++ -O2 -mwindows -static unsafe-chrome-windows-x64.cpp !RES_FILE! -o unsafe-chrome-windows-x64.exe
        ) else (
            clang++ -O2 -mwindows -static unsafe-chrome-windows-x64.cpp -o unsafe-chrome-windows-x64.exe
        )
        if exist unsafe-chrome-windows-x64.exe (
            echo Built: unsafe-chrome-windows-x64.exe
        ) else (
            echo FAILED: unsafe-chrome-windows-x64.exe
        )
    )

    if "!BUILD_ARM64!"=="1" (
        echo.
        echo === Building Windows ARM64 ===
        clang++ -target aarch64-w64-mingw32 -O2 -mwindows -static unsafe-chrome-windows-arm64.cpp -o unsafe-chrome-windows-arm64.exe 2>nul
        if exist unsafe-chrome-windows-arm64.exe (
            echo Built: unsafe-chrome-windows-arm64.exe
        ) else (
            echo SKIPPED: ARM64 requires proper toolchain setup
        )
    )

    goto :done
)

REM Check for MinGW g++
where g++ >nul 2>&1
if !ERRORLEVEL! == 0 (
    echo Using g++ compiler...

    REM Find windres for resource compilation
    set "WINDRES="
    where windres >nul 2>&1
    if !ERRORLEVEL! == 0 set "WINDRES=windres"

    if "!BUILD_X64!"=="1" (
        echo.
        echo === Building Windows x64 ===
        set "RES_FILE="
        if exist chrome.ico if defined WINDRES (
            !WINDRES! unsafe-chrome-windows-x64.rc -O coff -o unsafe-chrome-windows-x64.o 2>nul
            if exist unsafe-chrome-windows-x64.o set "RES_FILE=unsafe-chrome-windows-x64.o"
        )
        if defined RES_FILE (
            g++ -O2 -mwindows -static unsafe-chrome-windows-x64.cpp !RES_FILE! -o unsafe-chrome-windows-x64.exe
        ) else (
            g++ -O2 -mwindows -static unsafe-chrome-windows-x64.cpp -o unsafe-chrome-windows-x64.exe
        )
        if exist unsafe-chrome-windows-x64.exe (
            echo Built: unsafe-chrome-windows-x64.exe
        ) else (
            echo FAILED: unsafe-chrome-windows-x64.exe
        )
    )

    goto :done
)

REM Try common MinGW installation paths
set "MINGW_PATHS=C:\msys64\mingw64\bin;C:\mingw64\bin;C:\MinGW\bin"
for %%P in ("%MINGW_PATHS:;=" "%") do (
    if exist "%%~P\g++.exe" (
        echo Found MinGW at %%~P
        set "PATH=%%~P;!PATH!"
        goto :retry_mingw
    )
)

echo.
echo ERROR: No C++ compiler found.
echo.
echo Options:
echo   1. Run this from "Developer Command Prompt for VS" ^(for MSVC^)
echo   2. Run this from "MSYS2 MinGW 64-bit" shell ^(for MinGW^)
echo   3. Add MinGW to your Windows PATH
echo   4. Install Build Tools for Visual Studio from:
echo      https://visualstudio.microsoft.com/downloads/
echo.
exit /b 1

:retry_mingw
echo Using g++ compiler from MinGW...

REM Find windres for resource compilation
set "WINDRES="
where windres >nul 2>&1
if !ERRORLEVEL! == 0 set "WINDRES=windres"

if "!BUILD_X64!"=="1" (
    echo.
    echo === Building Windows x64 ===
    set "RES_FILE="
    if exist chrome.ico if defined WINDRES (
        !WINDRES! unsafe-chrome-windows-x64.rc -O coff -o unsafe-chrome-windows-x64.o 2>nul
        if exist unsafe-chrome-windows-x64.o set "RES_FILE=unsafe-chrome-windows-x64.o"
    )
    if defined RES_FILE (
        g++ -O2 -mwindows -static unsafe-chrome-windows-x64.cpp !RES_FILE! -o unsafe-chrome-windows-x64.exe
    ) else (
        g++ -O2 -mwindows -static unsafe-chrome-windows-x64.cpp -o unsafe-chrome-windows-x64.exe
    )
    if exist unsafe-chrome-windows-x64.exe (
        echo Built: unsafe-chrome-windows-x64.exe
    ) else (
        echo FAILED: unsafe-chrome-windows-x64.exe
    )
)

goto :done

:done
echo.
echo === Build complete ===
echo.
echo Output files are named unsafe-chrome-windows-{arch}.exe
echo Rename to chrome.exe when deploying.
echo.
echo Usage: unsafe-chrome-windows-x64.exe https://example.com --incognito

REM Cleanup intermediate files
del *.obj *.o *.res 2>nul
