#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s;
    string text;
    cin >> text;
    int sum = 0;
    for (char c : text)
    {
        switch (c)
        {
            case 'C':
                s.push(12);
                break;
            case 'H':
                s.push(1);
                break;
            case 'O':
                s.push(16);
                break;
            case '(':
                s.push(-1);
                break;
            case ')':
                sum = 0;
                while (s.top() != -1)
                {
                    sum += s.top();
                    s.pop();
                }
                s.pop();
                s.push(sum);
                //cout << "subtotal: " << sum << endl;
                break;
            default:
                //cout << "digit val: " << (int)(c - '0') << endl;
                sum = s.top() * (int)(c - '0');
                s.pop();
                s.push(sum);
                //cout << "multiply result: " << sum << endl;
                break;
        }
    }
    sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }
    cout << sum << endl;
    return 0;
}

