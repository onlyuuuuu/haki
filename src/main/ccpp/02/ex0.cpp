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
    int population;
    int numberOfCommands;
    char command;
    int emergencyPerson;
    deque<int> q;
    stack<int> s;
    int i;
    int nextPerson;
    string result = "";
    int _case = 0;
    while (true)
    {
        cin >> population;
        cin >> numberOfCommands;
        if (population == 0)
        {
            cout << result;
            return 0;
        }
        q.clear();
        result.append("Case " + to_string(++_case) + ":\n");
        population = min(numberOfCommands, population);
        for (i = 1; i <= population; i++)
            q.push_back(i);
        for (i = 1; i <= numberOfCommands; i++)
        {
            cin >> command;
            if (command == 'N')
            {
                nextPerson = q.front();
                result.append(to_string(nextPerson));
                result.append("\n");
                q.pop_front();
                q.push_back(nextPerson);
                continue;
            }
            cin >> emergencyPerson;
            while (!q.empty() && q.front() != emergencyPerson)
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
            q.push_front(emergencyPerson);
        }
    }
}
