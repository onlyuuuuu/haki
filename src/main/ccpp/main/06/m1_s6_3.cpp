#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int>m;
    int n;string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        auto p = m.try_emplace(s,0);
        if(!p.second)
        {
            p.first->second++;
            cout<<p.first->first<<p.first->second<<'\n';
            continue;
        }
        cout<<"OK"<<'\n';
    }
    return 0;
}