#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;if(n==k){cout<<n<<endl;return 0;}
    multiset<pair<int,int>>i;
    multiset<int,greater<int>>s;multiset<int,greater<int>>::iterator f;
    for (;n>0;n--){cin>>a>>b;i.insert({b,a});}
    multiset<pair<int,int>>::iterator c=i.begin();
    s.insert(c->first);++c;++n;
    // ------------------------------
    for (;c!=i.end();++c)
    {
        f=s.lower_bound(c->second);
        if (f==s.end())
        {
            if ((int)s.size()==k) continue;
            s.insert(c->first);
            ++n;
            continue;
        }
        s.erase(f);
        s.insert(c->first);
        ++n;
    }
    // ------------------------------
    cout<<n<<endl;
    return 0;
}