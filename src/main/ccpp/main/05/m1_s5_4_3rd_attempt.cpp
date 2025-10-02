#include <bits/stdc++.h>
using namespace std;
struct entry{string t;int s,e;};
struct compare{bool operator()(const entry&a,const entry&b)const{return(a.t.length()!=b.t.length())?a.t.length()<b.t.length():a.e<b.e;}};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;int n,k,st=INT_MAX,nd=INT_MIN;cin>>n;
    priority_queue<entry,vector<entry>,compare>q;
    map<int,entry>m;map<int,entry>::iterator f;
    for (;n>0;n--)
    {
        cin>>s>>k;
        for (;k>0;k--)
        {
            entry e;e.t=s;cin>>e.s;e.e=e.s+e.t.length()-1;
            st=min(st,e.s);
            nd=max(nd,e.e);
            q.push(e);
        }
    }
    m[q.top().e]=q.top();q.pop();entry top;
    for (;!q.empty()&&!(static_cast<int>(m.size())==1&&m.begin()->second.s==st&&m.begin()->second.e==nd);q.pop())
    {
        top=q.top();
        f=m.lower_bound(top.s);
        if (f==m.end()||top.e<f->second.s){m[top.e]=top;continue;}
        if (top.s<=f->second.s&&top.e>=f->second.e)continue;
        if (f->second.s<top.s)
        {
            if (f->second.e>top.s)top.t=f->second.t.substr(0,top.s+1)+top.t;
            else /*if (f->second.e==top.s)*/top.t=f->second.t+top.t;
            top.s=f->second.s;
            m.erase(f);
            f=m.lower_bound(top.s);
            if (f==m.end())continue;
        }
        if (f->second.s>top.s)
        {
            if (f->second.s<top.e)f->second.t=top.t.substr(0,f->second.s+1)+f->second.t;
            else /*if (f->second.s==top.e)*/f->second.t=top.t+f->second.t;
            f->second.s=top.s;
        }
    }
    return 0;
}