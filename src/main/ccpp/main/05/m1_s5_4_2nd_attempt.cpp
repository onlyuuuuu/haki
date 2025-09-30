#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;int k,x,n;cin>>n;
    map<pair<int,int>,string>m;
    map<pair<int,int>,string>::iterator it;
    for (;n>0;n--)
    {
        cin>>s>>k;
        for (;k>0;k--)
        {
            cin>>x;
            m[{x+s.size()-1,x}]=s;
        }
    }
    n=1;for (it=m.begin();it!=m.end();it=m.lower_bound({n,0}))
    {
        k=it->first.second;
        x=it->first.first;
        if (k>n) {cout<<s.assign(k-n,'a');cout<<it->second;}
        else if (k<n) cout<<it->second.substr(n-k);
        else cout<<it->second;
        n=x+1;
    }
    return 0;
}