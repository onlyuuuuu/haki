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
