#include<bits/stdc++.h>
using namespace std;
void solve(const int&n)
{
    if(n==1)return;
    solve(n-1);
    solve(n-1);
}
int main()
{
    solve(8);
    return 0;
}