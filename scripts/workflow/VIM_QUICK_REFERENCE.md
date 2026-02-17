# Vim Quick Reference

## Quick Start

```bash
# Start Vim
vim filename.ext

# Or just
vim
```

## Essential Keybindings

### File Operations
```
Ctrl+N          → Toggle file explorer (NERDTree)
Ctrl+P          → Fuzzy file finder
Ctrl+S          → Save file
:w              → Save file
:q              → Quit
:wq             → Save and quit
:q!             → Quit without saving
```

### Language-Specific Quick Run

```
F5              → Compile & Run (or just Run for interpreted languages)
F4              → Compile only (for compiled languages)
F8              → Toggle code outline (Tagbar)
```

### Navigation

```
h/j/k/l         → Left/Down/Up/Right
w               → Next word
b               → Previous word
0               → Start of line
$               → End of line
gg              → Top of file
G               → Bottom of file
Ctrl+D          → Page down
Ctrl+U          → Page up
```

### Editing

```
i               → Insert mode (before cursor)
a               → Insert mode (after cursor)
o               → New line below
O               → New line above
Esc             → Normal mode
u               → Undo
Ctrl+R          → Redo
dd              → Delete line
yy              → Copy line
p               → Paste
Y               → Copy to end of line
```

### Visual Mode

```
v               → Visual mode (character)
V               → Visual mode (line)
Ctrl+V          → Visual block mode
y               → Yank (copy)
d               → Delete
```

### Search & Replace

```
/pattern        → Search forward
?pattern        → Search backward
n               → Next match
N               → Previous match
:%s/old/new/g   → Replace all in file
:noh            → Clear search highlight
Space /         → Clear search highlight
```

### Window Management

```
:vsplit         → Vertical split
:split          → Horizontal split
Ctrl+W h/j/k/l  → Navigate between windows
Ctrl+W q        → Close window
Space sv        → Vertical split
Space sh        → Horizontal split
```

### Buffer Management

```
:bnext          → Next buffer
:bprev          → Previous buffer
:bd             → Close buffer
Space bn        → Next buffer
Space bp        → Previous buffer
```

### Commenting

```
gcc             → Comment/uncomment line
gc              → Comment motion
```

## Plugin-Specific Commands

### NERDTree (File Explorer)

```
Ctrl+N          → Toggle NERDTree
m               → Menu (in NERDTree)
o               → Open file
s               → Open in vertical split
i               → Open in horizontal split
t               → Open in new tab
```

### CtrlP (Fuzzy Finder)

```
Ctrl+P          → Open CtrlP
Ctrl+J/K        → Navigate results
Enter           → Open file
Ctrl+V          → Open in vertical split
```

### ALE (Linting)

```
Space f         → Fix/format code
:ALEFix         → Fix linting errors
:ALEInfo        → Show linter info
```

### Git (Fugitive)

```
:Git status     → Git status
:Git commit     → Git commit
:Git push       → Git push
:Git diff       → Git diff
```

## Language-Specific Features

### C/C++

```vim
" File: example.cpp
F4              → Compile: g++ -std=c++20 -O2 -Wall example.cpp -o example
F5              → Compile & Run
```

### Java

```vim
" File: Main.java
F4              → Compile: javac Main.java
F5              → Compile & Run: javac Main.java && java Main
```

### Python

```vim
" File: script.py
F5              → Run: python script.py
```

### Rust

```vim
" File: main.rs (in Cargo project)
F4              → Build: cargo build
F5              → Run: cargo run
```

### Go

```vim
" File: main.go
F4              → Build: go build main.go
F5              → Run: go run main.go
```

### JavaScript/TypeScript

```vim
" File: app.js
F5              → Run: node app.js

" File: app.ts
F5              → Run: ts-node app.ts
```

### HTML (Emmet)

```vim
" Type: div.container>ul>li*3
" Press: Ctrl+Z then ,
" Result:
<div class="container">
  <ul>
    <li></li>
    <li></li>
    <li></li>
  </ul>
</div>
```

## Configuration

### Location

```
Primary:   %USERPROFILE%\_vimrc  (Windows)
           ~/.vimrc               (Linux/Mac)
Source:    scripts/workflow/_vimrc
```

### Update Config

```batch
# Windows
cd C:\dev\haki\scripts\workflow
setupWindowsVim.bat

# Or manually
copy _vimrc %USERPROFILE%\_vimrc
vim +PlugInstall +qall
```

### Reload Config

```vim
:source $MYVIMRC
```

## Plugin Management

### Inside Vim

```vim
:PlugInstall    → Install plugins
:PlugUpdate     → Update all plugins
:PlugClean      → Remove unused plugins
:PlugStatus     → Check plugin status
```

## Customization

### Leader Key

Leader key is `Space`. Use it for custom commands:

```
Space sv        → Vertical split
Space sh        → Horizontal split
Space bn        → Next buffer
Space bp        → Previous buffer
Space /         → Clear search highlight
Space f         → Format code
```

### Adding Custom Keybindings

Edit `_vimrc`:

```vim
" Example: Map F9 to run Python with input
autocmd FileType python nmap <F9> :!python % < input.txt<CR>
```

## Tips & Tricks

1. **Quick Save**: Use `Ctrl+S` in any mode
2. **Auto-pairs**: Brackets/quotes auto-close
3. **Multiple Cursors**: Select word, press `Ctrl+N` repeatedly
4. **Persistent Undo**: Undo history persists between sessions
5. **Auto-format**: `Space f` to format code with ALE
6. **System Clipboard**: `"+y` to copy to system clipboard
7. **Vertical Selection**: `Ctrl+V` for block selection
8. **Macros**: `q{letter}` to record, `@{letter}` to replay

## Common Tasks

### Open Multiple Files

```bash
vim file1.cpp file2.cpp file3.cpp
```

Navigate with `:bnext` and `:bprev`

### Search in Multiple Files

```vim
:vimgrep /pattern/ **/*.cpp
:copen
```

### Find and Replace in Multiple Files

```vim
:args **/*.cpp
:argdo %s/old/new/ge | update
```

### Split Screen Workflow

```vim
:vsplit file2.cpp    " Open file2.cpp in vertical split
Ctrl+W h             " Focus left window
Ctrl+W l             " Focus right window
```

## Troubleshooting

### Plugin Not Working

```vim
:PlugInstall
:PlugUpdate
" Restart Vim
```

### Syntax Highlighting Broken

```vim
:syntax on
:filetype plugin indent on
```

### Linter Errors

```vim
:ALEInfo            " Check what's wrong
:ALEFix             " Try to auto-fix
```

### Slow Startup

```vim
:PlugClean          " Remove unused plugins
" Comment out plugins you don't use in _vimrc
```

## Resources

- **Vim Help**: `:help` or `:help {topic}`
- **Vim Tutor**: Run `vimtutor` in terminal
- **Plugin Docs**: `:help {plugin-name}`

## Comparison with NeoVim

| Feature | Vim | NeoVim |
|---------|-----|--------|
| **Startup** | Faster | Slightly slower |
| **Plugins** | vim-plug | Lazy.nvim |
| **LSP** | Via plugins | Built-in |
| **Config** | VimScript | Lua + VimScript |
| **Use Case** | Quick edits | Full IDE |

**When to use Vim**: Quick edits, servers, lightweight setup
**When to use NeoVim**: Full development, competitive programming, modern features

---

**Installed Plugins**:
- NERDTree - File explorer
- CtrlP - Fuzzy finder
- vim-airline - Status bar
- vim-fugitive - Git integration
- vim-gitgutter - Git diff in gutter
- auto-pairs - Auto-close brackets
- vim-commentary - Easy commenting
- ALE - Linting and fixing
- vim-mucomplete - Auto-completion
- UltiSnips - Snippets
- Language-specific plugins for C/C++, Python, Rust, Go, Java, JS/TS

**Run `:PlugStatus` to see all installed plugins**
