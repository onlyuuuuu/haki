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
    map<int,queue<int>>t;
    pair<int,int>r={0,0};
    auto h=t.begin();
    while(!m.empty())
    {
        if(m.begin()->second.size()>1 && 2*m.begin()->first==s)
        {
            r.first=m.begin()->second.front();
            r.second=m.begin()->second.back();
            return r;
        }
        h=t.emplace_hint(h,m.begin()->first,m.begin()->second);
        m.erase(m.begin());
        if(m.empty())return r;
        int l = s - std::prev(t.end())->first;
        if(l < m.begin()->first || l > std::prev(m.end())->first)continue;
        if(l == m.begin()->first)
        {
            r.first=std::prev(t.end())->second.front();
            r.second=m.begin()->second.front();
            return r;
        }
        if(l == std::prev(m.end())->first)
        {
            r.first=std::prev(t.end())->second.front();
            r.second=std::prev(m.end())->second.front();
            return r;
        }
        auto f=m.find(l);
        if(f==m.end())continue;
        r.first=std::prev(t.end())->second.front();
        r.second=f->second.front();
        return r;
    }
    if(!t.empty())m.swap(t);
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
        if(m.empty() || m.begin()->second.size()==1)
        {
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
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
