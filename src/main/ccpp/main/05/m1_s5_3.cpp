#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    multiset<int,greater<>>s1;multiset<int>s2;
    string s;int i;cin>>s>>i;int m = i;
    for (;n>1;n--)
    {
        cin>>s;
        if (s!="MEDIAN")
        {
            cin>>i;
            if (s=="IN")
            {
                if (i<=m)s1.insert(i);
                else s2.insert(i);
            }
            else
            {
                if (i==m)
                {
                    if (s1.size()>=s2.size())
                    {
                        m=*s1.begin();
                        s1.erase(s1.begin());
                    }
                    else
                    {
                        m=*s2.begin();
                        s2.erase(s2.begin());
                    }
                }
                else if (i<m) s1.erase(s1.find(i));
                else s2.erase(s2.find(i));
            }
            if ((int)s1.size()-(int)s2.size()==2)
            {
                s2.insert(m);
                m=*s1.begin();
                s1.erase(s1.begin());
            }
            else if ((int)s1.size()-(int)s2.size()==-2)
            {
                s1.insert(m);
                m=*s2.begin();
                s2.erase(s2.begin());
            }
            continue;
        }
        if (s1.size()==s2.size()) cout<<m<<endl;
        else if (s1.size()>s2.size()) cout<<(double)(m+*s1.begin())/2<<endl;
        else cout<<(double)(m+*s2.begin())/2<<endl;
    }
    return 0;
}