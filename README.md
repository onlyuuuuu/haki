# Haki Development Environment

Complete development environment setup for competitive programming and multi-language development on Windows/Linux.

## Table of Contents

- [Overview](#overview)
- [Quick Start](#quick-start)
- [Editor Setup](#editor-setup)
  - [NeoVim Setup](#neovim-setup)
  - [Vim Setup](#vim-setup)
- [Competitive Programming](#competitive-programming)
- [Supported Languages](#supported-languages)
- [Project Structure](#project-structure)
- [Scripts](#scripts)

## Overview

This repository contains development configurations and scripts for:
- **NeoVim** with LSP, auto-completion, and competitive programming tools
- **Vim** with syntax highlighting and IDE-like features for multiple languages
- **Competitive Programming** tools (similar to VSCode CPH / CLion AutoCP)
- **Multi-language support**: Java, C/C++, Python, Rust, Go, JavaScript/TypeScript, Bash, and more

## Quick Start

### Windows Setup

```batch
# Setup NeoVim with CP tools
cd C:\dev\haki\scripts\workflow
setupWindowsNeovim.bat

# Setup Vim
setupWindowsVim.bat
```

### Linux/macOS Setup

```bash
# Coming soon
```

## Editor Setup

### NeoVim Setup

NeoVim is configured with full IDE features including LSP, auto-completion, file tree, fuzzy finding, and competitive programming tools.

#### Installation (Windows)

```batch
cd scripts\workflow
setupWindowsNeovim.bat
```

This will:
- ✅ Install NeoVim via winget/chocolatey
- ✅ Install required dependencies (Git, Node.js, ripgrep, fd, GCC)
- ✅ Install Nerd Fonts for icons
- ✅ Link/copy configuration from `scripts/workflow/.config/nvim`
- ✅ Setup competitive programming plugins

#### Configuration Location

- **Source**: `scripts/workflow/.config/nvim/`
- **Target (Windows)**: `%LOCALAPPDATA%\nvim`
- **Target (Linux/macOS)**: `~/.config/nvim`

#### Key Features

- **LazyVim**: Plugin manager with lazy loading
- **Mason**: LSP server installer
- **Telescope**: Fuzzy finder (Ctrl+P, Ctrl+F)
- **nvim-tree**: File explorer (Leader+t)
- **Auto-completion**: With nvim-cmp
- **LSP Support**: Java, C/C++, Python, Rust, Go, JavaScript/TypeScript, HTML/CSS, Bash
- **Catppuccin**: Beautiful color scheme
- **Auto-save**: Automatic file saving

#### Essential Keybindings

| Key | Action |
|-----|--------|
| `Space` | Leader key |
| `Ctrl+P` | Find files |
| `Ctrl+F` | Live grep/search |
| `Ctrl+W` / `Ctrl+S` | Save file |
| `Leader+t` | Toggle file tree |
| `Ctrl+L` | Open Lazy plugin manager |

### Vim Setup

Vim is configured for efficient development with syntax highlighting, auto-completion, and IDE-like features without heavy plugins.

#### Installation (Windows)

```batch
cd scripts\workflow
setupWindowsVim.bat
```

This will:
- ✅ Install Vim via winget/chocolatey
- ✅ Install vim-plug plugin manager
- ✅ Copy `_vimrc` configuration
- ✅ Install essential plugins
- ✅ Setup language-specific configurations

#### Configuration Location

- **Source**: `scripts/workflow/_vimrc`
- **Target (Windows)**: `C:\Program Files\Vim\_vimrc` and `~/_vimrc`
- **Target (Linux/macOS)**: `~/.vimrc`

#### Key Features

- **vim-plug**: Lightweight plugin manager
- **NERDTree**: File explorer
- **vim-airline**: Status bar
- **Auto-pairs**: Bracket auto-closing
- **Syntax Highlighting**: For all major languages
- **Ctags Support**: Jump to definitions
- **ALE**: Async linting and fixing
- **YouCompleteMe**: Code completion (optional)

#### Essential Keybindings

| Key | Action |
|-----|--------|
| `Ctrl+N` | Toggle NERDTree |
| `Ctrl+P` | Fuzzy file finder |
| `F5` | Run current file |
| `F8` | Toggle Tagbar |
| `,cc` | Comment line |
| `,cu` | Uncomment line |

#### Updating Configuration

After modifying `scripts/workflow/_vimrc`:

```batch
# Windows
cd scripts\workflow
setupWindowsVim.bat

# Or manually
copy _vimrc "%USERPROFILE%\_vimrc"
```

## Competitive Programming

NeoVim includes powerful competitive programming tools similar to **VSCode CPH** and **CLion AutoCP**.

### Features

- **One-click test running**: Press `F5` to compile and test
- **Test case management**: Add, edit, delete test cases with keybindings
- **Browser integration**: Parse problems from Codeforces, AtCoder, CodeChef, etc.
- **Multi-language support**: C++, C, Java, Python, Rust
- **Auto-templates**: Pre-configured templates with fast I/O
- **Visual test results**: See input, output, expected output side-by-side

### Quick Start Example

```bash
# 1. Create a solution file
nvim A.cpp

# 2. Add test case (press F6)
# Input: 3 4
# Output: 7

# 3. Write solution
#include <iostream>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
    return 0;
}

# 4. Run tests (press F5)
# ✅ Test 1: PASSED (0.02s)
```

### Keybindings

| Key | Action |
|-----|--------|
| `F5` | Run all test cases |
| `F6` | Add new test case |
| `Space+cr` | Run test cases |
| `Space+ca` | Add test case |
| `Space+ce` | Edit test case |
| `Space+cd` | Delete test case |
| `Space+cc` | Receive from browser |

### Browser Extension Setup

1. Install **Competitive Companion**:
   - [Chrome/Edge](https://chrome.google.com/webstore/detail/competitive-companion/cjnmckjndlpiamhfimnnjmnckgghkjbl)
   - [Firefox](https://addons.mozilla.org/en-US/firefox/addon/competitive-companion/)

2. Configure extension: Set port to `27121`

3. Usage:
   - Open problem on Codeforces/AtCoder/etc.
   - Start NeoVim (must be running)
   - Click extension icon
   - Problem opens automatically with test cases!

### Supported Platforms

- Codeforces
- AtCoder
- CodeChef
- TopCoder
- HackerRank
- LeetCode
- CSES
- Kattis
- And more...

### Templates

Default templates in `~/cp_templates/`:

**C++ Template** (`template.cpp`):
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define all(x) (x).begin(), (x).end()

void solve() {
    // Your code here
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}
```

**Python Template** (`template.py`):
```python
#!/usr/bin/env python3
import sys
from collections import defaultdict, Counter, deque
from math import gcd, ceil, floor, sqrt

def solve():
    """Your solution here"""
    pass

def main():
    t = 1
    # t = int(input())  # Uncomment for multiple test cases

    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
```

### Test Case Format

Test cases are stored in `.testcases` files:

```
[TESTCASE:1]
[INPUT]
3 4
[OUTPUT]
7

[TESTCASE:2]
[INPUT]
10 20
[OUTPUT]
30
```

### Documentation

- **Full Guide**: `scripts/workflow/.config/nvim/CP_README.md`
- **Quick Reference**: `scripts/workflow/.config/nvim/CP_QUICK_REFERENCE.md`
- **Example Config**: `scripts/workflow/.config/nvim/.competitest.lua.example`

## Supported Languages

### Programming Languages

| Language | NeoVim LSP | Vim Syntax | Compiler/Runtime |
|----------|-----------|------------|------------------|
| **Java** | ✅ jdtls | ✅ | JDK 11+ |
| **C/C++** | ✅ clangd | ✅ | GCC/Clang |
| **Python** | ✅ pyright | ✅ | Python 3.x |
| **Rust** | ✅ rust-analyzer | ✅ | rustc, cargo |
| **Go** | ✅ gopls | ✅ | go |
| **JavaScript/TypeScript** | ✅ tsserver | ✅ | Node.js |
| **HTML/CSS** | ✅ html, cssls | ✅ | - |
| **Bash** | ✅ bashls | ✅ | bash |
| **Batch** | ⚠️ | ✅ | cmd |

✅ = Fully supported | ⚠️ = Basic support

### Language-Specific Features

#### Java
- Full LSP with jdtls
- Auto-completion, go-to-definition
- Refactoring support
- Maven/Gradle project support

#### C/C++
- clangd LSP server
- Competitive programming optimized
- Fast compilation with GCC/Clang
- Debugger integration ready

#### Python
- pyright LSP for type checking
- Auto-formatting with black
- Linting with flake8/pylint
- Virtual environment support

#### Rust
- rust-analyzer for full IDE features
- Cargo integration
- Inline error messages
- Auto-formatting with rustfmt

#### JavaScript/TypeScript
- tsserver for IntelliSense
- ESLint integration
- Prettier formatting
- JSX/TSX support

## Project Structure

```
haki/
├── README.md                          # This file
├── scripts/
│   └── workflow/
│       ├── setupWindowsNeovim.bat    # NeoVim setup script
│       ├── setupWindowsVim.bat       # Vim setup script
│       ├── _vimrc                     # Vim configuration
│       └── .config/
│           ├── nvim/                  # NeoVim configuration
│           │   ├── init.lua          # Main config
│           │   ├── lua/
│           │   │   ├── config/       # Lazy.nvim config
│           │   │   ├── plugins/      # Plugin configurations
│           │   │   └── onlyu/        # Custom configs
│           │   ├── CP_README.md      # CP full documentation
│           │   └── CP_QUICK_REFERENCE.md
│           ├── bat/                   # Bat (cat alternative) config
│           ├── tmux-powerline/        # Tmux config
│           └── starship.toml          # Starship prompt config
├── src/
│   └── main/
│       ├── ccpp/                      # C/C++ projects
│       └── web/                       # Web projects
└── docker/                            # Docker configurations
```

## Scripts

### Windows Scripts

#### `setupWindowsNeovim.bat`

Automated NeoVim installation and configuration.

**Features**:
- Installs NeoVim, Git, Node.js, ripgrep, fd, GCC
- Creates symbolic link to config (or copies if no admin)
- Installs Nerd Fonts
- Sets up competitive programming tools

**Usage**:
```batch
cd scripts\workflow
setupWindowsNeovim.bat
```

#### `setupWindowsVim.bat`

Automated Vim installation and configuration.

**Features**:
- Installs Vim via winget/chocolatey
- Installs vim-plug plugin manager
- Copies _vimrc configuration
- Installs plugins automatically
- Supports re-running to update config

**Usage**:
```batch
cd scripts\workflow
setupWindowsVim.bat
```

### Configuration Update Workflow

When you modify configurations in the repo:

```batch
# For NeoVim (if using symlink, changes are automatic)
# If copied, re-run:
cd scripts\workflow
setupWindowsNeovim.bat

# For Vim (always need to re-run)
cd scripts\workflow
setupWindowsVim.bat
```

## Development Workflow

### Typical Day with NeoVim

```bash
# Start NeoVim in project
cd C:\dev\haki\src\main\ccpp
nvim main.cpp

# Use Telescope to find files (Ctrl+P)
# Edit multiple files
# Auto-completion with Tab
# Save with Ctrl+S
# Run tests with F5 (for CP)
```

### Typical Day with Vim

```bash
# Start Vim
vim main.cpp

# Open file tree (Ctrl+N)
# Find files (Ctrl+P)
# Run file (F5)
# Save and quit (:wq)
```

## Tips and Tricks

### NeoVim

1. **First time setup**: Plugins install automatically on first launch
2. **Check health**: Run `:checkhealth` to diagnose issues
3. **Update plugins**: Press `Ctrl+L` then `U` to update
4. **LSP info**: Use `:LspInfo` to check language server status
5. **Lazy loading**: Plugins load only when needed for fast startup

### Vim

1. **Install plugins**: Run `:PlugInstall` after adding new plugins
2. **Update plugins**: Run `:PlugUpdate`
3. **Clean plugins**: Run `:PlugClean`
4. **Quick reload**: `:source $MYVIMRC` after config changes

### Competitive Programming

1. **Templates**: Customize `~/cp_templates/` for your style
2. **Shortcuts**: Use F5/F6 for quick testing
3. **Browser sync**: Keep NeoVim running when parsing problems
4. **Test offline**: Add test cases manually with `<leader>ca`
5. **Debug mode**: Use `#define LOCAL` in templates for local testing

## Troubleshooting

### NeoVim Issues

**Plugins not loading**:
```vim
:Lazy sync
:checkhealth
```

**LSP not working**:
```vim
:Mason
:LspInfo
```

**Treesitter errors (Windows)**:
- Ensure GCC/MinGW is in PATH
- Restart terminal after installing compilers

### Vim Issues

**Plugins not working**:
```vim
:PlugInstall
:PlugUpdate
```

**Syntax highlighting broken**:
```vim
:syntax on
:filetype plugin indent on
```

### Competitive Programming Issues

**Compiler not found**:
- Windows: Add GCC to PATH (`C:\msys64\ucrt64\bin`)
- Check: `gcc --version`

**Browser extension not working**:
1. Verify NeoVim is running
2. Check port 27121 is not blocked
3. Restart NeoVim
4. Check extension settings

**Test cases not running**:
- Check compile command in config
- Verify source file is saved
- Check timeout settings

## Contributing

When adding new features:
1. Update relevant configuration files
2. Update this README
3. Test on clean installation
4. Document new keybindings

## Resources

### Documentation
- [NeoVim Docs](https://neovim.io/doc/)
- [Vim Docs](https://www.vim.org/docs.php)
- [LazyVim](https://www.lazyvim.org/)
- [CompetiTest](https://github.com/xeluxee/competitest.nvim)

### Learning
- [Vim Adventures](https://vim-adventures.com/) - Learn Vim through a game
- [Competitive Programming Algorithms](https://cp-algorithms.com/)
- [Codeforces](https://codeforces.com/)
- [AtCoder](https://atcoder.jp/)

### Communities
- [r/neovim](https://www.reddit.com/r/neovim/)
- [r/vim](https://www.reddit.com/r/vim/)
- [Codeforces Community](https://codeforces.com/blog/entry/)

## License

This configuration is provided as-is for personal and educational use.

## Acknowledgments

- NeoVim community for excellent plugins
- CompetiTest.nvim for CP tools
- LazyVim for plugin management
- All open-source contributors

---

**Happy Coding!** 🚀

For issues or questions, check the documentation files in `scripts/workflow/.config/nvim/` or create an issue in the repository.
