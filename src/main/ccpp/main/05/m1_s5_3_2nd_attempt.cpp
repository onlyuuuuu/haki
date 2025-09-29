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
            if (t1.empty()&&t2.empty())
            {
                t1.insert(x);
                m=x;
                continue;
            }
            if (x<=m)
            {
                if (t1.empty())
                {
                    t1.insert(x);
                    m=(*t1.begin()+*t2.begin())/2;
                    continue;
                }
                if (x<=*t1.rbegin()) t1.insert(--t1.end(),x);
                else if (x>=*t1.begin()) t1.insert(t1.begin(),x);
                else t1.insert(x);
                if ((int)t1.size()-(int)t2.size()==2)
                {
                    t2.insert(t2.begin(),*t1.begin());
                    t1.erase(t1.begin());
                }
                else if ((int)t1.size()-(int)t2.size()==1)
                    m=*t1.begin();
                else
                    m=(*t1.begin()+*t2.begin())/2;
            }
            else
            {
                if (t2.empty())
                {
                    t2.insert(x);
                    m=(*t1.begin()+*t2.begin())/2;
                    continue;
                }
                if (x>=*t2.rbegin()) t2.insert(--t2.end(),x);
                else if (x<=*t2.begin()) t2.insert(t2.begin(),x);
                else t2.insert(x);
                if ((int)t2.size()-(int)t1.size()==2)
                {
                    t1.insert(t1.begin(),*t2.begin());
                    t2.erase(t2.begin());
                }
                else if ((int)t2.size()-(int)t1.size()==1)
                    m=*t2.begin();
                else
                    m=(*t1.begin()+*t2.begin())/2;
            }
        }
        else
        {
            if (x<=m)
            {
                t1.erase(t1.find(x));
                if ((int)t2.size()-(int)t1.size()==2)
                {
                    t1.insert(t1.begin(),*t2.begin());
                    t2.erase(t2.begin());
                }
                else if ((int)t2.size()-(int)t1.size()==1)
                    m=*t2.begin();
                else
                    m=(*t1.begin()+*t2.begin())/2;
            }
            else
            {
                t2.erase(t2.find(x));
                if ((int)t1.size()-(int)t2.size()==2)
                {
                    t2.insert(t2.begin(),*t1.begin());
                    t1.erase(t1.begin());
                }
                else if ((int)t1.size()-(int)t2.size()==1)
                    m=*t1.begin();
                else
                    m=(*t1.begin()+*t2.begin())/2;
            }
        }
    }
    return 0;
}