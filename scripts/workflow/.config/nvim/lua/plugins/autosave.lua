return
{
  "okuuva/auto-save.nvim",
  version = '^1.0.0', -- Use the latest version
  cmd = "ASToggle", -- Commands to lazy load
  event = { "InsertLeave", "TextChanged" }, -- Events to lazy load
  opts = {
    -- specific configuration (optional)
    enabled = true, -- Start enabled
    trigger_events = { "InsertLeave", "TextChanged" }, -- Save when leaving insert mode or changing text
  },
}
