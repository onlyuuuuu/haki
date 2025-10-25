#include <bits/stdc++.h>
using namespace std;
struct token
{
    int start,end;
    const string* text;
    token(int start,const string* text):
    start(start),end(start+static_cast<int>(text->length())),text(text){}
};
struct nearest
{
    map<int,token,greater<int>>* inp;
    map<int,token,greater<int>>::iterator tkn;
    nearest(map<int,token,greater<int>>*& inp,const map<int,token,greater<int>>::iterator& tkn)
    :inp(inp),tkn(tkn){}
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
optional<token> best_extension(optional<token> a,optional<token> b)
{
    if (!a) return b;
    if (!b) return a;
    return a->end > b->end ? a : b;
}
optional<nearest> nearest_neighbor(optional<nearest> a,optional<nearest> b)
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
    list<map<int,token,greater<int>>>l;
    list<map<int,token,greater<int>>>::iterator li;
    optional<nearest> near;
    optional<token> best;
    while (n--)
    {
        cin>>t>>k>>start;v.push_back(t);++id;
        tks=&m.try_emplace(t.length()).first->second;
        mi=tks->emplace(piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,&v[id])).first;
        while (--k)
        {
            cin>>start;
            mi=tks->emplace_hint(mi,piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,&v[id]));
        }
        end=max(end,mi->second.end);
    }
    for (auto it=m.begin();it!=m.end();it=m.erase(it)) tks=min_start_max_end(tks,&l.emplace_front(it->second));
    t="";
    n=tks->rbegin()->second.start-1;
    while (n--) t+=char_a;
    t+=*tks->rbegin()->second.text;
    start=tks->rbegin()->second.end;
    tks->erase(std::prev(tks->end()));
    while (start!=end)
    {
        stop=false;best.reset();near.reset();
        for (li=l.begin();li!=l.end();)
        {
            tks=&*li;
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
                best=best_extension(best,tks->begin()->second);
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
                near=nearest_neighbor(near,nearest(tks,std::prev(tks->end())));
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
                near=nearest_neighbor(near,nearest(tks,mi));
                li++;continue;
            }
            best=best_extension(best,tks->begin()->second);
            tks->erase(mi); // O(1)
            // tks->erase(mi,tks->end()); // O(n)
            li++;break;
        }
        if (stop) continue;
        if (!best)
        {
            n=near->tkn->second.start-start;
            while (n--) t+=char_a;
            t+=*near->tkn->second.text;
            start=near->tkn->second.end;
            near->self_destruct(); // O(1)
            // nearest->cascade_destruct(); // O(n)
            continue;
        }
        while (li!=l.end())
        {
            tks=&*li;
            // if (tks->begin()->second.end <= best->end)
            if (tks->empty() || tks->begin()->second.end <= best->end)
            {
                li=l.erase(li);
                continue;
            }
            if (start + static_cast<int>(tks->begin()->second.text->length()) <= best->end) break;
            if (tks->rbegin()->second.start > start) {li++;continue;}
            if (tks->rbegin()->second.start == start)
            {
                best=best_extension(best,std::prev(tks->end())->second);
                tks->erase(std::prev(tks->end()));
                li++;continue;
            }
            if (tks->begin()->second.start <= start)
            {
                best=best_extension(best,tks->begin()->second);
                li=l.erase(li);
                continue;
            }
            mi=tks->lower_bound(start);
            best=best_extension(best,std::prev(tks->end())->second);
            tks->erase(mi); // O(1)
            // tks->erase(mi,tks->end()); // O(n)
            li++;
        }
        n=start-best->start;
        while (n--) t.pop_back();
        t+=*best->text;
        start=best->end;
    }
    cout<<t;
    return 0;
}