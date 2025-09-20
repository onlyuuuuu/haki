#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,i,val;map<long long, long long, greater<long long>>m;
    cin>>n;for (i=1;i<=n;i++){cin>>val;m[val]=i;}
    n=INT_MAX;auto pre=m.cbegin();
    for (auto cur=++m.cbegin();cur!=m.cend();++cur)
    {
        if (pre->second > cur->second){++pre;continue;}
        n=min(n,pre->first-cur->first);++pre;
    }
    cout<<n<<endl;
    return 0;
}