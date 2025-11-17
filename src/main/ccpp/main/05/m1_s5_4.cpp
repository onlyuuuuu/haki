#include<bits/stdc++.h>
using namespace std;
struct token
{
    std::string_view txt;
    int str=0,end=0;
    token()=default;
    token(const string&t,const int&s):txt(t),str(s),end(s+t.length()){}
    bool operator!=(const token&tk)const{return str!=tk.str;}
    bool operator==(const token&tk)const{return str==tk.str;}
    bool operator>(const token&tk)const{return str>tk.str;}
    bool operator<(const token&tk)const{return str<tk.str;}
    bool operator>=(const token&tk)const{return str>=tk.str;}
    bool operator<=(const token&tk)const{return str<=tk.str;}
    bool operator!=(const int&i)const{return str!=i;}
    bool operator==(const int&i)const{return str==i;}
    bool operator>(const int&i)const{return str>i;}
    bool operator<(const int&i)const{return str<i;}
    bool operator>=(const int&i)const{return str>=i;}
    bool operator<=(const int&i)const{return str<=i;}
    friend bool operator!=(const int&i,const token&tk){return i!=tk.str;}
    friend bool operator==(const int&i,const token&tk){return i==tk.str;}
    friend bool operator>(const int&i,const token&tk){return i>tk.str;}
    friend bool operator<(const int&i,const token&tk){return i<tk.str;}
    friend bool operator>=(const int&i,const token&tk){return i>=tk.str;}
    friend bool operator<=(const int&i,const token&tk){return i<=tk.str;}
};
struct input
{
    vector<token>::iterator front;
    vector<token>tokens;
    input()=default;
    const input& shift_front(const vector<token>::iterator&new_front){front=new_front;return *this;}
};
struct entry
{
    input*i=nullptr;
    vector<token>::iterator n;
    entry()=default;
    entry(input&inp,const vector<token>::iterator&it):i(&inp),n(it){};
    entry(const map<int,input,greater<int>>::iterator&inp,const vector<token>::iterator&it):i(&inp->second),n(it){};
    const entry& shift_front(){i->shift_front(std::next(n));return *this;}
    const entry& reset(){i=nullptr;return *this;}
};
const entry& nearest_neighbor(const entry&a,const entry&b)
{
    if(!a.i) return b;
    if(a.n->str != b.n->str) return a.n->str < b.n->str ? a : b;
    return a.n->end > b.n->end ? a : b;
}
const token& best_extension(const token&a,const token&b)
{
    if(a.end != b.end) return a.end > b.end ? a : b;
    return a.str < b.str ? a : b;
}
const token& best_extension(const optional<token>&a,const token&b)
{
    if(!a) return b;
    return best_extension(*a,b);
}
const token& best_extension(const optional<token>&a,const vector<token>::iterator&b)
{
    return best_extension(a,*b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator mit;
    string t;int k,n;int start,end=INT_MIN;cin>>n;
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
        end=std::max(end,v.back().end);
    }
    optional<token>bs;entry nr;t="";bool stop=false;
    for(start=1;start!=end;)
    {
        stop=false;
        bs.reset();
        nr.reset();
        for(mit=m.begin();mit!=m.end();)
        {
            if(mit->second.tokens.back().end <= start)
            {
                mit=m.erase(mit);
                continue;
            }
            if(mit->second.tokens.back() == start)
            {
                t+=mit->second.tokens.back().txt;
                start=mit->second.tokens.back().end;
                mit=m.erase(mit);
                stop=true;
                break;
            }
            if(mit->second.tokens.back() < start)
            {
                bs=mit->second.tokens.back();
                mit=m.erase(mit);
                break;
            }
            if(*mit->second.front == start)
            {
                t+=mit->second.front->txt;
                start=mit->second.front++->end;
                stop=true;
                break;
            }
            if(*mit->second.front > start)
            {
                nr=nearest_neighbor(nr,entry(mit,mit->second.front));
                mit++;
                continue;
            }
            vit=std::lower_bound(mit->second.front,mit->second.tokens.end(),start);
            if(*vit == start)
            {
                t+=vit->txt;
                start=vit->end;
                mit->second.shift_front(++vit);
                stop=true;
                break;
            }
            if((--vit)->end > start)
            {
                bs=*vit;
                mit++->second.shift_front(++vit);
                break;
            }
            nr=nearest_neighbor(nr,entry(mit++,++vit));
        }
        if(stop) continue;
        if(!bs)
        {
            n=nr.n->str-start;
            while(n--) t+='a';
            t+=nr.n->txt;
            start=nr.n->end;
            nr.shift_front();
            continue;
        }
        for(;mit!=m.end() && start + mit->first > bs->end;)
        {
            if(mit->second.tokens.back().end <= bs->end)
            {
                mit=m.erase(mit);
                continue;
            }
            if(mit->second.tokens.back() <= start)
            {
                bs=best_extension(bs,mit->second.tokens.back());
                mit=m.erase(mit);
                continue;
            }
            if(*mit->second.front > start)
            {
                mit++;
                continue;
            }
            if(*mit->second.front == start)
            {
                bs=best_extension(bs,mit++->second.front++);
                continue;
            }
            vit=std::lower_bound(mit->second.front,mit->second.tokens.end(),start);
            bs=best_extension(bs,*vit == start ? vit : --vit);
            mit++->second.shift_front(++vit);
        }
        n=start-bs->str;
        while(n--) t.pop_back();
        t+=bs->txt;
        start=bs->end;
    }
    cout<<t<<'\n';
    return 0;
}