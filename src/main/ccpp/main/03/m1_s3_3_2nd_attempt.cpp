#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Solution() {}
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        int mx = INT_MIN;
        return mx;
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

    // k = 3;
    // m[0] = 0;
    // m[3] = 0;
    // m[9] = 2;

    k = 26;
    m[-17] = 13;
    m[2] = 1;
    m[8] = -5;
    m[18] = -20;

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
