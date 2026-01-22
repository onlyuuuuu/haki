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
        auto e=m.try_emplace(i);
        if(e.second)
        {
            queue<int>q;
            q.push(p);
            e.first->second=q;
            continue;
        }
        if(i+e.first->first!=x)continue;
        cout<<e.first->second.front()<<' '<<p<<'\n';
        return 0;
    }
    while(!m.empty())
    {
        auto p=poll(m);
        if(m.empty())
        {
            cout<<"IMPOSSIBLE"<<'\n';
            return 0;
        }
        n=x-p.first;
        if(n < m.begin()->first || n > std::prev(m.end())->first)
        {
            if(m.begin()->first == p.first)
                m.erase(m.begin());
            continue;
        }
        if(n == m.begin()->first)
        {
            cout<<p.second<<' '<<m.begin()->second.front()<<'\n';
            return 0;
        }
        if(n == std::prev(m.end())->first)
        {
            cout<<p.second<<' '<<std::prev(m.end())->second.front()<<'\n';
            return 0;
        }
        auto f=m.find(x-p.first);
        if(f==m.end())
        {
            if(m.begin()->first == p.first)
                m.erase(m.begin());
            continue;
        }
        cout<<p.second<<' '<<f->second.front()<<'\n';
        return 0;
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
