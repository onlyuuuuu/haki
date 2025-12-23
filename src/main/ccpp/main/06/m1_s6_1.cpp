#include <bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,int,greater<int>>m;
    int n,x,i;
    cin>>n>>x;
    for(int j=1;j<=n;j++)
    {
        cin>>i;
        m.emplace(i,j);
    }
    auto f=m.upper_bound(x);
    while (m.end()!=f)
    {
        auto f2=m.find(x-f->first);
        if(m.end()!=f2)
        {
            cout<<f->first<<" "<<f2->first;
            return 0;
        }
        f=m.erase(f);
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
