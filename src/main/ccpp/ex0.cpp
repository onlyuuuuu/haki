#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <regex>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#include <functional>
#include <cstdio>
#include <climits>
#include <limits>

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