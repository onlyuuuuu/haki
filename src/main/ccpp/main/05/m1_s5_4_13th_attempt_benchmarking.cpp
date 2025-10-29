#include <bits/stdc++.h>
using namespace std;
struct token
{
    const string* t;int s,e;
    token(const string*t,const int&s):t(t),s(s),e(s+t->length()){}
    bool operator==(const token&tk)const{return s==tk.s;}
    bool operator<(const token&tk)const{return s<tk.s;}
    bool operator<=(const token&tk)const{return s<=tk.s;}
    bool operator>(const token&tk)const{return s>tk.s;}
    bool operator>=(const token&tk)const{return s>=tk.s;}
    bool operator==(const int&i)const{return s==i;}
    bool operator<(const int&i)const{return s<i;}
    bool operator<=(const int&i)const{return s<=i;}
    bool operator>(const int&i)const{return s>i;}
    bool operator>=(const int&i)const{return s>=i;}
};
struct input
{
    vector<token>v;
    vector<token>::iterator f;
    input():f(v.begin()){};
};
struct nearest
{
    int idx;input inp;vector<token>::iterator vit;
    nearest(const vector<token>::iterator&vit,const input&inp):idx(vit-inp.v.begin()),inp(inp),vit(vit){}
    nearest(const int&idx,const vector<token>::iterator&vit,const input&inp):idx(idx),inp(inp),vit(vit){}
    void to_next_head(){inp.f=std::next(vit);}
};
nearest*nearest_neighbor(nearest*a,nearest*b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->vit->s != b->vit->s)
        return a->vit->s < b->vit->s ? a : b;
    return a->vit->e > b->vit->e ? a : b;
}
nearest*nearest_neighbor(nearest*a,const vector<token>::iterator&vit,const input&inp)
{
    return nearest_neighbor(a,new nearest(vit,inp));
}
nearest*nearest_neighbor(nearest*a,const vector<token>::iterator&vit,const map<size_t,input,greater<size_t>>::iterator&mit)
{
    return nearest_neighbor(a,vit,mit->second);
}
nearest*nearest_neighbor(nearest*a,const int&idx,const vector<token>::iterator&vit,const input&inp)
{
    return nearest_neighbor(a,new nearest(idx,vit,inp));
}
nearest*nearest_neighbor(nearest*a,const int&idx,const vector<token>::iterator&vit,const map<size_t,input,greater<size_t>>::iterator&mit)
{
    return nearest_neighbor(a,idx,vit,mit->second);
}
optional<token>best_extension(optional<token>a,optional<token>b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->e != b->e)
        return a->e > b->e ? a : b;
    return a->s > b->s ? a : b;
}
optional<token>best_extension(optional<token>a,const vector<token>::iterator&b)
{
    return best_extension(a,std::make_optional(*b));
}
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<size_t,input,greater<size_t>>m;
    map<size_t,input,greater<size_t>>::iterator mit;
    bool stop;string t;int n,k,s,i,seq=-1,e=INT_MIN;cin>>n;
    vector<string>d;d.reserve(n);
    optional<token> best;
    nearest* near=nullptr;
    vector<token>::iterator found;
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        auto&v=m.try_emplace(t.length()).first->second.v;
        if (v.empty())
        {
            v.reserve(k);
            v.emplace_back(&d[seq],s);
            while (--k)
            {
                cin>>s;
                v.emplace_back(&d[seq],s);
            }
        }
        else
        {
            if (v.back()<s)
            {
                v.reserve(v.size()+k);
                v.emplace_back(&d[seq],s);
                while (--k)
                {
                    cin>>s;
                    v.emplace_back(&d[seq],s);
                }
            }
            else
            {
                vector<token>tmp;
                tmp.reserve(k+v.size());
                for (i=0;v[i]<s;i++) tmp.push_back(v[i]);
                tmp.emplace_back(&d[seq],s);
                while (--k)
                {
                    cin>>s;
                    for (;v[i]<s&&i<v.size();i++) tmp.push_back(v[i]);
                    tmp.emplace_back(&d[seq],s);
                }
                for (;i<v.size();i++) tmp.push_back(v[i]);
                v.swap(tmp);
            }
        }
        near=nearest_neighbor(near,0,v.begin(),mit->second);
        e=std::max(e,v.back().e);
    }
    t=*near->vit->t;
    s=near->vit->e;
    near->to_next_head();
    while (s!=e)
    {
        stop=false;
        near=nullptr;
        best.reset();
        for (mit=m.begin();mit!=m.end();)
        {
            vector<token>&tokens=mit->second.v;
            vector<token>::iterator&front=mit->second.f;
            vector<token>::iterator&back=--mit->second.v.end();
            if (back->e <= s) { mit=m.erase(mit);continue; }
            if (back->s == s)
            {
                t+=*back->t;
                s=back->e;
                mit=m.erase(mit);
                stop=true;break;
            }
            if (back->s < s)
            {
                best=best_extension(best,back);
                mit=m.erase(mit);
                break;
            }
            if (front->s == s)
            {
                t+=*front->t;
                s=front->e;
                front++;
                stop=true;break;
            }
            if (front->s > s)
            {
                near=nearest_neighbor(near,0,front,mit);
                continue;
            }
            found=std::lower_bound(front,back,s);
            if (found->s == s)
            {
                t+=*found->t;
                s=found->e;
                front=std::next(found);
                stop=true;break;
            }
            if ((--found)->e > s)
            {
                best=best_extension(best,found);
                front=std::next(found);
                break;
            }
            near=nearest_neighbor(near,std::next(found),mit);
        }
        if (stop) continue;
        if (!best)
        {
            n=near->tkn().s-s;
            while (n--) t+=char_a;
            t+=*near->tkn().t;
            s=near->tkn().e;
            near->to_next_head();
            continue;
        }
        while (mit!=m.end() && s+mit->first>s)
        {
            auto&head=mit->second.first;
            auto&tokens=mit->second.second;
            auto&front=tokens[head];
            auto&back=tokens.back();
            if (back.e <= s) { mit=m.erase(mit);continue; }
            if (front > s) continue;
            if (back <= s)
            {
                best=best_extension(best,new nearest(tokens.size()-1,mit));
                mit=m.erase(mit);
                continue;
            }
            if (front == s)
            {
                best=best_extension(best,new nearest(0,mit));
                continue;
            }

        }
        n=s-best->tkn().s;
        while (n--) t.pop_back();
        t+=*best->tkn().t;
        s=best->tkn().e;
    }
    return 0;
}