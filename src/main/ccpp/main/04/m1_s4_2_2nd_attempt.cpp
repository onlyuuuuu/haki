#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,a,b;vector<int>va,vb;multiset<int>sa,sb,sout;multiset<int>::iterator ita,itb,itout;
    cin>>M>>N>>K;
    for (;M>0;M--){cin>>a;sa.insert(a);}
    for (;N>0;N--){cin>>b;sb.insert(b);}
    cout<<*sa.begin()+*sb.begin()<<endl;

    return 0;
}