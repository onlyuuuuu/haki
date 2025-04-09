require("onlyu")
require("onlyu.remap")
require("lazyvim")
require("config.lazy")
require("autoclose").setup()
--require("nvim-java").setup()

-- Set tab width to 2 spaces
vim.opt.number = true
vim.opt.tabstop = 2        -- Width of tab character
vim.opt.softtabstop = 2    -- Fine tunes the amount of whitespace to be added
vim.opt.shiftwidth = 2     -- Size of an indent
vim.opt.expandtab = true   -- Use spaces instead of tabs

-- Optional settings
vim.opt.smartindent = true -- Automatically indent new lines
vim.opt.autoindent = true  -- Copy indent from current line when starting a new line
vim.opt.guicursor = "n-v-c:block,i-ci-ve:block"

vim.cmd.colorscheme "catppuccin-latte"

