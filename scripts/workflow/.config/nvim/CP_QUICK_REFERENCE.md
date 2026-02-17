# Competitive Programming Quick Reference

## Quick Start

1. Open problem file: `nvim solution.cpp`
2. Add test case: Press `F6` or `<leader>ca`
3. Run tests: Press `F5` or `<leader>cr`

## Essential Keybindings

```
F5              → Run all test cases
F6              → Add new test case
<leader>cr      → Run test cases
<leader>ca      → Add test case
<leader>ce      → Edit test case
<leader>cd      → Delete test case
<leader>cc      → Receive from web (needs browser extension)
```

## Languages Supported

- **C++**: g++ -std=c++20
- **C**: gcc -std=c11
- **Python**: python3
- **Java**: javac/java
- **Rust**: rustc
- **JavaScript**: node

## File Structure

```
problem.cpp        → Your solution
problem.testcases  → Test cases (auto-managed)
```

## Test Case Format

```
[TESTCASE:1]
[INPUT]
3 4
[OUTPUT]
7

[TESTCASE:2]
[INPUT]
5 10
[OUTPUT]
15
```

## Templates Location

```
~/cp_templates/template.cpp   → C++ template
~/cp_templates/template.c     → C template
~/cp_templates/template.py    → Python template
~/cp_templates/template.java  → Java template
```

## Runner UI Controls

While viewing test results:

```
R    → Run current test again
Ctrl+R → Run all tests again
K    → Kill current test
Ctrl+K → Kill all tests
i/I  → View input
a/A  → View expected output
o/O  → View stdout
e/E  → View stderr
d/D  → Toggle diff view
q/Q  → Close window
```

## Common Issues

**Compiler not found**: Add to PATH
- Windows MinGW: `C:\MinGW\bin`
- Windows MSYS2: `C:\msys64\ucrt64\bin`

**Test timeout**: Increase in config (default 5000ms)

**Browser extension**: Install Competitive Companion, set port 27121

## Pro Tips

1. **Fast testing**: Press `F5` repeatedly to quick-test after changes
2. **Multiple test cases**: Add all sample inputs at once
3. **Templates**: Customize `~/cp_templates/` for your style
4. **Diff mode**: Press `d` to see exact differences in output
5. **Time tracking**: Runner shows execution time per test

## Example Workflow

```bash
# 1. Open NeoVim
nvim A.cpp

# 2. Add test case (press F6)
# Input: 3 4
# Output: 7

# 3. Write solution
# 4. Test (press F5)
# 5. Debug if needed
# 6. Add more test cases (F6)
# 7. Repeat until all pass
```

## Using Browser Extension

1. Install Competitive Companion
2. Open problem on Codeforces/AtCoder
3. Start NeoVim (must be running!)
4. Click extension icon
5. Problem opens with test cases automatically

## Performance

- Compilation: ~1-2 seconds (C++/Java)
- Execution: < 5 seconds per test
- Parallel: Tests run sequentially by default

---

**More help**: See `CP_README.md` for full documentation
