#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M,N,K,a,b;vector<int>va,vb;multiset<int>sa,sb,out;multiset<int>::iterator ita,itb,itout;
    cin>>M>>N>>K;
    for (;M>0;M--){cin>>a;sa.insert(a);}
    for (;N>0;N--){cin>>b;sb.insert(b);}
    ita=sa.begin();va.push_back(*ita);ita++;
    itb=sb.begin();vb.push_back(*itb);itb++;
    while (ita!=sa.end()&&itb!=sb.end())
    {
        if (*ita >= *itb)
        {
            va.push_back(*ita);
            ita++;
        }
        else
        {
            vb.push_back(*itb);
            itb++;
        }
        if ((int)va.size()*(int)vb.size() > K)break;
    }
    while (ita!=sa.end()&&itb!=sb.end())
    return 0;
}