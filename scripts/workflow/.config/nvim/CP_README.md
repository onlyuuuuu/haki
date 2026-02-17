# Competitive Programming Setup for NeoVim

This NeoVim configuration includes powerful competitive programming tools similar to VSCode's CPH and CLion's AutoCP.

## Features

- **CompetiTest.nvim**: Full-featured competitive programming helper
  - Run test cases with one keypress
  - Add/edit/delete test cases easily
  - Automatic compilation and execution
  - View input/output/expected output side-by-side
  - Support for C, C++, Java, Python, Rust, JavaScript
  - Testcase auto-detection and management

- **CPHelper.nvim**: Additional problem parsing from competitive programming websites
  - Parse problems from Codeforces, AtCoder, CodeChef, etc.
  - Automatic test case extraction
  - Template-based file generation

## Keybindings

### Main Commands (Leader = Space)

| Keybinding | Command | Description |
|------------|---------|-------------|
| `<leader>cr` | Run testcases | Compile and run all test cases |
| `<leader>cR` | Run without compile | Run without recompiling |
| `<leader>ca` | Add testcase | Add a new test case |
| `<leader>ce` | Edit testcase | Edit existing test case |
| `<leader>cd` | Delete testcase | Delete a test case |
| `<leader>cc` | Receive testcases | Receive test cases from web (requires browser extension) |
| `<leader>cp` | Receive problem | Receive problem from web |
| `<leader>cC` | Receive contest | Receive entire contest |
| `<leader>cs` | Show UI | Show CompetiTest UI |
| `<leader>ct` | Convert format | Convert testcases format |

### Quick Access Keys

| Key | Command | Description |
|-----|---------|-------------|
| `F5` | Run testcases | Quick run all test cases |
| `F6` | Add testcase | Quick add test case |

## Templates

Default templates are automatically created in `~/cp_templates/`:
- `template.cpp` - C++ template with common macros and fast I/O
- `template.c` - C template
- `template.py` - Python template with common imports
- `template.java` - Java template with fast I/O

You can customize these templates to match your coding style.

## Browser Extension (For Parsing Problems)

To automatically receive problems and test cases from competitive programming websites:

### Installation

1. **Install Competitive Companion Browser Extension**:
   - **Chrome/Edge**: [Competitive Companion on Chrome Web Store](https://chrome.google.com/webstore/detail/competitive-companion/cjnmckjndlpiamhfimnnjmnckgghkjbl)
   - **Firefox**: [Competitive Companion on Firefox Add-ons](https://addons.mozilla.org/en-US/firefox/addon/competitive-companion/)

2. **Configure the Extension**:
   - Click on the extension icon
   - Set port to `27121` (default in config)
   - Enable for your favorite competitive programming sites

3. **Usage**:
   - Open any problem on Codeforces, AtCoder, CodeChef, etc.
   - Click the Competitive Companion extension icon
   - The problem will automatically open in NeoVim with test cases!

### Supported Websites

- Codeforces
- AtCoder
- CodeChef
- TopCoder
- HackerRank
- LeetCode
- CSES
- Kattis
- And many more!

## Workflow Example

### Basic Workflow (Manual Test Cases)

1. Create your solution file (e.g., `solution.cpp`)
2. Press `<leader>ca` to add test cases
3. Enter input and expected output
4. Press `F5` or `<leader>cr` to run
5. View results in the popup window

### Advanced Workflow (With Browser Extension)

1. Open a problem on Codeforces/AtCoder/etc.
2. Click Competitive Companion extension
3. NeoVim automatically opens with:
   - Problem file from template
   - All sample test cases loaded
4. Write your solution
5. Press `F5` to test
6. Iterate until all tests pass

## Test Case Storage

Test cases are stored in `.testcases` files next to your source code:
- `solution.cpp` → `solution.testcases`

Format example:
```
[TESTCASE:1]
[INPUT]
3
[OUTPUT]
6

[TESTCASE:2]
[INPUT]
5
[OUTPUT]
120
```

## Configuration

Configuration is located in:
- Plugin: `lua/plugins/competitest.lua`
- Keybindings: `lua/onlyu/cp.lua`

### Common Customizations

#### Change Compiler Flags

Edit `lua/plugins/competitest.lua`:

```lua
compile_command = {
  cpp = { exec = "g++", args = { "-Wall", "-std=c++20", "-O2", "$(FNAME)", "-o", "$(FNOEXT)" } },
}
```

#### Change Timeout

```lua
maximum_time = 5000, -- milliseconds
```

#### Change UI Layout

```lua
runner_ui = {
  interface = "split", -- or "popup"
}
```

## Troubleshooting

### Compiler Not Found

**Windows**: Ensure GCC/G++ is in your PATH
- If using MinGW: Add `C:\MinGW\bin` to PATH
- If using MSYS2: Add `C:\msys64\ucrt64\bin` to PATH

**Check**:
```bash
g++ --version
gcc --version
```

### Python Not Found

Ensure Python is installed and in PATH:
```bash
python --version
```

### Test Cases Not Loading from Browser

1. Check that NeoVim is running when you click the extension
2. Verify port `27121` is not blocked by firewall
3. Check extension settings match NeoVim port
4. Restart NeoVim and try again

### Compilation Errors

Check your compile command in the config:
```vim
:CompetiTest show_ui
```

## Tips

1. **Use Templates**: Customize templates in `~/cp_templates/` with your preferred style
2. **Fast I/O**: Templates include fast I/O optimizations for competitive programming
3. **Multiple Files**: You can have different test cases for each problem
4. **Keyboard Focused**: Everything can be done without touching the mouse
5. **Split Screen**: Use `:split` or `:vsplit` to view test cases and code side-by-side

## Additional Resources

- [CompetiTest Documentation](https://github.com/xeluxee/competitest.nvim)
- [Competitive Companion](https://github.com/jmerle/competitive-companion)
- [Competitive Programming Tips](https://cp-algorithms.com/)

## Support

For issues with:
- **NeoVim config**: Check `:checkhealth` in NeoVim
- **Plugin issues**: See plugin GitHub repos
- **Competitive programming**: Practice on Codeforces, AtCoder, etc.

Happy coding and good luck with your contests! 🚀
