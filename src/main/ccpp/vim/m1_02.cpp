#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, fh, hh;
    int c = 0;
    cin >> n;
    cin >> fh;
    for (int i = 0; i < n; i++)
    {
        cin >> hh;
        if (hh > fh)
            c++;
    }
    cout << (c + n) << endl;
    return 0;
}

