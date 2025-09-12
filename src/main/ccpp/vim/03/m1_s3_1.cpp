#include <bits/stdc++.h>
using namespace std;
int main()
{
    int P, C, i, e;
    char ch;
    int _case = 1;
    while (true)
    {
        cin >> P;
        cin >> C;
        if (P == 0 || C == 0) return 0;
        cout << "Case " << _case++ << ":" << endl;
        deque<int> q;
        stack<int> s;
        for (i = 1; i <= min(C, P); i++) q.push_back(i);
        for (i = 1; i <= C; i++)
        {
            cin >> ch;
            if (ch == 'N')
            {
                cout << q.front() << endl;
                q.push_back(q.front());
                q.pop_front();
                continue;
            }
            cin >> e;
            while (q.front() != e && !q.empty())
            {
                s.push(q.front());
                q.pop_front();
            }
            if (!q.empty())
                q.pop_front();
            while (!s.empty())
            {
                q.push_front(s.top());
                s.pop();
            }
            q.push_front(e);
        }
    }
    return 0;
}
