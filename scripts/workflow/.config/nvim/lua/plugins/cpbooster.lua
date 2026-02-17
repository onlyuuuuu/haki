-- CPBooster - Parse problems from competitive programming websites
-- Works with Codeforces, AtCoder, CodeChef, etc.
return {
  'p00f/cphelper.nvim',
  event = "VeryLazy",
  config = function()
    -- CPHelper uses vim global variables for configuration
    vim.g['cph#lang'] = 'cpp'
    vim.g['cph#dir'] = vim.fn.expand('~/cp_templates/')
  end,
}
