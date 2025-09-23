#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;if(n==k){cout<<n<<endl;return 0;}
    vector<pair<int,int>>v;v.reserve(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q(greater<pair<int,int>>(),move(v));
    multiset<int,greater<int>>s;multiset<int,greater<int>>::iterator it;
    for (;n>0;n--){cin>>a>>b;q.push({b,a});}
    s.insert(q.top().first);q.pop();++n;
    // ------------------------------
    for (;!q.empty();q.pop())
    {
        it=s.lower_bound(q.top().second);
        if (it==s.end())
        {
            if ((int)s.size()==k) continue;
            s.insert(q.top().first);
            ++n;
            continue;
        }
        s.erase(it);
        s.insert(q.top().first);
        ++n;
    }
    // ------------------------------
    cout<<n<<endl;
    return 0;
}