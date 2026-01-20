#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,queue<int>>m;
    vector<pair<int,int>>v;
    int n,x,i,ms=0;
    cin>>n>>x;
    if(n<3||x<3)
    {
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    for(int j=1;j<=n;j++)
    {
        cin>>i;
        if(i>x-2)continue;
        auto p = m.try_emplace(i);
        if(!p.second)
        {
            if(p.first->second.size()==3)continue;
            p.first->second.push(j);
            continue;
        }
        queue<int>q;
        q.push(j);
        p.first->second=q;
    }
    v.emplace_back(m.begin()->first,m.begin()->second.front());
    m.begin()->second.pop();
    if(m.begin()->second.empty())
        m.erase(m.begin());
    while(!m.empty())
    {
        pair<int,int>p={m.begin()->first,m.begin()->second.front()};
        m.begin()->second.pop();
        if(m.begin()->second.empty())
            m.erase(m.begin());
        if(m.empty())continue;
        int diff=ms-p.first;
        auto vit=v.begin();
        if(diff < v.front().first)
            vit=v.begin();
        else if(diff == v.front().first)
            vit=v.begin()+1;
        else
            vit=std::upper_bound(v.begin(),v.end(),std::make_pair(diff,0));
        for(;vit!=v.end();vit++)
        {
            ms=vit->first+p.first;
            int lookup=x-ms;
            if(lookup == m.begin()->first)
            {
                cout<<vit->second<<' '<<p.second<<' '<<m.begin()->second.front()<<'\n';
                return 0;
            }
            if(lookup == std::prev(m.end())->first)
            {
                cout<<vit->second<<' '<<p.second<<' '<<std::prev(m.end())->second.front()<<'\n';
                return 0;
            }
            if(lookup > m.begin()->first && lookup < std::prev(m.end())->first)
            {
                auto mit=m.find(lookup);
                if(mit!=m.end())
                {
                    cout<<vit->second<<' '<<p.second<<' '<<mit->second.front()<<'\n';
                    return 0;
                }
            }
        }
        if(p.first == v.back().first)continue;
        v.push_back(p);
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return 0;
}
