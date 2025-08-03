require("lazyvim")
require("config.lazy")
require("autoclose").setup()
require("Comment").setup
{
    -- LHS of toggle mappings in NORMAL mode
    toggler =
    {
        ---Line-comment toggle keymap
        line = '<C-m>',
        ---Block-comment toggle keymap
        block = '<C-n>',
    },
    -- LHS of operator-pending mappings in NORMAL and VISUAL mode
    opleader =
    {
        ---Line-comment keymap
        line = '<C-m>',
        ---Block-comment keymap
        block = '<C-n>',
    },
}

-- TELESCOPE
-- You dont need to set any of these options. These are the default ones. Only
-- the loading is important
require('telescope').setup
{
  extensions =
  {
    fzf =
    {
      fuzzy = true,                    -- false will only do exact matching
      override_generic_sorter = true,  -- override the generic sorter
      override_file_sorter = true,     -- override the file sorter
      case_mode = "smart_case",        -- or "ignore_case" or "respect_case"
                                       -- the default case_mode is "smart_case"
    }
  }
}
-- To get fzf loaded and working with telescope, you need to call
-- load_extension, somewhere after setup function:
require('telescope').load_extension('fzf')

-- Load my own configs
require("onlyu")
require("onlyu.remap")
require("onlyu.telescope")

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

