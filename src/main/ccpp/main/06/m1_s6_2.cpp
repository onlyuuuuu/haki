#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int>s;
    int n,x,i;
    cin>>n>>x;
    while(n--)
    {
        cin>>i;
        if(i>=x-1)continue;
        s.emplace(i);
    }
    
    return 0;
}
