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
map<int,token,greater<int>>* min_start_max_end
(map<int,token,greater<int>>* a,map<int,token,greater<int>>* b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->rbegin()->second.start != b->rbegin()->second.start)
        return a->rbegin()->second.start < b->rbegin()->second.start ? a : b;
    return a->rbegin()->second.end > b->rbegin()->second.end ? a : b;
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
    map<size_t,map<int,token,greater<int>>,greater<size_t>>m;
    map<int,token,greater<int>>* tks;
    map<int,token,greater<int>>::iterator mi;
    list<map<int,token,greater<int>>*>l;
    list<map<int,token,greater<int>>*>::iterator li;
    const token* best;
    const token* nearest;
    while (n--)
    {
        cin>>t>>k>>start;v.push_back(t);++id;
        tks=&m.try_emplace(t.length()).first->second;
        mi=tks->emplace(piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,&v[id])).first;
        while (k--)
        {
            cin>>start;
            mi=tks->emplace_hint(mi,piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,&v[id]));
        }
        end=max(end,mi->second.end);
    }
    for (auto&e:m)
    {
        tks=min_start_max_end(tks,&e.second);
        l.emplace_front(&e.second);
    }
    t=*tks->rbegin()->second.text;
    start=tks->rbegin()->second.end;
    tks->erase(std::prev(tks->end()));
    while (start!=end)
    {
        stop=false;
        best=nullptr;
        nearest=nullptr;
        for (li=l.begin();li!=l.end();)
        {
            tks=*li;
            if (tks->empty() || tks->begin()->second.end <= start)
            {
                li=l.erase(li);
                continue;
            }
            if (tks->begin()->second.start == start)
            {
                t+=*tks->begin()->second.text;
                start=tks->begin()->second.end;
                li=l.erase(li);
                stop=true;break;
            }
            if (tks->begin()->second.start < start)
            {
                best=best_extension(best,&tks->begin()->second);
                li=l.erase(li);
                break;
            }
            if (tks->rbegin()->second.start == start)
            {
                t+=*tks->rbegin()->second.text;
                start=tks->rbegin()->second.end;
                tks->erase(std::prev(tks->end()));
                li++;stop=true;break;
            }
            if (tks->rbegin()->second.start > start)
            {
                nearest=nearest_neighbor(nearest,&tks->rbegin()->second);
                li++;continue;
            }
            mi=tks->lower_bound(start);
            if (mi->second.start == start)
            {
                t+=*mi->second.text;
                start=mi->second.end;
                tks->erase(mi);
                li++;stop=true;break;
            }
            if (mi->second.end <= start)
            {
                nearest=nearest_neighbor(nearest,&mi->second);
                li++;continue;
            }
            best=best_extension(best,&tks->begin()->second);
            tks->erase(mi);
            li++;break;
        }
        if (stop) continue;
        if (!best)
        {
            n=nearest->start-start;
            while (n--) t+=char_a;
            t+=*nearest->text;
            start=nearest->end;
            continue;
        }
        while (li!=l.end())
        {
            tks=*li;
            if (tks->empty() || tks->begin()->second.end <= start)
            {
                li=l.erase(li);
                continue;
            }
        }
    }
    return 0;
}