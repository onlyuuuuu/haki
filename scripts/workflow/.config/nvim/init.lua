require("onlyu")
require("lazyvim")
require("config.lazy")

-- Set tab width to 2 spaces
vim.opt.tabstop = 2        -- Width of tab character
vim.opt.softtabstop = 2    -- Fine tunes the amount of whitespace to be added
vim.opt.shiftwidth = 2     -- Size of an indent
vim.opt.expandtab = true   -- Use spaces instead of tabs

-- Optional settings
vim.opt.smartindent = true -- Automatically indent new lines
vim.opt.autoindent = true  -- Copy indent from current line when starting a new line
vim.opt.guicursor = "n-v-c:block,i-ci-ve:block"

vim.cmd.colorscheme "catppuccin-latte"

-- Netrw configuration
vim.g.netrw_liststyle = 3     -- Tree-style listing (optional)
vim.g.netrw_browse_split = 4  -- Open files in the previous window (optional)
vim.g.netrw_winsize = 30      -- Set width to 50% (may be overridden by explicit resize)

-- Function to open Netrw on the left with correct width
local function open_netrw_left()
    -- Open Netrw in a vertical split on the left with 50 columns
    vim.cmd("topleft vertical 30 Lexplore")
end

-- Autocommand to adjust Netrw after it opens
vim.api.nvim_create_autocmd("FileType", {
    pattern = "netrw",
    callback = function()
        -- Ensure Netrw stays on the left and editor gets focus
        vim.cmd("wincmd H")          -- Move Netrw to the far left
        vim.cmd("vertical resize 30") -- Resize Netrw to 50 columns
        vim.cmd("wincmd p")          -- Switch focus back to the editor window
    end,
})

-- Optional keybinding to toggle Netrw
vim.keymap.set("n", "<leader>e", open_netrw_left, { silent = true, desc = "Open Netrw on left" })

