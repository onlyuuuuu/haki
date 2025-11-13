#include<bits/stdc++.h>
using namespace std;
struct token
{
    std::string_view txt;
    int str=0,end=0;
    token()=default;
    token(const string&t,const int&s):txt(t),str(s),end(s+t.length()){}
    const bool operator==(const token&tk)const{return str==tk.str;}
};
struct input
{
    vector<token>::iterator front;
    vector<token>::iterator back;
    vector<token>tokens;
    input()=default;
};
struct entry
{
    input*i=nullptr;
    vector<token>::iterator n;
    entry()=default;
    entry(input&inp,const vector<token>::iterator&it):i(&inp),n(it){};
    entry(const map<int,input,greater<int>>::iterator&inp,const vector<token>::iterator&it):i(&inp->second),n(it){};
    const entry& shift_left()const{i->front=std::next(n);return *this;}
    const entry& reset(){i=nullptr;return *this;}
};
const entry& best_extension(const entry&a,const entry&b)
{
    if(!a.i) return b.shift_left();
    if(!b.i) return a.shift_left();
    if(a.n->end != b.n->end) return a.n->end > b.n->end ? a.shift_left() : b.shift_left();
    return a.n->str < b.n->str ? a.shift_left() : b.shift_left();
}
const entry& nearest_neighbor(const entry&a,const entry&b)
{
    if(!a.i) return b;
    if(!b.i) return a;
    if(a.n->str != b.n->str) return a.n->str < b.n->str ? a : b;
    return a.n->end > b.n->end ? a : b;
}
struct compare
{
    
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator mit;
    string t;int k,n;int start,end=INT_MAX;cin>>n;
    vector<string>d;d.reserve(n);
    vector<token>::iterator vit;
    while(n--)
    {
        cin>>t>>k;
        d.emplace_back(t);
        auto&i=m.try_emplace(t.length()).first->second;
        auto&v=i.tokens;
        vector<token>tmp;
        tmp.reserve(k+v.size());
        vit=v.begin();
        while(k--)
        {
            cin>>start;
            for(;vit != v.end() && vit->str < start;vit++) tmp.push_back(std::move(*vit));
            tmp.emplace_back(d.back(),start);
        }
        for(;vit != v.end();vit++) tmp.push_back(std::move(*vit));
        v.swap(tmp);
        i.front=v.begin();
        i.back=std::prev(v.end());
        end=std::max(end,v.back().end);
    }
    entry nr,bs;
    start=1;
    while(start!=end)
    {
        bs.reset();
        nr.reset();
        mit=m.begin();
        while(mit != m.end() && start + mit->first > bs.n->end)
        {
            if(mit->second.back->end <= std::max(start,bs.n->end))
            {
                mit=m.erase(mit);
                continue;
            }
            if(mit->second.back->str <= start)
            {
                bs=best_extension(bs,entry(mit,mit->second.back));
                mit=m.erase(mit);
                continue;
            }
            if(mit->second.front->str > start)
            {
                nr=nearest_neighbor(nr,entry(mit++,mit->second.front));
                continue;
            }
            if(mit->second.front->str == start)
            {
                bs=best_extension(bs,entry(mit++,mit->second.front));
                continue;
            }
            vit=std::lower_bound(mit->second.front,mit->second.tokens.end(),start);
            if(vit->str == start)
            {
                bs=best_extension(bs,entry(mit++,vit));
                continue;
            }
            nr=nearest_neighbor(nr,entry(mit,vit));
            bs=best_extension(bs,entry(mit++,std::prev(vit)));
        }
    }
    cout<<t<<'\n';
    return 0;
}