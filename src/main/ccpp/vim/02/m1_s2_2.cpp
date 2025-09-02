#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    v.push_back(0);
    stack<int> s;
    s.push(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        while (v[s.top()] >= v[i]) s.pop();
        cout << s.top() << " ";
        s.push(i);
    }
    return 0;
}

