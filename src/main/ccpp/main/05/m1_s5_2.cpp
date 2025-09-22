#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;
    multiset<pair<int,int>>s;multiset<pair<int,int>>::iterator it;
    for (;n>0;n--){cin>>a>>b;s.insert({b,a});}
    // ------------------------------
    for (;!s.empty()&&k>0;k--)
    {
        for (it=s.begin();it!=s.end();)
        {
            ++n;a=it->second;b=it->first;s.erase(it);
            for (it=s.lower_bound({b+1,b});it!=s.end()&&it->second<b;++it){}
        }
    }
    // ------------------------------
    cout<<n<<endl;
    return 0;
}