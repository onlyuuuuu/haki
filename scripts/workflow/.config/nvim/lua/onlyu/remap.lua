vim.g.mapleader = " "
vim.keymap.set("n", "<leader><Tab>", vim.cmd.Ex)
-- vim.keymap.set("n", "<leader>pwd", vim.cmd.Ex)

-- Lazy
vim.keymap.set('n', '<C-l>', vim.cmd.Lazy, { desc = 'Open Lazy plugin manager' })

-- Tree
vim.keymap.set('n', '<leader>t', ':Neotree toggle<CR>', { desc = "Toggle File Tree" })

-- TELESCOPE
local builtin = require('telescope.builtin')

-- Trying to make it like VSCode & Jetbrains IDEs
vim.keymap.set('n', '<C-p>', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<C-n>', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<C-f>', builtin.live_grep, { desc = 'Telescope live grep' })
vim.keymap.set('n', '<leader><C-p>', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<leader><C-n>', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<leader><C-f>', builtin.live_grep, { desc = 'Telescope live grep' })

-- Save
vim.keymap.set({'n', 'i', 'v'}, '<C-w>', '<cmd>w<cr>', { desc = 'Save file' })
vim.keymap.set({'n', 'i', 'v'}, '<C-s>', '<cmd>w<cr>', { desc = 'Save file' })
vim.keymap.set({'n', 'i', 'v'}, '<C-q>', '<cmd>q<cr>', { desc = 'Quit' })
vim.keymap.set({'n', 'i', 'v'}, '<C-S-q>', '<cmd>q!<cr>', { desc = 'Quit without saving' })

-- Default and additonals
vim.keymap.set('n', '<leader>ff', builtin.find_files, { desc = 'Telescope find files' })
vim.keymap.set('n', '<leader>fg', builtin.live_grep, { desc = 'Telescope live grep' })
vim.keymap.set('n', '<leader>fb', builtin.buffers, { desc = 'Telescope buffers' })
vim.keymap.set('n', '<leader>fh', builtin.help_tags, { desc = 'Telescope help tags' })

