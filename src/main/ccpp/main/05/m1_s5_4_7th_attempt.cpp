#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool stop;string t,s="";int n,k,i,len,end=INT_MIN;cin>>n;
    map<int,map<int,string,greater<int>>,greater<int>>m;
    map<int,string,greater<int>>::iterator i1,found,max1;
    map<int,map<int,string,greater<int>>,greater<int>>::iterator i2,min,max2;
    while (n--)
    {
        cin>>t>>k>>i;
        len=static_cast<int>(t.length());
        auto&sm=m.try_emplace(len).first->second;
        i1=sm.emplace(i,t).first;
        while (--k)
        {
            cin>>i;
            sm.emplace_hint(i1,i,t);
        }
        end=max(end,i+len);
    }
    for (n=1;n!=end;)
    {
        k=0;
        stop=false;
        min=m.begin();
        for (i2=m.begin();i2!=m.end();i2++)
        {
            if (i2->second.rbegin()->first==n)
            {
                s+=i2->second.rbegin()->second;
                n+=static_cast<int>(i2->second.rbegin()->second.length());
                i2->second.erase(--i2->second.end());
                if (i2->second.empty()) m.erase(i2);
                stop=true;break;
            }
            if (i2->second.begin()->first==n)
            {
                s+=i2->second.begin()->second;
                n+=static_cast<int>(i2->second.begin()->second.length());
                i2->second.erase(i2->second.begin());
                if (i2->second.empty()) m.erase(i2);
                stop=true;break;
            }
            if (i2->second.rbegin()->first<n)
            {
                if (i2->second.begin()->first<n)
                    found=i2->second.begin();
                else found=i2->second.lower_bound(n);
                if (found->first==n)
                {
                    s+=found->second;
                    n+=static_cast<int>(found->second.length());
                    i2->second.erase(found);
                    if (i2->second.empty()) m.erase(i2);
                    stop=true;
                }
                else
                {
                    k=found->first+static_cast<int>(found->second.length());
                    max1=found;
                    max2=i2;
                }
                break;
            }
            if (i2->second.rbegin()->first < min->second.rbegin()->first)
                min=i2;
        }
        if (stop) continue;
        if (k==0)
        {
            i=min->second.rbegin()->first-n;
            while (i--) s+=char_a;
            s+=min->second.rbegin()->second;
            n=min->second.rbegin()->first+static_cast<int>(min->second.rbegin()->second.length());
            min->second.erase(--min->second.end());
            if (min->second.empty()) m.erase(min);
            continue;
        }
        for (++i2;i2!=m.end();i2++)
        {
            if (n+i2->first<=k) break;
            if (i2->second.rbegin()->first>n) continue;
            if (i2->second.rbegin()->first==n) found=--i2->second.end();
            else if (i2->second.begin()->first==n) found=i2->second.begin();
            else
            {
                if (i2->second.begin()->first<n)
                    found=i2->second.begin();
                else found=i2->second.lower_bound(n);
            }
            i=found->first+static_cast<int>(found->second.length());
            if (i>k)
            {
                k=i;
                max1=found;
                max2=i2;
            }
        }
        i=n-max1->first;
        while (i--) s.pop_back();
        s+=max1->second;
        n+=k;
        max2->second.erase(max1);
        if (max2->second.empty()) m.erase(max2);
    }
    cout<<s;
    return 0;
}