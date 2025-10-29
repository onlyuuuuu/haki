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
struct result
{
    int id;
    map<size_t,pair<int,vector<token>>,greater<size_t>>::iterator mit;
    result(const int&id,const map<size_t,pair<int,vector<token>>,greater<size_t>>::iterator&mit):id(id),mit(mit){}
    token&tkn(){return mit->second.second[id];}
    void to_this_head(){mit->second.first=id;}
    void to_next_head(){mit->second.first=id+1;}
};
result* best_extension(result*a,result*b)
{
    if (!a)
    {
        b->to_next_head();
        return b;
    }
    if (!b)
    {
        a->to_next_head();
        return a;
    }
    a->to_next_head();
    b->to_next_head();
    return a->tkn().e > b->tkn().e ? a : b;
}
result* nearest_neighbor(result*a,result*b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->tkn().s != b->tkn().s)
        return a->tkn().s < b->tkn().s ? a : b;
    return a->tkn().e > b->tkn().e ? a : b;
}
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<size_t,pair<int,vector<token>>,greater<size_t>>m;
    map<size_t,pair<int,vector<token>>,greater<size_t>>::iterator mit;
    bool stop;string t;int n,k,s,i,seq=-1,e=INT_MIN;cin>>n;
    vector<string>d;d.reserve(n);
    result* best=nullptr;
    result* near=nullptr;
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        mit=m.try_emplace(t.length()).first;
        mit->second.first=0;
        auto&v=mit->second.second;
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
        near=nearest_neighbor(near,new result(0,mit));
        e=std::max(e,v.back().e);
    }
    t=*near->tkn().t;
    s=near->tkn().e;
    near->to_next_head();
    while (s!=e)
    {
        stop=false;
        best=nullptr;
        near=nullptr;
        for (mit=m.begin();mit!=m.end();)
        {
            auto&head=mit->second.first;
            auto&tokens=mit->second.second;
            auto&front=tokens[head];
            auto&back=tokens.back();
            if (back.e <= s) { mit=m.erase(mit);continue; }
            if (back == s)
            {
                t+=*back.t;
                s=back.e;
                mit=m.erase(mit);
                stop=true;break;
            }
            if (back < s)
            {
                best=best_extension(best,new result(tokens.size()-1,mit));
                mit=m.erase(mit);
                break;
            }
            if (front == s)
            {
                t+=*front.t;
                s=front.e;
                front=tokens[++head];
                stop=true;break;
            }
            if (front > s)
            {
                near=nearest_neighbor(near,new result(0,mit));
                front=tokens[++head];
                mit++;
                continue;
            }

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
                continue;
            }
            if (front == s)
            {
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