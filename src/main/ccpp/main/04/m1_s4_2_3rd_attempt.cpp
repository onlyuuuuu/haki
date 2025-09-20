#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i,m1=INT_MAX,m2=INT_MAX;bool b1=false,b2=false;priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>>q;vector<pair<int,bool>>v;multiset<int>out;multiset<int>::iterator outit;
    cin>>M>>N>>K;
    for(;M>0;M--){cin>>i;q.push({i,false});m1=min(m1,i);}
    for(;N>0;N--){cin>>i;q.push({i,true});m2=min(m2,i);}
    v.push_back({m1,false});v.push_back({m2,true});out.insert(m1+m2);
    for (;!q.empty()&&out.size()!=K;q.pop())
    {
        if (!b1&&q.top().first==m1&&q.top().second==false){b1=true;continue;}
        if (!b2&&q.top().first==m2&&q.top().second==true){b2=true;continue;}
        for (const auto& p : v)
        {
            if (out.size()==K)break;
            if (p.second==q.top().second)continue;
            out.insert(p.first+q.top().first);
        }
        v.push_back(q.top());
    }
    for (;!q.empty()&&v[0].first+q.top().first<*out.rbegin();q.pop())
    {
        if (!b1&&q.top().first==m1&&q.top().second==false){b1=true;continue;}
        if (!b2&&q.top().first==m2&&q.top().second==true){b2=true;continue;}
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