#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b) const
    {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first > b.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;if(n==k){cout<<n<<endl;return 0;}
    vector<pair<int,int>>v;v.reserve(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp>q(comp(),move(v));
    multiset<int,greater<int>>s;multiset<int,greater<int>>::iterator it;
    for (;n>0;n--){cin>>a>>b;q.push({a,b});}
    s.insert(q.top().second);q.pop();++n;
    // ------------------------------
    for (;!q.empty();q.pop())
    {
        it=s.lower_bound(q.top().first);
        if (it==s.end())
        {
            if ((int)s.size()==k) continue;
            s.insert(q.top().second);
            ++n;
            continue;
        }
        s.erase(it);
        s.insert(q.top().second);
        ++n;
    }
    // ------------------------------
    cout<<n<<endl;
    return 0;
}