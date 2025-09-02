#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 2); v[0] = 0; v[n + 1] = 0; 
    vector<int> vl(n + 1);
    vector<int> vr(n + 1);
    stack<int> sl; sl.push(0);
    stack<int> sr; sr.push(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        while (v[sl.top()] >= v[i]) sl.pop();
        vl[i] = sl.top();
        sl.push(i);
    }
    for (int i = n; i >= 1; i--)
    {
        while (v[sr.top()] >= v[i]) sr.pop();
        vr[i] = sr.top();
        sr.push(i);
    }
    unsigned long long m = 0;
    unsigned long long s = 0;
    for (int i = 1; i <= n; i++)
    {
        s = (unsigned long long)v[i] * (unsigned long long)(vr[i] - vl[i] - 1);
        if (s > m) m = s;
    }
    cout << m;
    return 0;
}

