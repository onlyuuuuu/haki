#include <bits/stdc++.h>
using namespace std;
struct token;
struct token_compare;
struct input;
struct token
{
    int start,end;
    string text;
    input*owner;
    token(int start,string&text,input* owner):start(start),end(start+static_cast<int>(text.length())),text(text),owner(owner){}
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
    map<int,input,greater<int>>*owner;
    input(map<int,input,greater<int>>*owner):owner(owner){}
    token min(){return *tokens.rbegin();}
    int min_start(){return tokens.rbegin()->start;}
    void erase_min(map<int,input,greater<int>>::iterator& it)
    {
        tokens.erase(--tokens.end());
        if (it->second.empty()) owner->erase(it);
    }
    bool empty(){return tokens.empty();}
    const token* before_or_equals(int pos,map<int,input,greater<int>>::iterator& it)
    {
        if (tokens.rbegin()->start > pos) return nullptr;
        if (tokens.rbegin()->start == pos) return &*tokens.rbegin();
        if (tokens.begin()->start == pos)
        {
            owner->erase(it);
            return &*tokens.begin();
        }
        if (tokens.begin()->start < pos)
        {
            if (tokens.begin()->end > pos)
            {
                owner->erase(it);
                return &*tokens.begin();
            }
        }
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
        auto&input=m.try_emplace(static_cast<int>(t.length()),&m).first->second;
        auto&tokens=input.tokens;
        h=tokens.emplace(start,t,&input).first;
        while (--k)
        {
            cin>>start;
            h=tokens.emplace_hint(h,start,t,&input);
        }
        end=max(end,h->end);
    }
    for (start=1;start!=end;)
    {
        closest=m.begin();
        for (it=m.begin();it!=m.end();it++)
        {
            found=it->second.before_or_equals(start,it);
            if (found && found->end > start) break; // fix
            if (it->second.min_start() < closest->second.min_start()) closest=it;
        }
        if (!found)
        {
            n=closest->second.min_start()-start;
            while (n--) s+='a';
            s+=closest->second.min().text;
            start=closest->second.min().end;
            closest->second.erase_min(closest);
            continue;
        }
        if (found->start==start)
        {
            s+=found->text;
            start=found->end;
            it->second.tokens.erase(found->start);
            if (it->second.empty()) m.erase(it);
            continue;
        }
        n=found->end;
        for (++it;it!=m.end();it++)
        {
            if (start + it->first <= n) break;
            found=it->second.before_or_equals(start,it);
        }
    }
    return 0;
}