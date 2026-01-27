#include<bits/stdc++.h>
using namespace std;
void solve(const int&n)
{
    cout<<n<<'\n';
    if(n==1)return;
    solve(n-1);
    cout<<"-----------------"<<'\n';
    solve(n-1);
}
int main()
{
    solve(4);
    return 0;
}