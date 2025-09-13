#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution() {}
    bool isValid(string s)
    {
        stack<char> st; st.push('s');
        for (char c : s)
        {
            if ( (st.top() == '(' && c == ')') ||
                 (st.top() == '[' && c == ']') || 
                 (st.top() == '{' && c == '}') )
                st.pop();
            else
                st.push(c);
        }
        return st.top() == 's';
    }
};

int main()
{
    Solution s;
    bool b;
    b = s.isValid("{}[](){[()[]{}()]}"); cout << b << endl;
    b = s.isValid(")))))"); cout << b << endl;
    return 0;
}

