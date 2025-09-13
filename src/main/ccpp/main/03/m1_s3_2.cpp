#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, k, a;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
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
        for (int i = k + 1; i <= N; i++)
        {
            cin >> a;
            q.push(a);
            ms.erase(ms.find(q.front()));
            ms.insert(a);
            q.pop();
            cout << " " << *ms.begin();
        }
        cout << endl;
    }
    return 0;
}
