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
        if (i>=x) continue;
        m.emplace(i,j);
    }
    for (auto it=m.begin();m.end()!=it;it=m.erase(it))
    {
        auto f=m.find(x-(it->first));
        if(m.end()==f) continue;
        cout<<it->second<<' '<<f->second;
        return 0;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
