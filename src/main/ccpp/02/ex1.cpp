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
    int i, j, k;
    int numberOfTests;
    int numberOfJudges;
    int numberOfOppPerFight;
    int left, right;
    string result = "";

    cin >> numberOfTests;
    for (i = 0; i < numberOfTests; ++i)
    {
        // init
        cin >> numberOfJudges;
        cin >> numberOfOppPerFight;
        int apm[numberOfJudges];
        auto compare = [&apm] (int a, int b){ return apm[a] > apm[b]; };
        priority_queue<int, vector<int>, decltype(compare)> minHeapIndexes(compare);
        left = 0;
        right = numberOfOppPerFight - 1;
        for (j = 0; j < numberOfOppPerFight; ++j)
        {
            cin >> apm[j];
            minHeapIndexes.push(j);
        }
        for (k = j; k < numberOfJudges; ++k)
            cin >> apm[k];
        result.append(to_string(apm[minHeapIndexes.top()]));
        result.append(" ");

        // next
        ++left;
        minHeapIndexes.push(++right);

        // real processing
        while (right != numberOfJudges)
        {
            while (!minHeapIndexes.empty() && minHeapIndexes.top() < left)
                minHeapIndexes.pop();
            result.append(to_string(apm[minHeapIndexes.top()]));
            result.append(" ");
            // next
            ++left;
            minHeapIndexes.push(++right);
        }
        result.append("\n");
    }
    cout << result << endl;
}
