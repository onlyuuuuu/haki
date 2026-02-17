return
{
  "okuuva/auto-save.nvim",
  cmd = "ASToggle", -- Commands to lazy load
  event = { "InsertLeave", "TextChanged" }, -- Events to lazy load
  opts = {
    enabled = true, -- Start enabled
    trigger_events = {
      immediate_save = { "BufLeave", "FocusLost" },
      defer_save = { "InsertLeave", "TextChanged" },
    },
  },
}
