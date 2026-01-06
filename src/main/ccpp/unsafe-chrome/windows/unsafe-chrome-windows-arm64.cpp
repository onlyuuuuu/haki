#include <windows.h>
#include <string>

// Build for Windows ARM64:
// cl /O2 /EHsc unsafe-chrome-windows-arm64.cpp unsafe-chrome-windows-arm64.res /link /SUBSYSTEM:WINDOWS /MACHINE:ARM64 /OUT:chrome.exe
// Or with MinGW: aarch64-w64-mingw32-g++ -O2 -mwindows unsafe-chrome-windows-arm64.cpp unsafe-chrome-windows-arm64.res -o chrome.exe

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Path to actual Chrome - ARM64 Windows typically uses the same path
    std::wstring chromePath = L"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe";

    // Build command line with --disable-web-security
    std::wstring cmdLine = L"\"" + chromePath + L"\" --disable-web-security";

    // Append any arguments passed to this exe
    LPWSTR originalCmdLine = GetCommandLineW();

    // Skip past the executable name in the command line
    LPWSTR args = originalCmdLine;
    if (args[0] == L'"') {
        // Executable path is quoted
        args++;
        while (*args && *args != L'"') args++;
        if (*args == L'"') args++;
    } else {
        // Executable path is not quoted
        while (*args && *args != L' ' && *args != L'\t') args++;
    }
    // Skip whitespace
    while (*args == L' ' || *args == L'\t') args++;

    // Append remaining arguments
    if (*args) {
        cmdLine += L" ";
        cmdLine += args;
    }

    // Launch Chrome
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    if (CreateProcessW(
        chromePath.c_str(),
        &cmdLine[0],
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }

    return 0;
}
