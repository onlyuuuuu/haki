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

class CustomCompare
{
public:
    int arr[];

    CustomCompare(int arr[])
    {
    }

    bool operator() (int, int)
    {
        return true;
    }
};

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
        CustomCompare customCompare(apm);
        priority_queue<int, vector<int>, > minHeapIndexes;
        left = 0;
        right = numberOfOppPerFight - 1;
        for (j = 0; j < numberOfOppPerFight; ++j)
        {
            cin >> apm[j];
            minHeapIndexes.push(j);
        }
        for (k = j; k < numberOfJudges; ++k)
            cin >> apm[k];
        result.append(apm[minHeapIndexes.top()] + " ");

        // next
        ++left;
        minHeapIndexes.push(++right);

        // real processing
        while (right != numberOfJudges)
        {
            while (!minHeapIndexes.empty() && minHeapIndexes.top() < left)
                minHeapIndexes.pop();

            // next
            ++left;
            minHeapIndexes.push(++right);
        }
    }
}
