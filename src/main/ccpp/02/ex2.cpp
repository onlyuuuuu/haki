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

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k)
    {
        int i;
        int temp;
        int max;
        int values[points.size()];

        // re-write
        for (i = 0; i < points.size(); ++i)
        {
            if (points[i][0] < 0)
                values[i] = points[i][1] - points[i][0];
            else
                values[i] = points[i][1] + points[i][0];
        }

        auto compare = [&values] (int a, int b) { return values[a] < values[b]; };
        priority_queue<int, vector<int>, decltype(compare)> indexMaxH(compare);

        // init
        i = 0;
        while (indexMaxH.size() != 2)
        {
            while (!indexMaxH.empty() && points[i][0] - points[indexMaxH.top()][0] > k)
                indexMaxH.pop();
            indexMaxH.push(i++);
        }
        temp = indexMaxH.top();
        indexMaxH.pop();
        max = values[temp] + values[indexMaxH.top()];
        indexMaxH.push(temp);

        // go


        return 0;
    }
};

int main()
{
    vector<vector<int>> points;

    vector<int> p1;
    p1.push_back(1);
    p1.push_back(2);
    points.push_back(p1);

    vector<int> p2;
    p1.push_back(2);
    p1.push_back(0);
    points.push_back(p1);

    vector<int> p3;
    p1.push_back(5);
    p1.push_back(10);
    points.push_back(p1);

    vector<int> p4;
    p1.push_back(6);
    p1.push_back(-10);
    points.push_back(p1);

    Solution sol;
    cout << sol.findMaxValueOfEquation(points, 1) << endl;

    return 0;
}
