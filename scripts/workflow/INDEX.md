# Editor Configuration Index

## Quick Links

| Document | Description |
|----------|-------------|
| **[Main README](../../README.md)** | Complete project overview |
| **[Vim Quick Reference](VIM_QUICK_REFERENCE.md)** | Vim keybindings and commands |
| **[CP README](.config/nvim/CP_README.md)** | Competitive programming full guide |
| **[CP Quick Reference](.config/nvim/CP_QUICK_REFERENCE.md)** | CP cheat sheet |
| **[Editor Comparison](EDITOR_COMPARISON.md)** | Vim vs NeoVim comparison |
| **[Update Guide](UPDATE_GUIDE.md)** | How to update configurations |

## Setup Scripts

| Script | Purpose | Run When |
|--------|---------|----------|
| **setupWindowsNeovim.bat** | Install/update NeoVim | First time + updates |
| **setupWindowsVim.bat** | Install/update Vim | First time + updates |

## Configuration Files

### Vim

| File | Purpose |
|------|---------|
| `_vimrc` | Main Vim configuration |

**Location after setup**:
- Primary: `%USERPROFILE%\_vimrc`
- Secondary: `C:\Program Files\Vim\_vimrc`

### NeoVim

| File/Directory | Purpose |
|----------------|---------|
| `.config/nvim/init.lua` | Main NeoVim config |
| `.config/nvim/lua/config/` | Lazy.nvim configuration |
| `.config/nvim/lua/plugins/` | Plugin specifications |
| `.config/nvim/lua/onlyu/` | Custom configurations |

**Location after setup**:
- Target: `%LOCALAPPDATA%\nvim`
- Source: `scripts/workflow/.config/nvim` (symlinked or copied)

## Plugin Configurations

### Vim Plugins (_vimrc includes)

- **NERDTree** - File explorer
- **CtrlP** - Fuzzy finder
- **vim-airline** - Status line
- **vim-fugitive** - Git integration
- **vim-gitgutter** - Git diff markers
- **auto-pairs** - Auto-close brackets
- **vim-commentary** - Easy commenting
- **vim-surround** - Surround text objects
- **ALE** - Async linting and fixing
- **vim-mucomplete** - Auto-completion
- **UltiSnips** - Snippet engine
- **Language plugins** - For C/C++, Python, Rust, Go, Java, JS/TS

### NeoVim Plugins (.config/nvim/lua/plugins/)

Core:
- **lazy.nvim** - Plugin manager
- **nvim-tree** - File explorer
- **telescope.nvim** - Fuzzy finder
- **lualine** - Status line
- **nvim-cmp** - Auto-completion
- **mason.nvim** - LSP installer
- **nvim-lspconfig** - LSP configuration
- **nvim-treesitter** - Better syntax highlighting

Competitive Programming:
- **competitest.nvim** - Test case management
- **cphelper.nvim** - Problem parser

Utilities:
- **auto-save.nvim** - Auto-save files
- **autoclose.nvim** - Auto-close pairs
- **which-key.nvim** - Keybinding hints
- **catppuccin** - Color scheme

## Language Support

Both editors support:

| Language | LSP/Linting | Compile & Run | Templates |
|----------|-------------|---------------|-----------|
| **C/C++** | ✅ clangd/gcc | F5, F4 | ✅ CP template |
| **Java** | ✅ jdtls/javac | F5, F4 | ✅ CP template |
| **Python** | ✅ pyright/flake8 | F5 | ✅ CP template |
| **Rust** | ✅ rust-analyzer | F5, F4 | ✅ |
| **Go** | ✅ gopls | F5, F4 | ✅ |
| **JavaScript** | ✅ tsserver/eslint | F5 | ✅ |
| **TypeScript** | ✅ tsserver/eslint | F5 | ✅ |
| **HTML/CSS** | ✅ | - | ✅ Emmet |
| **Bash** | ✅ bashls | F5 | ✅ |
| **Batch** | ⚠️ Syntax only | F5 | ⚠️ |

## Keybinding Summary

### Common (Both Editors)

| Key | Vim | NeoVim |
|-----|-----|--------|
| `Ctrl+S` | Save | Save |
| `F5` | Run file | Run tests (CP) or file |
| `Ctrl+P` | Find files | Find files |

### Vim-Specific

| Key | Action |
|-----|--------|
| `Ctrl+N` | Toggle NERDTree |
| `F4` | Compile only |
| `F8` | Toggle Tagbar |
| `Space` (Leader) | Custom commands |

### NeoVim-Specific

| Key | Action |
|-----|--------|
| `Space+t` | Toggle file tree |
| `Ctrl+F` | Live grep |
| `F6` | Add test case (CP) |
| `Space+cr` | Run tests (CP) |
| `Space+ca` | Add test case (CP) |

## Directory Structure

```
scripts/workflow/
├── setupWindowsNeovim.bat      # NeoVim installer
├── setupWindowsVim.bat         # Vim installer
├── _vimrc                      # Vim config
├── INDEX.md                    # This file
├── VIM_QUICK_REFERENCE.md      # Vim cheat sheet
├── EDITOR_COMPARISON.md        # Vim vs NeoVim guide
├── UPDATE_GUIDE.md             # Update instructions
└── .config/
    └── nvim/                   # NeoVim configs
        ├── init.lua            # Main config
        ├── CP_README.md        # CP documentation
        ├── CP_QUICK_REFERENCE.md
        ├── .competitest.lua.example
        ├── ftplugin/
        │   └── java.lua        # Java-specific
        └── lua/
            ├── config/
            │   └── lazy.lua    # Plugin manager
            ├── lazyvim/
            │   └── init.lua
            ├── onlyu/          # Custom configs
            │   ├── init.lua
            │   ├── remap.lua   # Keybindings
            │   ├── tree.lua    # File tree
            │   ├── telescope.lua
            │   ├── cp.lua      # CP config
            │   └── ...
            └── plugins/        # Plugin specs
                ├── competitest.lua
                ├── autocp-config.lua
                ├── nvim-tree.lua
                ├── telescope.lua
                └── ...
```

## Templates

### Competitive Programming Templates

Located in `~/cp_templates/` (created automatically):

- `template.cpp` - C++ with STL, fast I/O
- `template.c` - C template
- `template.py` - Python with common imports
- `template.java` - Java with fast I/O

### Custom Templates

To create custom templates:

1. Edit files in `~/cp_templates/`
2. Or modify `.config/nvim/lua/onlyu/cp.lua`
3. Restart NeoVim

## Common Tasks

### First-Time Setup

```batch
# 1. Clone/navigate to repo
cd C:\dev\haki

# 2. Run setup scripts
cd scripts\workflow
setupWindowsVim.bat
setupWindowsNeovim.bat

# 3. Optional: Install browser extension
# Competitive Companion for CP features
```

### Update Configuration

```batch
# 1. Edit config files in repo
notepad scripts\workflow\_vimrc
# or
notepad scripts\workflow\.config\nvim\init.lua

# 2. Run setup script
setupWindowsVim.bat
# or
setupWindowsNeovim.bat

# 3. Restart editor
```

### Add New Plugin

**Vim**:
```vim
" 1. Edit _vimrc, add:
Plug 'author/plugin-name'

" 2. Run setup or manually:
:source $MYVIMRC
:PlugInstall
```

**NeoVim**:
```lua
-- 1. Create: lua/plugins/myplugin.lua
return {
  'author/plugin-name',
  config = function()
    require('plugin-name').setup()
  end,
}

-- 2. Restart NeoVim (auto-installs)
```

### Competitive Programming Workflow

```bash
# 1. Install browser extension (one-time)
# Competitive Companion

# 2. Start NeoVim
nvim

# 3. Open problem on Codeforces/AtCoder
# Click extension icon

# 4. Code in auto-opened NeoVim with test cases

# 5. Test with F5

# 6. Submit when all pass
```

## Troubleshooting

### Issue: Vim config not loading

```batch
# Check config location
vim
:echo $MYVIMRC

# Should show: C:\Users\YourName\_vimrc

# If not, re-run setup
setupWindowsVim.bat
```

### Issue: NeoVim plugins not installing

```vim
# In NeoVim
:Lazy sync
:checkhealth lazy

# Or re-run setup
setupWindowsNeovim.bat
```

### Issue: LSP not working

```vim
# In NeoVim
:Mason
:LspInfo

# Install missing servers in Mason
```

### Issue: Compiler not found

```batch
# Check PATH
where gcc
where python
where node

# If not found, close terminal and reopen
# Or re-run setup script
```

## Resources

### Documentation
- [Vim Documentation](https://www.vim.org/docs.php)
- [NeoVim Documentation](https://neovim.io/doc/)
- [vim-plug](https://github.com/junegunn/vim-plug)
- [Lazy.nvim](https://github.com/folke/lazy.nvim)
- [CompetiTest](https://github.com/xeluxee/competitest.nvim)

### Learning
- Run `vimtutor` for Vim basics
- [Vim Adventures](https://vim-adventures.com/)
- [NeoVim from Scratch](https://github.com/LunarVim/Neovim-from-scratch)

### Competitive Programming
- [Competitive Companion](https://github.com/jmerle/competitive-companion)
- [Codeforces](https://codeforces.com/)
- [AtCoder](https://atcoder.jp/)
- [CP Algorithms](https://cp-algorithms.com/)

## Version Information

- **Vim**: 8.2+ (9.0+ recommended)
- **NeoVim**: 0.9+ (0.10+ recommended)
- **vim-plug**: Latest stable
- **Lazy.nvim**: Latest stable

## Platform Support

| Platform | Vim | NeoVim | Notes |
|----------|-----|--------|-------|
| **Windows 10/11** | ✅ | ✅ | Full support |
| **Linux** | ✅ | ✅ | Scripts TODO |
| **macOS** | ✅ | ✅ | Scripts TODO |

## Contributing

When adding features:
1. Update configuration files
2. Update relevant documentation
3. Test on clean installation
4. Commit to Git

## License

Educational and personal use.

---

**Last Updated**: 2026-02-16
**Maintainer**: See repo owner
**Status**: Active Development

For questions, see the main [README](../../README.md) or specific documentation files listed above.
