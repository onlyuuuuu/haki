#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b) const
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;
    multiset<pair<int,int>,comp>s;multiset<pair<int,int>,comp>::iterator it;pair<int,int>p;
    for (;n>0;n--){cin>>a>>b;s.insert({b,a});}
    // ------------------------------
    for (;!s.empty()&&k>0;k--)
    {
        it=s.begin();a=it->second;b=it->first;s.erase(it);p.first=b+1;p.second==b;++n;
        for (;true;)
        {
            for (it=s.lower_bound(p);it!=s.end()&&it->second<b;)
            {
                p.first=it->first;
                it=s.lower_bound(p);
            }
            if (it==s.end()) break;
            a=it->second;b=it->first;s.erase(it);p.first=b+1;p.second==b;++n;
        }
    }
    // ------------------------------
    cout<<n<<endl;
    return 0;
}