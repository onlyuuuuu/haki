#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;double m=0;int d,x,n;cin>>n;
    multiset<int>t1,t2;t1.insert(INT_MIN);t2.insert(INT_MAX);
    for (;n>0;n--)
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
            if (x<=*t1.begin()) t1.insert(t1.begin(),x);
            else if (x>=*t2.rbegin()) t2.insert(--t2.end(),x);
            else
            {
                if (x<=m) t1.insert(--t1.end(),x);
                else t2.insert(t2.begin(),x);
            }
        }
        else
        {
            if (x>*t1.rbegin()) t2.erase(t2.find(x));
            else t1.erase(t1.find(x));
        }
        d=static_cast<int>(t1.size())-static_cast<int>(t2.size());
        if (d==2)
        {
            t2.insert(t2.begin(),*t1.rbegin());
            t1.erase(--t1.end());
        }
        if (d==-2)
        {
            t1.insert(--t1.end(),*t2.begin());
            t2.erase(t2.begin());
        }
        if (t1.size()>t2.size()) m=*t1.rbegin();
        else if (t1.size()<t2.size()) m=*t2.begin();
        else m=static_cast<double>(*t1.rbegin()+*t2.begin())/2.0;
    }
    return 0;
}