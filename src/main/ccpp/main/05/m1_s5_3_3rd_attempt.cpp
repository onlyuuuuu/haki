#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;double m;int d,x,n;cin>>n;
    multiset<int>t1,t2;
    cin>>s>>x;t1.insert(x);m=x;
    for (;n>1;n--)
    {
        cin>>s;if (s=="MEDIAN"){cout<<m<<endl;continue;}cin>>x;
        if (s=="IN")
        {
            if (x<=m)
            {
                if (t1.empty()) t1.insert(x);
                else t1.insert(--t1.end(),x);
            }
            else
            {
                if (t2.empty()) t2.insert(x);
                else t2.insert(t2.begin(),x);
            }
        }
        else
        {
            if (x<=*t1.rbegin()) t1.erase(t1.find(x));
            else t2.erase(t2.find(x));
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
        else m=static_cast<double>(*t1.rbegin()+*t2.begin())/2;
    }
    return 0;
}