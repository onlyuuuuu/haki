#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool do_insert;string t,temp;int n,k,s,e;cin>>n;
    map<int,pair<int,string>>m;
    map<int,pair<int,string>>::iterator it,fr,to;
    while (n--)
    {
        cin>>t>>k;
        while (k--)
        {
            cin>>s;
            e=s+static_cast<int>(t.length());
            it=m.lower_bound(s);
            if (it==m.end()||it->second.first>e)
            {
                m.emplace(piecewise_construct,forward_as_tuple(e),forward_as_tuple(s,t));
                continue;
            }
            if (it->second.first<=s&&it->first>=e) continue;
            if (it->second.first<=e&&it->first>e)
            {
                it->second.second=t.substr(0,it->second.first-s)+it->second.second;
                it->second.first=s;
                continue;
            }
            do_insert=true;
            temp=t;
            if (it->second.first<s)
            {
                temp=it->second.second.substr(0,s-it->second.first)+temp;
                s=it->second.first;
            }
            fr=it;
            to=m.upper_bound(e);
            if (to!=m.end()&&to->second.first>s&&to->second.first<=e)
            {
                to->second.second=temp.substr(0,to->second.first-s)+to->second.second;
                to->second.first=s;
                do_insert=false;
            }
            m.erase(fr,to);
            if (do_insert) m.emplace(piecewise_construct,forward_as_tuple(e),forward_as_tuple(s,temp));
        }
    }
    n=1;
    for (it=m.begin();it!=m.end();it++)
    {
        k=it->second.first-n;
        while (k--) cout<<char_a;
        cout<<it->second.second;
    }
    return 0;
}