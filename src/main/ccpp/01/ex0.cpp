#include <bits/stdc++.h>

using namespace std;

int main()
{
    int c = 12;
    int h = 1;
    int o = 16;
    string input;
    cin >> input;
    stack<int> st;
    int sum;
    int top;
    for (int i = 0; i < (int)input.length(); ++i)
    {
        switch (input[i])
        {
            case 'C':
                st.push(c);
                break;
            case 'H':
                st.push(h);
                break;
            case 'O':
                st.push(o);
                break;
            case '(':
                st.push(0);
                break;
            case ')':
                sum = 0;
                while (st.top() != 0)
                {
                    sum += st.top();
                    st.pop();
                }
                st.pop();
                st.push(sum);
                break;
            default:
                top = st.top();
                st.pop();
                st.push(top * int(input[i] - '0'));
                break;
        }
    }
    sum = 0;
    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }
    cout << sum << endl;
    return 0;
}
