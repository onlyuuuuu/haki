#!/bin/bash
# Build script for unsafe-chrome wrapper (Linux x64 and ARM64)
# Creates a chrome binary that launches Chrome with --disable-web-security

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
        echo "Usage: ./build-linux.sh [x64|arm64|all]"
        echo "  x64   - Build for Linux x64 only"
        echo "  arm64 - Build for Linux ARM64 only"
        echo "  all   - Build for both architectures (default)"
        exit 1
        ;;
esac

# Detect current architecture
ARCH=$(uname -m)

if [ $BUILD_X64 -eq 1 ]; then
    echo "=== Building Linux x64 ==="

    if [ "$ARCH" = "x86_64" ]; then
        # Native build
        g++ -O2 unsafe-chrome-linux-x64.cpp -o chrome-linux-x64
        echo "Built: chrome-linux-x64"
    else
        # Cross-compile
        if command -v x86_64-linux-gnu-g++ &> /dev/null; then
            x86_64-linux-gnu-g++ -O2 unsafe-chrome-linux-x64.cpp -o chrome-linux-x64
            echo "Built: chrome-linux-x64 (cross-compiled)"
        else
            echo "SKIPPED: x64 cross-compiler not found (x86_64-linux-gnu-g++)"
        fi
    fi
fi

if [ $BUILD_ARM64 -eq 1 ]; then
    echo ""
    echo "=== Building Linux ARM64 ==="

    if [ "$ARCH" = "aarch64" ]; then
        # Native build
        g++ -O2 unsafe-chrome-linux-arm64.cpp -o chrome-linux-arm64
        echo "Built: chrome-linux-arm64"
    else
        # Cross-compile
        if command -v aarch64-linux-gnu-g++ &> /dev/null; then
            aarch64-linux-gnu-g++ -O2 unsafe-chrome-linux-arm64.cpp -o chrome-linux-arm64
            echo "Built: chrome-linux-arm64 (cross-compiled)"
        else
            echo "SKIPPED: ARM64 cross-compiler not found (aarch64-linux-gnu-g++)"
            echo "Install with: sudo apt install g++-aarch64-linux-gnu"
        fi
    fi
fi

echo ""
echo "=== Build complete ==="
echo ""
echo "Output files are named chrome-linux-{arch}"
echo "Rename to 'google-chrome' or create symlink when deploying."
echo ""
echo "Usage: ./chrome-linux-x64 https://example.com --incognito"
echo ""
echo "To install as replacement (use with caution):"
echo "  sudo mv chrome-linux-x64 /usr/local/bin/chrome-unsafe"
echo "  /usr/local/bin/chrome-unsafe https://example.com"
