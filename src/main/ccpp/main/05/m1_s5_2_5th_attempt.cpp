#include <bits/stdc++.h>
using namespace std;
struct comp
{
    bool operator()(const pair<int,int>& a,const pair<int,int>& b) const
    {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first > b.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,a,b;cin>>n>>k;if (n==k)cout<<n<<endl;return 0;
    vector<pair<int,int>> v;v.reserve(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q(comp(),move(v));
    multimap<int,int>m;
    for (;n>0;n--){cin>>a>>b;q.push({a,b});}
    // ------------------------------

    // ------------------------------
    cout<<n<<endl;
    return 0;
}