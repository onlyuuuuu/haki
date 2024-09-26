#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n + 2];
    a[0] = 0;
    a[n + 1] = 0;

    int l[n + 2];
    l[0] = 0;
    l[n + 1] = 0;

    int r[n + 2];
    r[0] = 0;
    r[n + 1] = 0;

    stack<int> lst;
    lst.push(0);

    stack<int> rst;
    rst.push(n + 1);

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        while (a[lst.top()] >= a[i])
            lst.pop();
        l[i] = lst.top();
        lst.push(i);
    }

    for (int i = n; i >= 1; --i)
    {
        while (a[rst.top()] >= a[i])
            rst.pop();
        r[i] = rst.top();
        rst.push(i);
    }

    long long max = 0;
    long long area = 0;
    for (int i = 1; i <= n; ++i)
    {
        area = ((i - l[i]) + (r[i] - i) - 1) * a[i];
        if (area > max)
            max = area;
    }

    cout << max << endl;
}
