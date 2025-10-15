#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool stop;string t,s="";int n,k,i,len,end=INT_MIN;cin>>n;
    map<int,map<int,string,greater<int>>,greater<int>>m;
    map<int,string,greater<int>>::iterator i1,found;
    map<int,map<int,string,greater<int>>,greater<int>>::iterator i2,min;
    while (n--)
    {
        cin>>t>>k>>i;
        len=static_cast<int>(t.length());
        auto&sm=m.try_emplace(len).first->second;
        i1=sm.emplace(i,t).first;
        while (--k)
        {
            cin>>i;
            sm.emplace_hint(i1,i,t);
        }
        end=max(end,i+len);
    }
    n=1;
    for (;;)
    {
        stop=false;
        min=m.begin();
        for (i2=m.begin();i2!=m.end();i2++)
        {
            if (i2->second.rbegin()->first==n)
            {
                stop=true;
                n+=static_cast<int>(i2->second.rbegin()->second.length());
            }
        }
    }
    return 0;
}