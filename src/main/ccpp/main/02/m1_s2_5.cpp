#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution(){}
    int longestValidParentheses(string s)
    {
        string text = 's' + s;
        int max = 0;
        int length = 0;
        stack<int> st; st.push(0);
        for (int i = 1; i <= (int)text.length(); i++)
        {
            if ( text[st.top()] == '(' && text[i] == ')' )
            {
                st.pop();
                length = i - st.top();
                if (length > max) max = length;
                continue;
            }
            st.push(i);
        }
        return max;
    }
};

int main()
{
    Solution s;
    int i;
    i = s.longestValidParentheses(""); cout << i << endl;
    i = s.longestValidParentheses("()()()((()))"); cout << i << endl;
    i = s.longestValidParentheses("(()"); cout << i << endl;
    return 0;
}

