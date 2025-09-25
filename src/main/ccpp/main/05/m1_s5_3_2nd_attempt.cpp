#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;string s;int i;cin>>s>>i;int m = i;
    for (;n>1;n--)
    {
        cin>>s;
        if (s=="MEDIAN")
        {
            cout<<m<<endl;
            continue;
        }
        cin>>i;
    }
    return 0;
}