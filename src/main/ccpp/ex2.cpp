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
	int weight;
	cin >> weight;
	if (weight <= 2)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (weight % 2 == 0)
	{
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
}