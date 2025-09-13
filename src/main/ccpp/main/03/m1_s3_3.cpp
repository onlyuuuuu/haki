#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution() {}
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        int top = 0; int bot = 1; int sum = 0; int max = 0; int prev; map<int, int> s1m, s2m;
        for (; bot < points.size() && points[bot][0] - points[top][0] > k; bot++) top++;
        s1m[top] = points[top][1] - points[top][0];
        s2m[bot] = points[bot][1] + points[bot][0];
        max = s1m[top] + s2m[bot];
        for (++bot; bot < points.size(); bot++)
        {
            for (; points[bot][0] - points[top][0] > k; top++)
            {
                s1m.erase(top);
                s2m.erase(top);
            }
            if (top == bot) continue;
            prev = bot - 1;
            s1m[prev] = points[prev][1] - points[prev][0];
            s2m[prev] = points[prev][1] + points[prev][0];
            s1m[top] = points[top][1] - points[top][0];
            s2m.erase(top);
            s1m.erase(bot);
            s2m[bot] = points[bot][1] + points[bot][0];
            sum = s1m.rbegin()->second + s2m.rbegin()->second;
            if (sum > max) max = sum;
        }
        return max;
    }
};
int main()
{
    Solution s;
    int i, k; vector<vector<int>> p; map<int, int> m;

    // k = 1;
    // m[1] = 3;
    // m[2] = 0;
    // m[5] = 10;
    // m[6] = -10;

    k = 3;
    m[0] = 0;
    m[3] = 0;
    m[9] = 2;

    for (const auto& [k, v] : m)
    {
        vector<int> xy;
        xy.push_back(k);
        xy.push_back(v);
        p.push_back(xy);
    }
    i = s.findMaxValueOfEquation(p, k);
    cout << i << endl;

    return 0;
}
