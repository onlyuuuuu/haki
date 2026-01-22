#include<bits/stdc++.h>
using namespace std;
static void drop(map<int,queue<int>>&m)
{
    m.begin()->second.pop();
    if(m.begin()->second.empty())
        m.erase(m.begin());
}
static pair<int,int> poll(map<int,queue<int>>&m)
{
    pair<int,int>p={m.begin()->first,m.begin()->second.front()};
    drop(m);
    return p;
}
static pair<int,int> sum_of_two(map<int,queue<int>>&m,const int&s)
{
    pair<int,int> r={0,0};
    if()
    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,queue<int>>m;
    int n,x,i;
    cin>>n>>x;
    if(n<3||x<3)
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    for(int p=1;p<=n;p++)
    {
        cin>>i;
        if(i>=x-1)continue;
        auto e=m.try_emplace(i);
        if(e.second)
        {
            queue<int>q;
            q.push(p);
            e.first->second=q;
            continue;
        }
        if(e.first->second.size()==1 && e.first->first + i >= x)continue;
        if(e.first->second.size()==1)
        {
            e.first->second.push(p);
            continue;
        }
        if(e.first->second.size()==2 && 3*e.first->first != x)continue;
        cout<<e.first->second.front()<<' '<<e.first->second.back()<<' '<<p<<'\n';
        return 0;
    }
    while(!m.empty())
    {
        auto p=poll(m);
        auto r=sum_of_two(m,x-p.first);
        if(r.first!=0)
        {
            cout<<p.second<<' '<<r.first<<' '<<r.second<<'\n';
            return 0;
        }
        if(!m.empty() && m.begin()->first == p.first)
            m.erase(m.begin());
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
