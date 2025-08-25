#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t;
    cin >> n;
    cin >> t;
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> p[i];
    }
    int pos = 1;
    while (pos < t)
    {
        pos += p[pos];
        if (pos == t)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}

