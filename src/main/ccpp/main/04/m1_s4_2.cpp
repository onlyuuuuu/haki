#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,m,n;multiset<int>s1,s2;priority_queue<int,vector<int>,greater<int>>q;multiset<int>::iterator it1,it2;
    cin>>M>>N>>K;
    for (;M>=1;M--){cin>>m;s1.emplace(m);};
    for (;N>=1;N--){cin>>n;s2.emplace(n);};
    int i,j; i = 0;
    for (it1 = s1.begin(); it1 != s1.end() && i < K/2; it1++)
    {
        j = 0;
        for (it2 = s2.begin(); it2 != s2.end() && j < K/2; it2++)
        {
            q.push(*it1 + *it2);
            j++;
        }
        i++;
    }
    for (;K>=1;K--){cout<<q.top()<<endl;q.pop();}
    return 0;
}