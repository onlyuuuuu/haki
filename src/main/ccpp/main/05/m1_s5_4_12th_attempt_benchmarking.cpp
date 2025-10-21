#include <bits/stdc++.h>
using namespace std;
struct token
{
    int start,end;
    const string* text;
    token(int start,const string* text):
    start(start),end(start+static_cast<int>(text->length())),text(text){}
};
struct token_comparator
{
    using is_transparent=void;
    bool operator()(const token&a, const token&b) const{return a.start>b.start;}
    bool operator()(const int&a, const token&b) const{return a>b.start;}
    bool operator()(const token&a, const int&b) const{return a.start>b;}
};
const set<token,token_comparator>* min_start_max_end
(const set<token,token_comparator>* a,const set<token,token_comparator>* b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->rbegin()->start != b->rbegin()->start)
        return a->rbegin()->start < b->rbegin()->start ? a : b;
    return a->rbegin()->end > b->rbegin()->end ? a : b;
}
const token* best_extension(const token* a,const token* b)
{
    if (!a) return b;
    if (!b) return a;
    return a->end > b->end ? a : b;
}
const token* nearest_neighbor(const token* a,const token* b)
{
    if (!a) return b;
    if (!b) return a;
    return a->start < b->start ? a : b;
}
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    bool stop;
    string t;int n,k,start,end=INT_MIN,id=-1;cin>>n;
    vector<string>v;v.reserve(n);
    map<size_t,set<token,token_comparator>,greater<size_t>>m;
    set<token,token_comparator>* tks;
    const set<token,token_comparator>* msme;
    set<token,token_comparator>::iterator it;
    queue<const set<token,token_comparator>*>q;
    const token* best;
    const token* nearest;
    while (n--)
    {
        cin>>t>>k>>start;v.push_back(t);++id;
        tks=&m.try_emplace(t.length()).first->second;
        it=tks->emplace(start,&v[id]).first;
        while (k--)
        {
            cin>>start;
            it=tks->emplace_hint(it,start,&v[id]);
        }
        end=max(end,it->end);
    }
    for (const auto&[key,val]:m)
    {
        msme=min_start_max_end(msme,&val);
        q.emplace(&val);
    }
    return 0;
}