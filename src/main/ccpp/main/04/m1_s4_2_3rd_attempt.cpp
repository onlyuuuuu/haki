#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i;priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>>q;vector<pair<int,bool>>v;
    multiset<int>out;multiset<int>::iterator outit;
    cin>>M>>N>>K;for(;M>0;M--){cin>>i;q.push({i,false});}for(;N>0;N--){cin>>i;q.push({i,true});}
    v.push_back(q.top());q.pop();
    for (;out.size()!=K;q.pop())
    {
        for (const auto& p : v)
        {
            if (out.size()==K)break;
            if (p.second==q.top().second)continue;
            out.insert(p.first+q.top().first);
        }
        v.push_back(q.top());
    }
    for (;v[0].first+q.top().first<*out.rbegin();q.pop())
    {
        for (const auto& p : v)
        {
            i = p.first+q.top().first;
            if (i>=K)break;
            if (p.second==q.top().second)continue;
            out.erase(--out.end());
            out.insert(i);
        }
        v.push_back(q.top());
    }
    for (outit=out.begin();outit!=out.end();++outit)cout<<*outit<<endl;
    return 0;
}