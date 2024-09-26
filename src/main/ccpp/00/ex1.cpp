#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int h;
    cin >> h;
    int total = 0;
    int ih;
    for (int i = 0; i < n; ++i)
    {
        cin >> ih;
        if (ih > h)
        {
            total += 2;
            continue;
        }
        ++total;
    }
    cout << total << endl;
}