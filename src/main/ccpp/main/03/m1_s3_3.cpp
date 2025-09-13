#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        int top = 0; int bot = 1; map<int, int> s1m, s2m;

        s1m[points[top][0]] = points[top][1] - points[top][0];
        for (; bot < points.size() && points[bot][0] - points[top][0] <= k; bot++)
        {
            s1m[points[i][0]] = points[i][1] - points[i][0];
            s2m[points[i][0]] = points[i][1] + points[i][0];
        }
        s2m[points[bot][0]] = points[bot][1] + points[bot][0];
        int max = s1m.rbegin()->second + s2m.rbegin()->second;

        for (++bot; bot < points.size(); bot++)
        {
            while (points[bot][0] - points[top][0] > k) top++;
        }

        return max;
    }
};
int main()
{

    return 0;
}
