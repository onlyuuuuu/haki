#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i,minAB,temp;pair<int,bool>minp;multimap<int,bool>ma,mb;multimap<int,bool>::iterator mait,mbit;
    unordered_map<bool,vector<int>>mab;multiset<int>out;multiset<int>::iterator outit;
    cin>>M>>N>>K;for(;M>0;M--){cin>>i;ma.insert({i,false});}for(;N>0;N--){cin>>i;mb.insert({i,true});}
    minAB=min(ma.begin()->first,mb.begin()->first);out.insert(ma.begin()->first+mb.begin()->first);cout<<*out.begin()<<endl;
    vector<int>va(M),vb(N);va.push_back(ma.begin()->first);vb.push_back(mb.begin()->first);mab[false]=va;mab[true]=vb;mait=++ma.begin();mbit=++mb.begin();
    for (minp=min(*mait,*mbit);mait!=ma.end()&&mbit!=mb.end()&&out.size()!=K;minp=min(*mait,*mbit))
    {
        for (const auto& e : mab[!minp.second])
        {
            if (out.size()==K)break;
            out.insert(e+minp.first);
        }
        mab[minp.second].push_back(minp.first);
        if (!minp.second) ++mait; else ++mbit;
    }
    for (;mait!=ma.end()&&out.size()!=K;++mait)
    {
        for (const auto& e : mab[true])
        {
            if (out.size()==K)break;
            out.insert(e+mait->first);
        }
        mab[false].push_back(mait->first);
    }
    for (;mbit!=mb.end()&&out.size()!=K;++mbit)
    {
        for (const auto& e : mab[false])
        {
            if (out.size()==K)break;
            out.insert(e+mbit->first);
        }
        mab[true].push_back(mbit->first);
    }
    for (minp=min(*mait,*mbit);minAB+minp.first<*out.rbegin();minp=min(*mait,*mbit))
    {
        for (const auto& e : mab[!minp.second])
        {
            temp=e+minp.first;
            if (temp>=*out.rbegin())break;
            out.erase(--out.end());
            out.insert(temp);
        }
        mab[minp.second].push_back(minp.first);
        if (!minp.second) ++mait; else ++mbit;
    }
    for (outit=++out.begin();outit!=out.end();++outit)cout<<*outit<<endl;
    return 0;
}