-- CompetiTest.nvim - Competitive Programming Helper for NeoVim
-- Similar to VSCode CPH and CLion AutoCP
return {
  'xeluxee/competitest.nvim',
  dependencies = 'MunifTanjim/nui.nvim',
  config = function()
    require('competitest').setup({
      -- Local test case configuration
      local_config_file_name = ".competitest.lua",

      -- Floating window configuration for testcases
      floating_border = "rounded",
      floating_border_highlight = "FloatBorder",
      picker_ui = {
        width = 0.2,
        height = 0.3,
        mappings = {
          focus_next = { "j", "<down>", "<Tab>" },
          focus_prev = { "k", "<up>", "<S-Tab>" },
          close = { "<esc>", "<C-c>", "q", "Q" },
          submit = { "<cr>" },
        },
      },
      editor_ui = {
        popup_width = 0.4,
        popup_height = 0.6,
        show_nu = true,
        show_rnu = false,
        normal_mode_mappings = {
          switch_window = { "<C-h>", "<C-l>", "<C-i>" },
          save_and_close = "<C-s>",
          cancel = { "q", "Q" },
        },
        insert_mode_mappings = {
          switch_window = { "<C-h>", "<C-l>", "<C-i>" },
          save_and_close = "<C-s>",
          cancel = "<C-q>",
        },
      },
      runner_ui = {
        interface = "popup", -- "popup" or "split"
        selector_show_nu = false,
        selector_show_rnu = false,
        show_nu = true,
        show_rnu = false,
        mappings = {
          run_again = "R",
          run_all_again = "<C-r>",
          kill = "K",
          kill_all = "<C-k>",
          view_input = { "i", "I" },
          view_output = { "a", "A" },
          view_stdout = { "o", "O" },
          view_stderr = { "e", "E" },
          toggle_diff = { "d", "D" },
          close = { "q", "Q" },
        },
        viewer = {
          width = 0.5,
          height = 0.5,
          show_nu = true,
          show_rnu = false,
          close_mappings = { "q", "Q" },
        },
      },
      popup_ui = {
        total_width = 0.8,
        total_height = 0.8,
        layout = {
          { 4, "tc" },
          { 5, { { 1, "so" }, { 1, "si" } } },
          { 5, { { 1, "eo" }, { 1, "se" } } },
        },
      },
      split_ui = {
        position = "right",
        relative_to_editor = true,
        total_width = 0.3,
        vertical_layout = {
          { 1, "tc" },
          { 1, { { 1, "so" }, { 1, "eo" } } },
          { 1, { { 1, "si" }, { 1, "se" } } },
        },
        total_height = 0.4,
        horizontal_layout = {
          { 2, "tc" },
          { 3, { { 1, "so" }, { 1, "si" } } },
          { 3, { { 1, "eo" }, { 1, "se" } } },
        },
      },

      -- Save all files before running tests
      save_current_file = true,
      save_all_files = false,

      -- Compile and run commands for different languages
      compile_directory = ".",
      compile_command = {
        c = { exec = "gcc", args = { "-Wall", "-std=c11", "$(FNAME)", "-o", "$(FNOEXT)" } },
        cpp = { exec = "g++", args = { "-Wall", "-std=c++20", "$(FNAME)", "-o", "$(FNOEXT)" } },
        rust = { exec = "rustc", args = { "$(FNAME)" } },
        java = { exec = "javac", args = { "$(FNAME)" } },
      },
      running_directory = ".",
      run_command = {
        c = { exec = "./$(FNOEXT)" },
        cpp = { exec = "./$(FNOEXT)" },
        python = { exec = "python", args = { "$(FNAME)" } },
        rust = { exec = "./$(FNOEXT)" },
        java = { exec = "java", args = { "$(FNOEXT)" } },
        javascript = { exec = "node", args = { "$(FNAME)" } },
      },

      -- Multiple file support
      multiple_testing = -1, -- -1 = all testcases, 0 = single testcase, >0 = specific number

      -- Maximum output length
      maximum_time = 5000, -- 5 seconds timeout

      -- Output compare method
      output_compare_method = "squish", -- "exact", "squish" (ignore trailing whitespaces)

      -- Test cases directory
      testcases_directory = ".",
      testcases_use_single_file = true,
      testcases_auto_detect_storage = true,
      testcases_single_file_format = "$(FNOEXT).testcases",

      -- Companion support (for parsing problems from websites)
      companion_port = 27121,
      receive_print_message = true,

      -- Template files
      template_file = {
        c = "~/cp_templates/template.c",
        cpp = "~/cp_templates/template.cpp",
        java = "~/cp_templates/template.java",
        python = "~/cp_templates/template.py",
      },
      evaluate_template_modifiers = true,

      -- Date format for templates
      date_format = "%Y-%m-%d %H:%M:%S",

      -- Received problems directory
      received_problems_path = "$(CWD)/$(PROBLEM).$(FEXT)",
      received_problems_prompt_path = true,
      received_contests_directory = "$(CWD)",
      received_contests_problems_path = "$(PROBLEM).$(FEXT)",
      received_contests_prompt_directory = true,
      received_contests_prompt_extension = true,

      -- Open received problems/contests in new tabs
      open_received_problems = true,
      open_received_contests = true,

      -- Replace received test cases
      replace_received_testcases = false,
    })
  end,
}
