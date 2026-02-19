-- AutoCP-style configuration for NeoVim
-- Mimics CLion's AutoCP behavior with automatic test case management

return {
  -- Additional plugin for snippet-based test case insertion
  {
    'L3MON4D3/LuaSnip',
    event = "InsertEnter",
    dependencies = { "rafamadriz/friendly-snippets" },
    config = function()
      local ls = require("luasnip")
      local s = ls.snippet
      local t = ls.text_node
      local i = ls.insert_node

      -- Add competitive programming snippets
      ls.add_snippets("cpp", {
        -- Quick main template
        s("cpmain", {
          t({"#include <bits/stdc++.h>", "using namespace std;", "", "int main() {", "    "}),
          i(1, "// code here"),
          t({"", "    return 0;", "}"})
        }),

        -- For loop
        s("fori", {
          t("for (int "),
          i(1, "i"),
          t(" = 0; "),
          i(2, "i"),
          t(" < "),
          i(3, "n"),
          t("; "),
          i(4, "i"),
          t("++) {"),
          t({"", "    "}),
          i(5, "// code"),
          t({"", "}"})
        }),

        -- Fast I/O
        s("fastio", {
          t({"ios_base::sync_with_stdio(false);", "cin.tie(nullptr);"})
        }),

        -- Vector declaration
        s("vec", {
          t("vector<"),
          i(1, "int"),
          t("> "),
          i(2, "v"),
          t(";")
        }),

        -- Pair declaration
        s("pii", {
          t("pair<int, int> "),
          i(1, "p"),
          t(";")
        }),
      })

      -- Python snippets
      ls.add_snippets("python", {
        s("cpmain", {
          t({"def solve():", "    "}),
          i(1, "pass"),
          t({"", "", "if __name__ == '__main__':", "    t = int(input())", "    for _ in range(t):", "        solve()"})
        }),

        s("readin", {
          i(1, "n"),
          t(" = int(input())")
        }),

        s("readlist", {
          i(1, "arr"),
          t(" = list(map(int, input().split()))")
        }),
      })

      -- Java snippets
      ls.add_snippets("java", {
        s("cpmain", {
          t({"import java.util.*;", "import java.io.*;", "", "public class Main {", "    public static void main(String[] args) {", "        Scanner sc = new Scanner(System.in);", "        "}),
          i(1, "// code here"),
          t({"", "    }", "}"})
        }),
      })
    end,
  },

  -- Auto-pairs for brackets (helpful in CP)
  {
    'm4xshen/autoclose.nvim',
    event = "InsertEnter",
    config = function()
      require("autoclose").setup({
        keys = {
          ["("] = { escape = false, close = true, pair = "()" },
          ["["] = { escape = false, close = true, pair = "[]" },
          ["{"] = { escape = false, close = true, pair = "{}" },
          ['"'] = { escape = true, close = true, pair = '""' },
          ["'"] = { escape = true, close = true, pair = "''" },
        },
      })
    end,
  },

  -- Auto-save (like AutoCP auto-save feature)
  {
    'Pocco81/auto-save.nvim',
    event = { "InsertLeave", "TextChanged" },
    config = function()
      require("auto-save").setup({
        enabled = true,
        trigger_events = {"InsertLeave", "TextChanged"},
        condition = function(buf)
          local fn = vim.fn
          local utils = require("auto-save.utils.data")

          -- Only auto-save for competitive programming files
          if fn.getbufvar(buf, "&modifiable") == 1 and
             utils.not_in(fn.getbufvar(buf, "&filetype"), {'neo-tree'}) then
            local filename = fn.expand("%:t")
            -- Auto-save for common CP file patterns
            if filename:match("%.cpp$") or
               filename:match("%.c$") or
               filename:match("%.py$") or
               filename:match("%.java$") then
              return true
            end
          end
          return false
        end,
        write_all_buffers = false,
        debounce_delay = 1000, -- 1 second delay
      })
    end,
  },
}
