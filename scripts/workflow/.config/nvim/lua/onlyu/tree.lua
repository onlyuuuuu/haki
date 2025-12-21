-- disable netrw at the very start of your init.lua
vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1

-- optionally enable 24-bit colour
vim.opt.termguicolors = true

require("neo-tree").setup({
  window = {
    width = 30,
  },
  filesystem = {
    filtered_items = {
      visible = true, -- when true, they will just be displayed differently instead of being hidden
      hide_dotfiles = false,
      hide_gitignored = false,
      hide_by_name = {
        --".DS_Store",
        --"thumbs.db",
        --"node_modules",
      },
    },
    follow_current_file = {
      enabled = true,
    },
  },
})
