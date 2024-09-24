#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <regex>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#include <functional>
#include <cstdio>
#include <climits>
#include <limits>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < (int)s.length(); i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if ( (s[i] == ')' && st.top() == '(') ||
                 (s[i] == ']' && st.top() == '[') ||
                 (s[i] == '}' && st.top() == '{') )
            {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};

int main()
{
    Solution solution;
    cout << to_string(solution.isValid("()[]{}")) << endl;
    cout << to_string(solution.isValid("(((((")) << endl;
    cout << to_string(solution.isValid(")))))")) << endl;
    cout << to_string(solution.isValid(")(){}")) << endl;
    return 0;
}
