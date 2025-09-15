#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, i, no, min1, min2, cost, sum;
    while (true)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        cin >> N;
        if (N == 0) return 0;
        for (i = 0; i < N; i++)
        {
            cin >> no;
            q.emplace(no);
        }
        sum = 0;
        while (!q.empty())
        {
            min1 = q.top(); q.pop();
            if (q.empty()) break;
            min2 = q.top(); q.pop();
            cost = min1 + min2;
            q.emplace(cost);
            sum += cost;
        }
        cout << sum << endl;
    }
    return 0;
}