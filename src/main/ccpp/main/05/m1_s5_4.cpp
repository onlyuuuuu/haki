#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    map<pair<int,int>,string>m;map<pair<int,int>,string>::iterator it;
    string s;int k,x;
    for (;n>0;n--)
    {
        cin>>s>>k;
        for (;k>0;k--)
        {
            cin>>x;
            m[{x+s.size()-1,x}]=s;
        }
    }
    int next_req_from=1;int start,end;
    for (it=m.begin();it!=m.end();it=m.lower_bound({next_req_from,0}))
    {
        start=it->first.second;
        end=it->first.first;
        if (start>next_req_from)
        {
            cout<<s.assign(start-next_req_from,'a');
            cout<<it->second;
            next_req_from=it->first.first+1;
            continue;
        }
        if (start<next_req_from)
        {
            cout<<it->second.substr(next_req_from-start);
            next_req_from=it->first.first+1;
            continue;
        }
        cout<<it->second;
        next_req_from=it->first.first+1;
    }
    return 0;
}