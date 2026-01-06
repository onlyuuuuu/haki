#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>

// Build for Linux ARM64:
// aarch64-linux-gnu-g++ -O2 unsafe-chrome-linux-arm64.cpp -o chrome-linux-arm64
// Or native: g++ -O2 unsafe-chrome-linux-arm64.cpp -o chrome-linux-arm64
// For static linking: g++ -O2 -static unsafe-chrome-linux-arm64.cpp -o chrome-linux-arm64

// Chrome paths to try (in order of preference)
// Note: Chrome ARM64 support on Linux is limited, Chromium is more common
const char* chromePaths[] = {
    "/usr/bin/chromium-browser",
    "/usr/bin/chromium",
    "/snap/bin/chromium",
    "/usr/bin/google-chrome-stable",
    "/usr/bin/google-chrome",
    "/opt/google/chrome/google-chrome",
    nullptr
};

const char* findChrome() {
    for (int i = 0; chromePaths[i] != nullptr; i++) {
        if (access(chromePaths[i], X_OK) == 0) {
            return chromePaths[i];
        }
    }
    return nullptr;
}

int main(int argc, char* argv[]) {
    const char* chromePath = findChrome();
    if (chromePath == nullptr) {
        const char* msg = "Error: Chrome/Chromium not found. Searched paths:\n";
        write(STDERR_FILENO, msg, strlen(msg));
        for (int i = 0; chromePaths[i] != nullptr; i++) {
            write(STDERR_FILENO, "  ", 2);
            write(STDERR_FILENO, chromePaths[i], strlen(chromePaths[i]));
            write(STDERR_FILENO, "\n", 1);
        }
        return 1;
    }

    // Build argument list
    std::vector<const char*> args;
    args.push_back(chromePath);
    args.push_back("--disable-web-security");

    // Pass through all arguments (skip argv[0] which is this program)
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }
    args.push_back(nullptr);

    // Fork and exec
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        execv(chromePath, const_cast<char* const*>(args.data()));
        // If execv returns, it failed
        _exit(1);
    } else if (pid > 0) {
        // Parent process - exit immediately (don't wait)
        return 0;
    } else {
        // Fork failed
        return 1;
    }
}
