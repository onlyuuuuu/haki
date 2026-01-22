#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>m;
    int n,x,i;
    cin>>n>>x;
    if(n<2||x<2)
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    for(int p=1;p<=n;p++)
    {
        cin>>i;
        if(i>=x)continue;
        auto e=m.try_emplace(i,p);
        if(e.second || i+e.first->first!=x)continue;
        cout<<e.first->second<<' '<<p<<'\n';
        return 0;
    }
    while(!m.empty())
    {
        pair<int,int>p={m.begin()->first,m.begin()->second};
        m.erase(m.begin());
        if(m.empty())
        {
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
        n=x-p.first;
        if(n < m.begin()->first || n > std::prev(m.end())->first)continue;
        if(n == m.begin()->first)
        {
            cout<<p.second<<' '<<m.begin()->second<<'\n';
            return 0;
        }
        if(n == std::prev(m.end())->first)
        {
            cout<<p.second<<' '<<std::prev(m.end())->second<<'\n';
            return 0;
        }
        auto f=m.find(x-p.first);
        if(f==m.end())continue;
        cout<<p.second<<' '<<f->second<<'\n';
        return 0;
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
