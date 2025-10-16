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
    bool operator()(const token&a,const token&b)const{a.start>b.start;}
    bool operator()(const int a,const token&b)const{a>b.start;}
    bool operator()(const token&a,const int b)const{a.start>b;}
};
struct input
{
    set<token,token_compare>tokens;
    input(){}
    token min() const{return *tokens.rbegin();}
    token max() const{return *tokens.begin();}
    int min_start() const{return tokens.rbegin()->start;}
    int max_start() const{return tokens.begin()->start;}
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
    map<int,input,greater<int>>::iterator it;
    set<token,token_compare>::iterator h;
    string s,t;int n,k,start,end;cin>>n;
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
    return 0;
}