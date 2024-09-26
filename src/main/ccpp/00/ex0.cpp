#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int fasten;
    if (n == 1)
    {
        cin >> fasten;
        if (fasten == 1)
            cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    int loose = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> fasten;
        if (fasten == 0)
            loose++;
        if (loose > 1)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (loose < 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}