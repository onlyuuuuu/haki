#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t,s;int n,k,i,len,end=INT_MIN;cin>>n;
    map<int,map<int,string,greater<int>>,greater<int>>m;
    map<int,map<int,string,greater<int>>,greater<int>>::iterator it;
    map<int,string,greater<int>>::iterator h;
    while (n--)
    {
        cin>>t>>k>>i;
        len=static_cast<int>(t.length());
        auto&sm=m.try_emplace(len).first->second;
        h=sm.emplace(i,t).first;
        while (--k)
        {
            cin>>i;
            sm.emplace_hint(h,i,t);
        }
        end=max(end,i+len);
    }
    return 0;
}