#include <bits/stdc++.h>
using namespace std;
struct token
{
    int start,end;
    const string* text;
    token(int start,const string* text):
    start(start),end(start+static_cast<int>(text->length())),text(text){}
};
struct result
{
    map<int,token,greater<int>>* inp;
    map<int,token,greater<int>>::iterator tkn;
    result(map<int,token,greater<int>>*& inp,const map<int,token,greater<int>>::iterator& tkn):inp(inp),tkn(tkn){}
    void self_destruct(){inp->erase(tkn);} // O(1)
    void cascade_destruct(){inp->erase(tkn,inp->end());} // O(n)
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
optional<result> best_extension(optional<result> a,optional<result> b)
{
    if (!a) return b;
    if (!b) return a;
    return a->tkn->second.end > b->tkn->second.end ? a : b;
}
optional<result> nearest_neighbor(optional<result> a,optional<result> b)
{
    if (!a) return b;
    if (!b) return a;
    return a->tkn->second.start < b->tkn->second.start ? a : b;
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
    optional<result> best,nearest;
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
        stop=false;best.reset();nearest.reset();
        for (li=l.begin();li!=l.end();)
        {
            tks=*li;
            // if (tks->begin()->second.end <= start)
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
                best=best_extension(best,result(*li,tks->begin()));
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
                nearest=nearest_neighbor(nearest,result(*li,std::prev(tks->end())));
                li++;continue;
            }
            mi=tks->lower_bound(start);
            if (mi->second.start == start)
            {
                t+=*mi->second.text;
                start=mi->second.end;
                tks->erase(mi); // O(1)
                // tks->erase(mi,tks->end()); // O(n)
                li++;stop=true;break;
            }
            if (mi->second.end <= start)
            {
                nearest=nearest_neighbor(nearest,result(*li,mi));
                li++;continue;
            }
            best=best_extension(best,result(*li,tks->begin()));
            tks->erase(mi); // O(1)
            // tks->erase(mi,tks->end()); // O(n)
            li++;break;
        }
        if (stop) continue;
        if (!best)
        {
            n=nearest->tkn->second.start-start;
            while (n--) t+=char_a;
            t+=*nearest->tkn->second.text;
            start=nearest->tkn->second.end;
            nearest->self_destruct(); // O(1)
            // nearest->cascade_destruct(); // O(n)
            continue;
        }
        while (li!=l.end())
        {
            tks=*li;
            // if (tks->begin()->second.end <= best->tkn->second.end)
            if (tks->empty() || tks->begin()->second.end <= best->tkn->second.end)
            {
                li=l.erase(li);
                continue;
            }
            if (start + static_cast<int>(tks->begin()->second.text->length()) <= best->tkn->second.end) break;
            if (tks->rbegin()->second.start > start) {li++;continue;}
            if (tks->rbegin()->second.start == start)
            {
                best=best_extension(best,result(*li,std::prev(tks->end())));
                tks->erase(std::prev(tks->end()));
                li++;continue;
            }
            if (tks->begin()->second.start <= start)
            {
                best=best_extension(best,result(*li,tks->begin()));
                li=l.erase(li);
                continue;
            }
            mi=tks->lower_bound(start);
            best=best_extension(best,result(*li,std::prev(tks->end())));
            tks->erase(mi); // O(1)
            // tks->erase(mi,tks->end()); // O(n)
            li++;
        }
        n=start-best->tkn->second.start;
        while (n--) t.pop_back();
        t+=*best->tkn->second.text;
        start=best->tkn->second.end;
    }
    return 0;
}