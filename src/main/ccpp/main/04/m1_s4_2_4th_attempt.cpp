#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i;cin>>M>>N>>K;
    vector<pair<int,bool>>A,B;A.reserve(M);B.reserve(N);
    priority_queue qa(greater<pair<int,bool>>(),move(A)),qb(greater<pair<int,bool>>(),move(B));
    vector<int>a,b;a.reserve(M);b.reserve(N);
    unordered_map<bool,vector<int>>m;m.reserve(2);m[false]=a;m[true]=b;
    multiset<int>out;multiset<int>::iterator it;
    for (;M>0;M--){cin>>i;qa.push({i,false});}
    for (;N>0;N--){cin>>i;qb.push({i,true});}
    m[false].push_back(qa.top().first);
    m[true].push_back(qb.top().first);
    out.insert(qa.top().first+qb.top().first);
    qa.pop();qb.pop();
    for (;K>1;K--){out.insert(INT_MAX);}
    pair<int,bool>minp={INT_MAX,true};
    M=min(m[false][0],m[true][0]);
    // ----------------------------------------
    for (;!qa.empty()&&!qb.empty();)
    {
        minp=min(qa.top(),qb.top());
        if (M+minp.first>=*out.crbegin())break;
        for (const auto& x : m[!minp.second])
        {
            i=x+minp.first;
            if (i>=*out.crbegin())break;
            out.erase(--out.end());
            out.insert(i);
        }
        m[minp.second].push_back(minp.first);
        if (!minp.second)qa.pop();else qb.pop();
    }
    for (;!qa.empty();qa.pop())
    {
        minp=qa.top();
        if (M+minp.first>=*out.crbegin())break;
        for (const auto& b : m[true])
        {
            i=b+minp.first;
            if (i>=*out.crbegin())break;
            out.erase(--out.end());
            out.insert(i);
        }
        m[false].push_back(minp.first);
    }
    for (;!qb.empty();qb.pop())
    {
        minp=qb.top();
        if (M+minp.first>=*out.crbegin())break;
        for (const auto& a : m[false])
        {
            i=a+minp.first;
            if (i>=*out.crbegin())break;
            out.erase(--out.end());
            out.insert(i);
        }
        m[true].push_back(minp.first);
    }
    // ----------------------------------------
    for (it=out.cbegin();it!=out.cend();++it){cout<<*it<<endl;}
    return 0;
}