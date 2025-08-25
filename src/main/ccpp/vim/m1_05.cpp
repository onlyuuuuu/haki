#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n, N, m, M, a;
    cin >> n;
    cin >> m;
    cin >> a;
    N = n / a;
    if (n % a > 0)
        N++;
    M = m / a;
    if (m % a > 0)
        M++;
    cout << M * N << endl;
    return 0;
}

