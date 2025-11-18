-- Additional LSP configs
vim.lsp.config.clangd = {
  cmd = {'clangd', '--background-index', '--clang-tidy', '--log=verbose'},
  init_options = {
    fallbackFlags = { '-std=c++23' },
  },
}
vim.lsp.enable('clangd')
