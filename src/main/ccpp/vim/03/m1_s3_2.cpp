#include <bits/stdc++.h>
using namespace std;
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int T, N, k, a;
    // vector<vector<int>> r;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        // vector<int> v;
        multiset<int> ms;
        queue<int> q;
        cin >> N >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a;
            q.push(a);
            ms.insert(a);
        }
        cout << *ms.begin();
        // v.push_back(*ms.begin());
        for (int i = k + 1; i <= N; i++)
        {
            cin >> a;
            q.push(a);
            ms.erase(q.front());
            ms.insert(a);
            q.pop();
            cout << " " << *ms.begin();
            // v.push_back(*ms.begin());
        }
        cout << endl;
    }
    // for (int i = 0; i < (int)r.size(); i++)
    // {
    //     cout << r[i][0];
    //     for (int j = 1; j < (int)r[i].size(); j++)
    //         cout << " " << r[i][j];
    //     cout << endl;
    // }
    return 0;
}
