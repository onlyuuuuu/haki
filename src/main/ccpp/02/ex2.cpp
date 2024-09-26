#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        int i = 0;
        int max = INT_MIN;
        vector<int> _XiPlusYi(points.size());
        vector<int> XiPlusYi(points.size());
        auto compare = [&_XiPlusYi] (int a, int b) { return _XiPlusYi[a] < _XiPlusYi[b]; };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare);
        deque<int> q(points.size());

        _XiPlusYi[0] = points[0][1] - points[0][0];
        XiPlusYi[0] = INT_MIN;
        for (i = 1; i <= points.size() - 2; i++)
        {
            _XiPlusYi[i] = points[i][1] - points[i][0];
            XiPlusYi[i] = points[i][1] + points[i][0];
        }
        _XiPlusYi[points.size() - 1] = INT_MIN;
        XiPlusYi[points.size() - 1] = points[points.size() - 1][1] + points[points.size() - 1][0];

        q.push_front(0);
        pq.push(0);
        for (i = 1; i < points.size(); i++)
        {
            while (!pq.empty() && points[i][0] - points[pq.top()][0] > k) pq.pop();
            if (pq.empty()) pq.push(i);
            while (!q.empty() && q.back() < pq.top()) q.pop_back();
            if (q.empty())
            {
                q.push_front(i);
                continue;
            }
            max = std::max(max, _XiPlusYi[pq.top()] + XiPlusYi[i]);
            q.push_front(i);
            pq.push(i);
        }

        return max;
    }
};

int main()
{
    vector<vector<int>> points(4);

    vector<int> p1(2);
    p1[0] = 1;
    p1[1] = 3;
    points[0] = p1;

    vector<int> p2(2);
    p2[0] = 2;
    p2[1] = 0;
    points[1] = p2;

    vector<int> p3(2);
    p3[0] = 5;
    p3[1] = 10;
    points[2] = p3;

    vector<int> p4(2);
    p4[0] = 6;
    p4[1] = -10;
    points[3] = p4;

    Solution sol;
    cout << sol.findMaxValueOfEquation(points, 1) << endl;

    return 0;
}
