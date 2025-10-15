#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t,s="";int n,k,i,len,end=INT_MIN;cin>>n;
    map<int,map<int,string,greater<int>>,greater<int>>m;
    map<int,string,greater<int>>::iterator it;
    while (n--)
    {
        cin>>t>>k>>i;
        len=static_cast<int>(t.length());
        auto&sm=m.try_emplace(len).first->second;
        it=sm.emplace(i,t).first;
        while (--k)
        {
            cin>>i;
            sm.emplace_hint(it,i,t);
        }
        end=max(end,i+len);
    }
    len=end-1;
    for (n=1;static_cast<int>(s.length()) != len;)
    {

    }
    return 0;
}