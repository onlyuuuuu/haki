-- Competitive Programming configuration
-- Keybindings and settings for CompetiTest

-- CompetiTest keybindings (similar to CPH and AutoCP)
vim.keymap.set('n', '<leader>cr', ':CompetiTest run<CR>', { desc = 'CP: Run testcases' })
vim.keymap.set('n', '<leader>cR', ':CompetiTest run_no_compile<CR>', { desc = 'CP: Run without compile' })
vim.keymap.set('n', '<leader>ca', ':CompetiTest add_testcase<CR>', { desc = 'CP: Add testcase' })
vim.keymap.set('n', '<leader>ce', ':CompetiTest edit_testcase<CR>', { desc = 'CP: Edit testcase' })
vim.keymap.set('n', '<leader>cd', ':CompetiTest delete_testcase<CR>', { desc = 'CP: Delete testcase' })
vim.keymap.set('n', '<leader>cc', ':CompetiTest receive testcases<CR>', { desc = 'CP: Receive testcases from web' })
vim.keymap.set('n', '<leader>cp', ':CompetiTest receive problem<CR>', { desc = 'CP: Receive problem' })
vim.keymap.set('n', '<leader>cC', ':CompetiTest receive contest<CR>', { desc = 'CP: Receive contest' })
vim.keymap.set('n', '<leader>cs', ':CompetiTest show_ui<CR>', { desc = 'CP: Show UI' })
vim.keymap.set('n', '<leader>ct', ':CompetiTest convert<CR>', { desc = 'CP: Convert testcases format' })

-- Quick run with F5 (common in competitive programming)
vim.keymap.set('n', '<F5>', ':CompetiTest run<CR>', { desc = 'CP: Quick run' })
vim.keymap.set('n', '<F6>', ':CompetiTest add_testcase<CR>', { desc = 'CP: Quick add testcase' })

-- Competitive Programming specific settings
vim.api.nvim_create_autocmd("FileType", {
  pattern = { "cpp", "c", "java", "python" },
  callback = function()
    -- Enable faster feedback for CP files
    vim.opt_local.updatetime = 100

    -- Show absolute line numbers for easier debugging
    vim.opt_local.number = true
    vim.opt_local.relativenumber = false

    -- Faster scrolling
    vim.opt_local.scrolloff = 5
  end,
})

-- Create CP templates directory if it doesn't exist
local home = vim.fn.expand('~')
local templates_dir = home .. '/cp_templates'
if vim.fn.isdirectory(templates_dir) == 0 then
  vim.fn.mkdir(templates_dir, 'p')
end

-- Create default C++ template if it doesn't exist
local cpp_template = templates_dir .. '/template.cpp'
if vim.fn.filereadable(cpp_template) == 0 then
  local template_content = [[#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void solve() {
    // Your code here

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}
]]
  local file = io.open(cpp_template, 'w')
  if file then
    file:write(template_content)
    file:close()
  end
end

-- Create default C template if it doesn't exist
local c_template = templates_dir .. '/template.c'
if vim.fn.filereadable(c_template) == 0 then
  local template_content = [[#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ll long long

void solve() {
    // Your code here

}

int main() {
    int t = 1;
    // scanf("%d", &t);  // Uncomment for multiple test cases

    while (t--) {
        solve();
    }

    return 0;
}
]]
  local file = io.open(c_template, 'w')
  if file then
    file:write(template_content)
    file:close()
  end
end

-- Create default Python template if it doesn't exist
local py_template = templates_dir .. '/template.py'
if vim.fn.filereadable(py_template) == 0 then
  local template_content = [[#!/usr/bin/env python3
import sys
from typing import List, Tuple, Set, Dict
from collections import defaultdict, Counter, deque
from math import gcd, ceil, floor, sqrt
from itertools import combinations, permutations

def solve():
    """Your solution here"""
    pass

def main():
    t = 1
    # t = int(input())  # Uncomment for multiple test cases

    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
]]
  local file = io.open(py_template, 'w')
  if file then
    file:write(template_content)
    file:close()
  end
end

-- Create default Java template if it doesn't exist
local java_template = templates_dir .. '/template.java'
if vim.fn.filereadable(java_template) == 0 then
  local template_content = [[import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    static StringTokenizer st;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static void solve() throws IOException {
        // Your code here

    }

    public static void main(String[] args) throws IOException {
        int t = 1;
        // t = nextInt();  // Uncomment for multiple test cases

        while (t-- > 0) {
            solve();
        }

        out.flush();
        out.close();
    }
}
]]
  local file = io.open(java_template, 'w')
  if file then
    file:write(template_content)
    file:close()
  end
end

print("Competitive Programming setup loaded! Use <leader>c for CP commands or F5 to run tests.")
