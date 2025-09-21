#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i;cin>>M>>N>>K;
    multimap<int,bool>A,B;
    multimap<int,bool>::const_iterator ita,itb;
    vector<int>a,b;a.reserve(M);b.reserve(N);
    unordered_map<bool,vector<int>>m;m.reserve(2);m[false]=a;m[true]=b;
    multiset<int>out;
    for (;M>0;M--){cin>>i;A.insert({i,false});}
    for (;N>0;N--){cin>>i;B.insert({i,true});}
    ita=A.cbegin();itb=B.cbegin();
    m[false].push_back(ita->first);
    m[true].push_back(itb->first);
    out.insert(ita->first+itb->first);
    for (;K>1;K--){out.insert(INT_MAX);}
    ++ita;++itb;
    pair<int,bool>minp={INT_MAX,true};
    M=min(m[false][0],m[true][0]);
    // ----------------------------------------
    for (;ita!=A.cend()||itb!=B.cend();)
    {
        if (ita!=A.cend()&&itb==B.cend()) minp=*ita;
        else if (ita==A.cend()&&itb!=B.cend()) minp=*itb;
        else minp=min(*ita,*itb);
        if (M+minp.first>=*out.crbegin())break;
        for (const auto &x : m[!minp.second])
        {
            i=x+minp.first;
            if (i>=*out.crbegin())break;
            out.erase(--out.end());
            out.insert(i);
        }
        m[minp.second].push_back(minp.first);
        if (!minp.second)++ita;else++itb;
    }
    // ----------------------------------------
    for (auto it=out.cbegin();it!=out.cend();++it){cout<<*it<<endl;}
    return 0;
}