local project_name = vim.fn.fnamemodify(vim.fn.getcwd(), ':p:h:t')
local workspace_dir = '/tools/java-lang-server-data/' .. project_name
local config = 
{
  cmd = 
  {
    '/tools/eclipse-java-ls/bin/jdtls',
    '-data', workspace_dir
  },
  root_dir = vim.fs.dirname(vim.fs.find({'gradlew', 'gradlew.bat', '.git', 'mvnw', 'mvnw.bat'}, { upward = true })[1]),
}
-- require('jdtls').start_or_attach(config)
