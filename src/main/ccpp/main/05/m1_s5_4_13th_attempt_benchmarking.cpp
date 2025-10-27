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
token* min_start_max_end(token*a,token*b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->s != b->s)
        return a->s < b->s ? a : b;
    return a->e > b->e ? a : b;
}
token* best_extension(token*a,token*b)
{
    if (!a) return b;
    if (!b) return a;
    return a->e > b->e ? a : b;
}
token* nearest_neighbor(token*a,token*b)
{
    if (!a) return b;
    if (!b) return a;
    return a->s < b->s ? a : b;
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
    token* msme=nullptr;
    token* best=nullptr;
    token* near=nullptr;
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
        msme=min_start_max_end(msme,&v[0]);
        e=std::max(e,v.back().e);
    }
    t=*msme->t;
    s=msme->e;
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
                best=best_extension(best,&back);
                mit=m.erase(mit);
                continue;
            }
            if (front == s)
            {
                t+=*front.t;
                s=front.e;
                head++;
                mit++;
                stop=true;break;
            }
            if (front > s)
            {
                near=nearest_neighbor(near,&front);
                head++;
                mit++;
                continue;
            }

        }
        if (stop) continue;
        if (!best)
        {
            n=near->s-s;
            while (n--) t+=char_a;
            t+=*near->t;
            s=
            continue;
        }
        while (mit!=m.end())
        {
            i=mit->second.first;
            auto&tokens=mit->second.second;
            auto&front=tokens[i];
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
            // search
        }

    }
    return 0;
}