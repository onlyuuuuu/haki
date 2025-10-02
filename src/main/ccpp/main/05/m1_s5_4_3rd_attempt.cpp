#include <bits/stdc++.h>
using namespace std;
struct obj{string text;int start,end;};
struct compare
{
    bool operator()(const obj& a,const obj& b) const
    {
        if (a.text.size()!=b.text.size())
            return a.text.size()<b.text.size();
        return a.end<b.end;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;int n,k,x,st=INT_MAX,nd=INT_MIN;cin>>n;
    priority_queue<obj,vector<obj>,compare>q;
    map<int,obj>m;map<int,obj>::iterator it;
    for (;n>0;n--)
    {
        cin>>s>>k;
        for (;k>0;k--)
        {
            obj o;
            o.text=s;
            cin>>o.start;
            o.end=o.start+static_cast<int>(s.length())-1;
            st=min(st,o.start);
            nd=max(nd,o.end);
            q.push(o);
        }
    }
    m.insert({q.top().text.length(),q.top()});q.pop();
    for (obj top=q.top();!q.empty() && !(m.size()==1 && m.begin()->second.start==st && m.begin()->second.end==nd);q.pop())
    {
        it=m.lower_bound(q.top().start);

    }
    return 0;
}