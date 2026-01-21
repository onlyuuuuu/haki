#include<bits/stdc++.h>
using namespace std;
static void drop(map<int,queue<int>>&m)
{
    m.begin()->second.pop();
    if(m.begin()->second.empty()||INT_MIN==m.begin()->second.front())
        m.erase(m.begin());
}
static pair<int,int> poll(map<int,queue<int>>&m)
{
    pair<int,int>p={m.begin()->first,m.begin()->second.front()};
    drop(m);
    return p;
}
static void move(map<int,queue<int>>&m,vector<pair<int,int>>&v)
{
    if(v.back().first==m.begin()->first)
    {
        drop(m);
        return;
    }
    v.emplace_back(m.begin()->first,m.begin()->second.front());
    drop(m);
}
static void move(const pair<int,int>&p,vector<pair<int,int>>&v)
{
    if(p.first==v.back().first) return;
    v.emplace_back(p.first,p.second);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,queue<int>>m;
    vector<pair<int,int>>v;
    int n,x,i,s=0;
    cin>>n>>x;
    if(n<3||x<3)
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    for(int pos=1;pos<=n;pos++)
    {
        cin>>i;
        if(i>x-2)continue;
        auto p = m.try_emplace(i);
        if(p.second)
        {
            queue<int>q;
            q.push(pos);
            p.first->second=q;
            continue;
        }
        if(INT_MIN==p.first->second.back())continue;
        if(2==p.first->second.size())
        {
            cout<<p.first->second.front()<<' '<<p.first->second.back()<<' '<<pos<<'\n';
            return 0;
        }
        if(2*p.first->first>=x)
        {
            p.first->second.push(INT_MIN);
            continue;
        }
        if(3*p.first->first==x)
        {
            p.first->second.push(pos);
            continue;
        }
        p.first->second.push(pos);
        p.first->second.push(INT_MIN);
    }
    if(m.empty())
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    move(m,v);
    s=v.front().first;
    while(!m.empty() && x-(v.back().first+m.begin()->first) > std::prev(m.end())->first)
    {
        s=v.back().first+m.begin()->first;
        move(m,v);
    }
    if(!m.empty() && s + std::prev(m.end())->first == x)
    {
        cout<<v.back().second<<' '<<v[v.size()-2].second<<' '<<std::prev(m.end())->second.front()<<'\n';
        return 0;
    }
    while(!m.empty())
    {
        pair<int,int>p=poll(m);
        auto vit=v.begin();
        
        if(m.empty())
        {
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
        
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
