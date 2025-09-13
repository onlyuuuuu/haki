#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    bool b;

    if (n == 1)
    {
        cin >> b;
        if (b == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        if (b == false)
            count++;
    }

    if (count == 1)
        cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

