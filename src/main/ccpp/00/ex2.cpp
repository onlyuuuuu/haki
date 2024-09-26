#include <bits/stdc++.h>

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