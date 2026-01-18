#include <bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,int>m;
    int n,x,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>j;
        if(j>=x-1)continue;
        m.emplace(j,i);
    }
    while(m.size()>2)
    {
        pair<int,int>a={m.begin()->first,m.begin()->second};
        auto bit=m.erase(m.begin());
        pair<int,int>b={bit->first,bit->second};
        
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
