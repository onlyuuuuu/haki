#!/bin/bash
# Build script for unsafe-chrome wrapper (Windows x64 and ARM64)
# For use with MinGW/MSYS2 on Windows
# Creates chrome.exe that looks like Chrome but adds --disable-web-security

set -e
cd "$(dirname "$0")"

BUILD_X64=0
BUILD_ARM64=0

case "${1:-all}" in
    x64)
        BUILD_X64=1
        ;;
    arm64)
        BUILD_ARM64=1
        ;;
    all|"")
        BUILD_X64=1
        BUILD_ARM64=1
        ;;
    *)
        echo "Usage: ./build-windows.sh [x64|arm64|all]"
        echo "  x64   - Build for Windows x64 only"
        echo "  arm64 - Build for Windows ARM64 only"
        echo "  all   - Build for both architectures (default)"
        exit 1
        ;;
esac

# Extract Chrome icon if not present
if [ ! -f chrome.ico ]; then
    echo "=== Extracting Chrome icon ==="
    CHROME_PATH="/c/Program Files/Google/Chrome/Application/chrome.exe"
    if [ -f "$CHROME_PATH" ]; then
        # Use PowerShell to extract icon
        powershell.exe -Command "
            Add-Type -AssemblyName System.Drawing;
            \$chromePath = 'C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe';
            Add-Type -TypeDefinition 'using System; using System.Runtime.InteropServices; public class IconExtractor { [DllImport(\"shell32.dll\", CharSet = CharSet.Auto)] public static extern IntPtr ExtractIcon(IntPtr hInst, string lpszExeFileName, int nIconIndex); [DllImport(\"user32.dll\", SetLastError = true)] public static extern bool DestroyIcon(IntPtr hIcon); }';
            \$hIcon = [IconExtractor]::ExtractIcon([IntPtr]::Zero, \$chromePath, 0);
            if (\$hIcon -ne [IntPtr]::Zero) {
                \$icon = [System.Drawing.Icon]::FromHandle(\$hIcon);
                \$fs = [System.IO.File]::Create('chrome.ico');
                \$icon.Save(\$fs);
                \$fs.Close();
                [IconExtractor]::DestroyIcon(\$hIcon);
                Write-Host 'Icon extracted successfully';
            } else {
                Write-Host 'Failed to extract icon';
            }
        " 2>/dev/null || echo "Warning: Could not extract icon via PowerShell"
    else
        echo "Warning: Chrome not found at default path. Icon will not be embedded."
    fi
fi

if [ ! -f chrome.ico ]; then
    echo "WARNING: chrome.ico not found. Executables will work but won't have Chrome's icon."
fi

if [ $BUILD_X64 -eq 1 ]; then
    echo ""
    echo "=== Building Windows x64 ==="

    # Find compiler - prefer clang++, then g++
    COMPILER=""
    if command -v clang++ &> /dev/null; then
        COMPILER="clang++"
    elif command -v x86_64-w64-mingw32-g++ &> /dev/null; then
        COMPILER="x86_64-w64-mingw32-g++"
    elif command -v g++ &> /dev/null; then
        COMPILER="g++"
    else
        echo "ERROR: No x64 C++ compiler found"
        exit 1
    fi

    # Find windres
    WINDRES=""
    if command -v llvm-windres &> /dev/null; then
        WINDRES="llvm-windres"
    elif command -v x86_64-w64-mingw32-windres &> /dev/null; then
        WINDRES="x86_64-w64-mingw32-windres"
    elif command -v windres &> /dev/null; then
        WINDRES="windres"
    fi

    echo "Using compiler: $COMPILER"

    # Try to compile resources if possible
    RES_FILE=""
    if [ -f chrome.ico ] && [ -n "$WINDRES" ]; then
        echo "Using windres: $WINDRES"
        if $WINDRES unsafe-chrome-windows-x64.rc -o unsafe-chrome-windows-x64.res 2>/dev/null; then
            RES_FILE="unsafe-chrome-windows-x64.res"
        else
            echo "Note: windres failed, building without icon/version info"
        fi
    else
        echo "Note: Building without icon (windres not available or chrome.ico missing)"
    fi

    if [ -n "$RES_FILE" ]; then
        $COMPILER -O2 -mwindows unsafe-chrome-windows-x64.cpp "$RES_FILE" -o chrome-windows-x64.exe
    else
        $COMPILER -O2 -mwindows unsafe-chrome-windows-x64.cpp -o chrome-windows-x64.exe
    fi

    if [ -f chrome-windows-x64.exe ]; then
        echo "Built: chrome-windows-x64.exe"
    else
        echo "FAILED: chrome-windows-x64.exe"
    fi
fi

if [ $BUILD_ARM64 -eq 1 ]; then
    echo ""
    echo "=== Building Windows ARM64 ==="

    # Find ARM64 compiler - prefer clang with target, then dedicated cross-compiler
    COMPILER=""
    COMPILER_FLAGS=""
    if command -v clang++ &> /dev/null; then
        # Check if clang supports aarch64-w64-mingw32 target
        if clang++ -target aarch64-w64-mingw32 --print-target-triple 2>/dev/null | grep -q aarch64; then
            COMPILER="clang++"
            COMPILER_FLAGS="-target aarch64-w64-mingw32"
        fi
    fi
    if [ -z "$COMPILER" ] && command -v aarch64-w64-mingw32-g++ &> /dev/null; then
        COMPILER="aarch64-w64-mingw32-g++"
    fi

    if [ -n "$COMPILER" ]; then
        echo "Using compiler: $COMPILER $COMPILER_FLAGS"

        # Find windres for ARM64
        WINDRES=""
        if command -v llvm-windres &> /dev/null; then
            WINDRES="llvm-windres"
        elif command -v aarch64-w64-mingw32-windres &> /dev/null; then
            WINDRES="aarch64-w64-mingw32-windres"
        fi

        # Try to compile resources if possible
        RES_FILE=""
        if [ -f chrome.ico ] && [ -n "$WINDRES" ]; then
            echo "Using windres: $WINDRES"
            if $WINDRES unsafe-chrome-windows-arm64.rc -o unsafe-chrome-windows-arm64.res 2>/dev/null; then
                RES_FILE="unsafe-chrome-windows-arm64.res"
            else
                echo "Note: windres failed, building without icon/version info"
            fi
        else
            echo "Note: Building without icon (windres not available or chrome.ico missing)"
        fi

        if [ -n "$RES_FILE" ]; then
            $COMPILER $COMPILER_FLAGS -O2 -mwindows unsafe-chrome-windows-arm64.cpp "$RES_FILE" -o chrome-windows-arm64.exe 2>&1
        else
            $COMPILER $COMPILER_FLAGS -O2 -mwindows unsafe-chrome-windows-arm64.cpp -o chrome-windows-arm64.exe 2>&1
        fi

        if [ -f chrome-windows-arm64.exe ]; then
            echo "Built: chrome-windows-arm64.exe"
        else
            echo "FAILED: chrome-windows-arm64.exe"
            echo "Note: ARM64 cross-compilation requires proper toolchain setup"
            echo "For clang, you may need to install aarch64-w64-mingw32 sysroot"
        fi
    else
        echo "SKIPPED: ARM64 cross-compiler not found"
        echo "Install clang with ARM64 support or aarch64-w64-mingw32-g++"
    fi
fi

echo ""
echo "=== Build complete ==="
echo ""
echo "Output files are named chrome-windows-{arch}.exe"
echo "Rename to chrome.exe when deploying."
echo ""
echo "Usage: ./chrome-windows-x64.exe https://example.com --incognito"

# Cleanup intermediate files
rm -f *.res *.o 2>/dev/null || true
