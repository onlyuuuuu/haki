-- Additional LSP configs
local lspconfig = require('lspconfig')
lspconfig.clangd.setup({
  cmd = {'clangd', '--background-index', '--clang-tidy', '--log=verbose'},
  init_options = {
    fallbackFlags = { '-std=c++23' },
  },
})
