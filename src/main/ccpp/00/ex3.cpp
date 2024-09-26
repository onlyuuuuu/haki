#include <bits/stdc++.h>

using namespace std;

int main()
{
	int numberOfCells;
	cin >> numberOfCells;
	int destination;
	cin >> destination;
	int path;
	int journey = 1;
	for (int i = 1; i < numberOfCells; i++)
	{
		cin >> path;
		if (journey > destination)
		{
			cout << "NO" << endl;
			return 0;
		}
		if (journey == destination)
		{
			cout << "YES" << endl;
			return 0;
		}
		if (journey == i)
			journey += path;
	}
	if (journey > destination || journey < destination)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}