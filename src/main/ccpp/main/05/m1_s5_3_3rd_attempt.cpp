#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;double m=0;int x,n;cin>>n;
    multiset<int,greater<>>t1;
    multiset<int>t2;
    for (;n>1;n--)
    {
        cin>>s;
        if (s=="MEDIAN")
        {
            cout<<m<<endl;
            continue;
        }
        cin>>x;
        if (s=="IN")
        {

        }
        else
        {

        }
    }
    return 0;
}