#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i,m1=INT_MAX,m2=INT_MAX,_min;bool b1=false,b2=false;priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>>q;unordered_map<bool,vector<int>>m;vector<int>va,vb;multiset<int>out;multiset<int>::iterator outit;
    cin>>M>>N>>K;for(;M>0;M--){cin>>i;q.push({i,false});m1=min(m1,i);}for(;N>0;N--){cin>>i;q.push({i,true});m2=min(m2,i);}
    va.push_back(m1);vb.push_back(m2);m[false]=va;m[true]=vb;out.insert(m1+m2);
    for (;(int)out.size()!=K;q.pop())
    {
        if (!b1&&q.top().first==m1&&!q.top().second){b1=true;continue;}
        if (!b2&&q.top().first==m2&&q.top().second){b2=true;continue;}
        for (const auto& p : m[!q.top().second])
        {
            if ((int)out.size()==K)break;
            out.insert(p+q.top().first);
        }
        m[q.top().second].push_back(q.top().first);
    }
    for (_min=min(m1,m2);!q.empty()&&_min+q.top().first<*out.crbegin();q.pop())
    {
        if (!b1&&q.top().first==m1&&!q.top().second){b1=true;continue;}
        if (!b2&&q.top().first==m2&&q.top().second){b2=true;continue;}
        for (const auto& p : m[!q.top().second])
        {
            i=p+q.top().first;
            if (i>=*out.crbegin())break;
            out.erase(--out.end());
            out.insert(i);
        }
        m[q.top().second].push_back(q.top().first);
    }
    for (outit=out.begin();outit!=out.end();++outit)cout<<*outit<<endl;
    return 0;
}