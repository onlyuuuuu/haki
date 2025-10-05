#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
class input
{
public:
    string text;int start;
    input(){}
    input(string text,int start)
    {
        this->text=text;
        this->start=start;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string result,t;int n,k,x,e;cin>>n;
    map<int,input>m;
    map<int,input>::iterator i;
    for (;n>0;n--)
    {
        cin>>t>>k;
        for (;k>0;k--)
        {
            cin>>x;
            e=x+static_cast<int>(t.length());
            i=m.find(e);
            if (i==m.end())
                m.emplace(piecewise_construct,forward_as_tuple(e),forward_as_tuple(t,x));
            else
            {
                if (t.length()>i->second.text.length())
                {
                    i->second.text=t;
                    i->second.start=x;
                }
            }
        }
    }
    if (m.rbegin()->second.start==1)
    {
        cout<<m.rbegin()->second.text;
        return 0;
    }
    n=m.rbegin()->second.start;
    result=m.rbegin()->second.text;
    m.erase(--m.end());
    for (i=m.lower_bound(n);!m.empty();i=m.lower_bound(n))
    {
        if (i->second.start==1)
        {
            result=((i->first==n)?i->second.text:i->second.text.substr(0,n-i->second.start))+result;
            break;
        }
        while (i!=m.end() && i->second.start>=n) i=m.erase(i);
        if (i==m.end())
        {
            --i;
            for (k=n-i->first;k>0;k--) result=char_a+result;
            result=i->second.text+result;
        }
        else result=((i->first==n)?i->second.text:i->second.text.substr(0,n-i->second.start))+result;
        n=i->second.start;
    }
    cout<<result;
    return 0;
}