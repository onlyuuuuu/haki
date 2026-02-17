# Configuration Update Guide

## Quick Update

When you modify editor configurations in this repository, run the appropriate setup script to update your system.

### Windows

```batch
# Update Vim config
cd C:\dev\haki\scripts\workflow
setupWindowsVim.bat

# Update NeoVim config
cd C:\dev\haki\scripts\workflow
setupWindowsNeovim.bat

# Update both
cd C:\dev\haki\scripts\workflow
setupWindowsVim.bat && setupWindowsNeovim.bat
```

## What Gets Updated

### Vim (`setupWindowsVim.bat`)

✅ **Automatically updated**:
- `~/_vimrc` - Main Vim configuration
- `C:\Program Files\Vim\_vimrc` - System-wide config (if admin)
- Vim plugins (via `:PlugInstall`)
- Plugin updates (via `:PlugUpdate`)

📝 **Source files**:
- `scripts/workflow/_vimrc`

### NeoVim (`setupWindowsNeovim.bat`)

✅ **Automatically updated**:
- `%LOCALAPPDATA%\nvim\*` - All NeoVim config
  - If using **symlink**: Updates are instant! (no need to re-run)
  - If using **copy**: Must re-run script to update
- Plugins (via Lazy.nvim auto-update)

📝 **Source files**:
- `scripts/workflow/.config/nvim/**/*`

## Update Workflows

### Method 1: Run Setup Scripts (Recommended)

This is the safest method that handles everything:

```batch
# 1. Edit config in repo
cd C:\dev\haki\scripts\workflow
notepad _vimrc
# or
notepad .config\nvim\init.lua

# 2. Run setup script
setupWindowsVim.bat
# or
setupWindowsNeovim.bat

# 3. Restart editor
# Done!
```

**Pros**:
- ✅ Handles backups automatically
- ✅ Installs any new dependencies
- ✅ Updates plugins
- ✅ Verifies installation

**Cons**:
- ⏱️ Takes 30-60 seconds

### Method 2: Manual Copy (Quick)

For quick config-only updates:

#### Vim

```batch
# Copy config
copy "C:\dev\haki\scripts\workflow\_vimrc" "%USERPROFILE%\_vimrc" /y

# Update plugins (in Vim)
vim +PlugInstall +PlugUpdate +qall

# Or inside Vim
:source $MYVIMRC
:PlugUpdate
```

#### NeoVim (if NOT using symlink)

```batch
# Copy entire config
xcopy "C:\dev\haki\scripts\workflow\.config\nvim" "%LOCALAPPDATA%\nvim" /E /I /H /Y

# Restart NeoVim (plugins auto-update)
nvim
```

**Pros**:
- ⚡ Very fast (< 5 seconds)

**Cons**:
- ❌ No automatic backups
- ❌ Won't install new dependencies
- ❌ Manual plugin updates needed

### Method 3: Symlink (Best for NeoVim)

If you used symlink during setup, NeoVim config updates automatically!

**Check if you're using symlink**:

```batch
# Windows (PowerShell)
Get-Item $env:LOCALAPPDATA\nvim | Select-Object LinkType, Target

# If LinkType = "SymbolicLink", you're using symlink!
```

**With symlink**:
```lua
-- 1. Edit config in repo
-- 2. Restart NeoVim
-- 3. Done! (No copy needed)
```

**To create symlink** (if not already):

```batch
# Run as Administrator
cd C:\dev\haki\scripts\workflow

# Remove existing config
rmdir /s /q "%LOCALAPPDATA%\nvim"

# Create symlink
mklink /D "%LOCALAPPDATA%\nvim" "%CD%\.config\nvim"
```

## Update Frequency

### When to Update

**Always update after**:
- ✅ Modifying `_vimrc` or NeoVim config files
- ✅ Adding new plugins
- ✅ Changing language-specific settings
- ✅ Updating keybindings

**Optional update for**:
- 📦 New vim-plug or Lazy.nvim versions (automatic)
- 📦 Plugin updates (can do inside editor)

### Scheduled Updates

**Weekly** (recommended):
```batch
# Update both editors
cd C:\dev\haki\scripts\workflow
setupWindowsVim.bat
setupWindowsNeovim.bat
```

**Monthly** (minimum):
```vim
" In Vim
:PlugUpdate

" In NeoVim
:Lazy update
```

## Version Control

### Tracking Changes

All configuration changes are tracked in Git:

```batch
# See what changed
cd C:\dev\haki
git status

# View changes
git diff scripts/workflow/_vimrc
git diff scripts/workflow/.config/nvim/

# Commit changes
git add scripts/workflow/
git commit -m "Update editor configs: add XYZ feature"
```

### Reverting Changes

If an update breaks something:

```batch
# See recent commits
git log --oneline scripts/workflow/

# Revert to previous version
git checkout <commit-hash> scripts/workflow/_vimrc

# Re-run setup
setupWindowsVim.bat
```

### Backup Strategy

Setup scripts automatically create backups:

**Vim backups**:
```
%USERPROFILE%\_vimrc.backup.YYYYMMDD_HHMMSS
```

**NeoVim backups**:
```
%LOCALAPPDATA%\nvim.backup.YYYYMMDD_HHMMSS
```

To restore a backup:
```batch
# Find backup
dir %USERPROFILE%\_vimrc.backup.*

# Restore
copy "%USERPROFILE%\_vimrc.backup.20260216_143022" "%USERPROFILE%\_vimrc" /y

# Verify
vim
```

## Plugin Management

### Vim Plugins

**Update all plugins**:
```vim
:PlugUpdate
```

**Add new plugin**:
```vim
" 1. Edit _vimrc in repo
Plug 'author/plugin-name'

" 2. Run setup script
" scripts/workflow/setupWindowsVim.bat

" 3. Or manually
:source $MYVIMRC
:PlugInstall
```

**Remove plugin**:
```vim
" 1. Remove from _vimrc
" 2. In Vim
:PlugClean
```

### NeoVim Plugins

**Update all plugins**:
```vim
:Lazy update
```

**Add new plugin**:
```lua
-- 1. Create new file in lua/plugins/
-- scripts/workflow/.config/nvim/lua/plugins/myplugin.lua

return {
  'author/plugin-name',
  config = function()
    -- config here
  end,
}

-- 2. Restart NeoVim (auto-installs)
```

**Remove plugin**:
```lua
-- 1. Delete plugin file or comment out
-- 2. In NeoVim
:Lazy clean
```

## Troubleshooting Updates

### Vim Not Loading New Config

```vim
" 1. Check config location
:echo $MYVIMRC
" Should show: C:\Users\YourName\_vimrc

" 2. Reload config
:source $MYVIMRC

" 3. Check for errors
:messages

" 4. If still broken, restore backup
" copy backup file to %USERPROFILE%\_vimrc
```

### NeoVim Config Not Updating

**If using symlink**:
```batch
# Verify symlink
dir %LOCALAPPDATA%\nvim
# Should show <SYMLINK> or <JUNCTION>

# If not a symlink, recreate it
setupWindowsNeovim.bat
```

**If using copy**:
```batch
# Must re-run setup after every change
setupWindowsNeovim.bat
```

### Plugins Not Installing

**Vim**:
```vim
" 1. Check vim-plug is installed
:echo exists(':PlugInstall')
" Should return 2

" 2. Reinstall vim-plug
" Delete: %USERPROFILE%\vimfiles\autoload\plug.vim
" Run: setupWindowsVim.bat

" 3. Try manual install
:PlugInstall
```

**NeoVim**:
```vim
" 1. Check Lazy.nvim
:Lazy

" 2. Reinstall plugins
:Lazy sync

" 3. Check health
:checkhealth lazy
```

### Merge Conflicts (Git)

If multiple machines/users edit configs:

```batch
# 1. See conflicts
git status

# 2. Edit conflicted files
notepad scripts/workflow/_vimrc
# Look for <<<<<<< and >>>>>>>
# Keep desired changes

# 3. Mark resolved
git add scripts/workflow/_vimrc

# 4. Commit
git commit -m "Resolve config merge conflict"

# 5. Update editor
setupWindowsVim.bat
```

## Advanced: Custom Update Script

Create a custom update script for your workflow:

**`scripts/workflow/updateAll.bat`**:
```batch
@echo off
echo Updating all editor configurations...

cd /d %~dp0

echo.
echo [1/3] Updating Vim...
call setupWindowsVim.bat

echo.
echo [2/3] Updating NeoVim...
call setupWindowsNeovim.bat

echo.
echo [3/3] Committing changes to Git...
cd ..\..
git add scripts/workflow/
git status

echo.
echo Done! All editors updated.
pause
```

**Usage**:
```batch
cd C:\dev\haki\scripts\workflow
updateAll.bat
```

## Syncing Across Machines

### Method 1: Git (Recommended)

**On Machine A**:
```batch
# Make changes
notepad scripts/workflow/_vimrc

# Commit and push
git add scripts/workflow/
git commit -m "Update Vim config"
git push
```

**On Machine B**:
```batch
# Pull changes
git pull

# Update editors
cd scripts\workflow
setupWindowsVim.bat
setupWindowsNeovim.bat
```

### Method 2: Cloud Sync

Place repo in OneDrive/Dropbox/Google Drive:
- ✅ Automatic sync
- ⚠️ May need to run setup scripts after sync
- ⚠️ Watch for conflicts

### Method 3: Manual Copy

```batch
# Export from Machine A
xcopy C:\dev\haki\scripts\workflow E:\backup\workflow /E /I /H

# Import to Machine B
xcopy E:\backup\workflow C:\dev\haki\scripts\workflow /E /I /H

# Update on Machine B
cd C:\dev\haki\scripts\workflow
setupWindowsVim.bat
setupWindowsNeovim.bat
```

## Quick Reference

| Task | Vim | NeoVim |
|------|-----|--------|
| **Full update** | `setupWindowsVim.bat` | `setupWindowsNeovim.bat` |
| **Quick copy** | `copy _vimrc ~\_vimrc` | `xcopy .config\nvim %LOCALAPPDATA%\nvim` |
| **Update plugins** | `:PlugUpdate` | `:Lazy update` |
| **Reload config** | `:source $MYVIMRC` | `:source $MYVIMRC` |
| **Check health** | N/A | `:checkhealth` |
| **Clean plugins** | `:PlugClean` | `:Lazy clean` |

## Summary

**Best Practice Workflow**:

1. ✅ Use Git to track all changes
2. ✅ Edit configs in `scripts/workflow/`
3. ✅ Run setup scripts to update system
4. ✅ Test changes in editor
5. ✅ Commit working configs to Git
6. ✅ Update weekly/monthly

**For NeoVim Power Users**:
- Use symlink for instant updates
- No need to re-run setup script

**For Multi-Machine Users**:
- Keep repo in Git
- Pull → Setup → Test on each machine

---

**Questions?** Check the main README.md or editor-specific documentation.
