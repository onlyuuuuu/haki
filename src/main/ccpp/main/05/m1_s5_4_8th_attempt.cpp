#include <bits/stdc++.h>
using namespace std;
struct token
{
    int start,end;
    string text;
    token(const int start,const string&text):start(start),end(start+static_cast<int>(text.length())),text(text){}
};
struct token_compare
{
    using is_transparent=void;
    bool operator()(const token&a,const token&b)const{return a.start>b.start;}
    bool operator()(const int a,const token&b)const{return a>b.start;}
    bool operator()(const token&a,const int b)const{return a.start>b;}
};
struct input
{
    set<token,token_compare>tokens;
    input(){}
    token min() const{return *tokens.rbegin();}
    int min_start() const{return tokens.rbegin()->start;}
    void erase_min(){tokens.erase(--tokens.end());}
    const token* before(const int pos) const
    {
        if (tokens.rbegin()->start > pos) return nullptr;
        if (tokens.rbegin()->start == pos) return &*tokens.rbegin();
        if (tokens.begin()->start <= pos) return &*tokens.begin();
        return &*tokens.lower_bound(pos);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator it,closest;
    set<token,token_compare>::iterator h;
    string s,t;int n,k,start,end;cin>>n;
    const token* found;
    while (n--)
    {
        cin>>t>>k>>start;
        auto&tokens=m.try_emplace(static_cast<int>(t.length())).first->second.tokens;
        h=tokens.emplace(start,t).first;
        while (--k)
        {
            cin>>start;
            h=tokens.emplace_hint(h,start,t);
        }
        end=max(end,h->end);
    }
    for (start=1;start!=end;)
    {
        closest=m.begin();
        for (it=m.begin();it!=m.end();it++)
        {
            found=it->second.before(start);
            if (found) break;
            if (it->second.min_start() < closest->second.min_start()) closest=it;
        }
        if (!found)
        {
            n=closest->second.min_start()-start;
            while (n--) s+='a';
            s+=closest->second.min().text;
            start=closest->second.min().end;
            closest->second.tokens.erase(closest->second.min());
        }
    }
    return 0;
}