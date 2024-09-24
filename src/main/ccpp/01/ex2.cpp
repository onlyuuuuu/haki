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

    int a[n + 2];
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
        lst.push(a[i]);
    }
}
