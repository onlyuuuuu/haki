#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
        s.insert(0, ")");
        stack<int> st;
        st.push(0);
        int maximum = 0;
        for (int i = 1; i < (int)s.length(); ++i)
        {
            if (s[i] == ')' && s[st.top()] == '(')
            {
                st.pop();
                maximum = max(i - st.top(), maximum);
                continue;
            }
            st.push(i);
        }
        return maximum;
    }
};

int main()
{
    Solution solution;
    cout << to_string(solution.longestValidParentheses("))()()))(()(()))")) << endl;
    cout << to_string(solution.longestValidParentheses("()()()()()))()()))(()(()))")) << endl;
    cout << to_string(solution.longestValidParentheses(")()())")) << endl;
    return 0;
}
