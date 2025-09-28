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
            if (x<=m)
            {
                if (x<=*t1.crbegin()) t1.insert(--t1.end(),x);
                else if (x>=*t1.cbegin()) t1.insert(t1.begin(),x);
                else t1.insert(x);

            }
            else
            {
                if (x>=*t2.crbegin()) t2.insert(--t2.end(),x);
                else if (x<=*t2.cbegin()) t2.insert(t2.begin(),x);
                else t2.insert(x);

            }

        }
        else
        {

        }
    }
    return 0;
}