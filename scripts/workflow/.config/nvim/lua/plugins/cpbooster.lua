-- CPBooster - Parse problems from competitive programming websites
-- Works with Codeforces, AtCoder, CodeChef, etc.
return {
  'p00f/cphelper.nvim',
  event = "VeryLazy",
  config = function()
    -- CPHelper configuration
    -- This provides additional parsing capabilities for competitive programming sites
    require('cphelper').setup({
      -- Default language to use
      default_language = 'cpp',

      -- Template directory
      template_path = vim.fn.expand('~/cp_templates/'),

      -- Problem directory structure
      -- e.g., codeforces/1234/A/A.cpp
      directory_structure = {
        use_platform = true, -- codeforces, atcoder, etc.
        use_contest = true,  -- contest number/name
        use_problem = true,  -- problem letter/name
      },

      -- Compile commands
      compile_command = {
        cpp = 'g++ -std=c++20 -O2 -Wall',
        c = 'gcc -std=c11 -O2 -Wall',
        java = 'javac',
        python = 'python3',
      },

      -- Run commands
      run_command = {
        cpp = './',
        c = './',
        java = 'java',
        python = 'python3',
      },
    })
  end,
}
