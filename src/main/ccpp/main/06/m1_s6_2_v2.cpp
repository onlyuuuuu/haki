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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,queue<int>>m;
    vector<pair<int,int>>v;
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
        if(e.first->second.size()==1 && 2*e.first->first >= x)continue;
        if(e.first->second.size()==1)
        {
            e.first->second.push(p);
            continue;
        }
        if(e.first->second.size()==2 && 3*e.first->first != x)continue;
        cout<<e.first->second.front()<<' '<<e.first->second.back()<<' '<<p<<'\n';
        return 0;
    }
    if(m.empty())
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    v.push_back(poll(m));
    if(m.empty())
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    auto end=std::prev(m.end());
    while(!m.empty())
    {
        auto p=poll(m);
        if(m.empty())
        {
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
        i = x - ( v.back().first + p.first );
        if( i == end->first )
        {
            cout<<v.back().second<<' '<<p.second<<' '<<end->second.front()<<'\n';
            return 0;
        }
        if( i > end->first )
        {
            v.push_back(p);
            continue;
        }
        i = x - ( p.first + end->first );
        if(i == v.front().first)
        {
            cout<<v.front().second<<' '<<p.second<<' '<<end->second.front()<<'\n';
            return 0;
        }
        if(i == v.back().first)
        {
            cout<<v.back().second<<' '<<p.second<<' '<<end->second.front()<<'\n';
            return 0;
        }
        auto it=v.end();
        if(i < v.front().first)     it=v.begin();
        else if(i > v.back().first) it=v.end();
        else                        it=std::lower_bound(v.begin(),v.end(),std::make_pair(i,0));
        for(;it!=v.end();it++)
        {
            i = x - ( it->first + p.first );
            if(i == m.begin()->first)
            {
                cout<<it->second<<' '<<p.second<<' '<<m.begin()->second.front()<<'\n';
                return 0;
            }
            if(i == end->first)
            {
                cout<<it->second<<' '<<p.second<<' '<<end->second.front()<<'\n';
                return 0;
            }
            if(i < m.begin()->first)break;
            auto f=m.find(i);
            if(f==m.end())continue;
            cout<<it->second<<' '<<p.second<<' '<<f->second.front()<<'\n';
            return 0;
        }
        v.push_back(p);
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
