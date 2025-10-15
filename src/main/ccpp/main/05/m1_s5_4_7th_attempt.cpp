#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t,s;int n,k,i;cin>>n;
    map<int,map<int,string,greater<int>>,greater<int>>m;
    map<int,map<int,string,greater<int>>,greater<int>>::iterator it;
    map<int,string,greater<int>>::iterator h;
    while (n--)
    {
        cin>>t>>k>>i;
        auto&sm=m.try_emplace(static_cast<int>(t.length()),map<int,string,greater<int>>()).first->second;
        h=sm.emplace(i,t).first;
        while (--k)
        {
            cin>>i;
            sm.emplace_hint(h,i,t);
        }
    }
    return 0;
}