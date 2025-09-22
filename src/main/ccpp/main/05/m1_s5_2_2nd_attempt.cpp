#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;
    multiset<pair<int,int>,greater<pair<int,int>>>S;multiset<int,greater<int>>o;multiset<pair<int,int>>s;
    for (;n>0;n--){cin>>a>>b;s.insert({a,b});}
    S.insert({s.cbegin()->second, 1});
    // ------------------------------
    for (auto it=++s.cbegin();it!=s.cend();++it)
    {
        a=it->first;b=it->second;
        // pumpkin...
    }
    // ------------------------------
    n=0;for (auto it=o.cbegin();it!=o.cend()&&k>0;k--)n+=*it;cout<<n<<endl;
    return 0;
}