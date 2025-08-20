require("lazyvim")
require("config.lazy")
require("autoclose").setup()

vim.lsp.enable('jdtls') -- Java Language Server
vim.lsp.enable('bashls')
--vim.lsp.enable('biome') -- { "astro", "css", "graphql", "html", "javascript", "javascriptreact", "json", "jsonc", "svelte", "typescript", "typescript.tsx", "typescriptreact", "vue" }
--vim.lsp.enable('ast_grep') -- { "c", "cpp", "rust", "go", "java", "python", "javascript", "javascriptreact", "javascript.jsx", "typescript", "typescriptreact", "typescript.tsx", "html", "css", "kotlin", "dart", "lua" }
vim.lsp.enable('html')
vim.lsp.enable('css_variables')
vim.lsp.enable('cssls')
vim.lsp.enable('cssmodules_ls')
vim.lsp.enable('jsonls')
vim.lsp.enable('dockerls')
vim.lsp.enable('bright_script')
vim.lsp.enable('clangd')

-- Mason NeoVim package manager
require("mason").setup()

-- Load my own configs
require("onlyu")
require("onlyu.remap")
require("onlyu.tree")
require("onlyu.telescope")
require("onlyu.commentary")
require("onlyu.completion")

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

-- Autocommands for specific filetypes
vim.api.nvim_create_autocmd("FileType",
{
  pattern = { "java", "jsp", "c", "h", "cpp" },
  callback = function()
    vim.bo.tabstop = 4
    vim.bo.softtabstop = 4
    vim.bo.shiftwidth = 4
  end,
})

vim.api.nvim_create_autocmd("FileType",
{
  pattern = { "sh", "html", "css", "javascript" },
  callback = function()
    vim.bo.tabstop = 2
    vim.bo.softtabstop = 2
    vim.bo.shiftwidth = 2
  end,
})

vim.cmd.colorscheme "catppuccin-latte"
