#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i,s1,s2;priority_queue<int,vector<int>,greater<int>>qa,qb;vector<int>vfa,vfb;
    cin>>M>>N>>K;
    cin>>i;vfb.push_back(i);M--;
    for (;M>0;M--){cin>>i;qa.push(i);};
    cin>>i;vfa.push_back(i);N--;
    for (;N>0;N--){cin>>i;qb.push(i);};
    cout<<vfa[0]+vfb[0]<<endl;
    while (!qa.empty()&&!qb.empty())
    {
        
    }
    return 0;
}