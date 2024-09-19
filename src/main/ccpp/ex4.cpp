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
	long long n;
	cin >> n;
	long long m;
	cin >> m;
	long long a;
	cin >> a;
	long long side1 = min((int)(n % a), 1) + (n / a);
	long long side2 = min((int)(m % a), 1) + (m / a);
	cout << side1 * side2 << endl;

	/*
	signed char			8	-128					127
	unsigned char		8	0						255
	char				8	(see below)				(see below)
	signed short		16	-32768					32767
	unsigned short		16	0						65535
	signed int			16	-32768					32767
	unsigned int		16	0						65535
	signed long			32	-2147483648				2147483647
	unsigned long		32	0						4294967295
	signed long long	64	-9223372036854775808	9223372036854775807
	unsigned long long	64	0						18446744073709551615
	*/
}