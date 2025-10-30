#include <bits/stdc++.h>
using namespace std;
struct token
{
    string&t;int s,e;
    token(string&t):t(t),s(0),e(0){}
    token(string&t,int&s):t(t),s(s),e(s+t.length()){}
    int operator-(const int&i)const{return s-i;}
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
    bool unset()const{return s==0;}
    token&reset(){s=0;return*this;}
};
struct input
{
    vector<token>v;
    vector<token>::iterator&f;
    input();
};
struct nearest
{
    input&inp;
    const vector<token>::iterator&vit;
    nearest(const vector<token>::iterator&vit,input&inp):inp(inp),vit(vit){}
    nearest&to_next_head(){inp.f=vit+1;return*this;}
    int operator-(const int&i)const{return*vit-i;}
};
nearest*nearest_neighbor(nearest*a,nearest*b)
{
    if (!a) return b;
    if (!b) return a;
    if (a->vit->s != b->vit->s)
        return a->vit->s < b->vit->s ? a : b;
    return a->vit->e > b->vit->e ? a : b;
}
nearest*nearest_neighbor(nearest*a,const vector<token>::iterator&vit,input&inp)
{
    return nearest_neighbor(a,new nearest(vit,inp));
}
nearest* nearest_neighbor(nearest*a,const vector<token>::iterator&vit,const map<size_t,input,greater<size_t>>::iterator&mit)
{
    return nearest_neighbor(a,vit,mit->second);
}
token&best_extension(token&a,token&b)
{
    if (a.e != b.e)
        return a.e > b.e ? a : b;
    return a.s > b.s ? a : b;
}
token&best_extension(token&a,const vector<token>::iterator&b)
{
    return best_extension(a,*b);
}
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<size_t,input,greater<size_t>>m;
    map<size_t,input,greater<size_t>>::iterator mit;
    bool stop;string t;int n,k,s,i,seq=0,e=INT_MIN;cin>>n;
    vector<token>::iterator found;
    vector<string>d;d.reserve(n+1);d.emplace_back("");
    token best(d[0]);
    nearest*near;
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        mit=m.try_emplace(t.length()).first;
        vector<token>&v=mit->second.v;
        if (v.empty())
        {
            v.reserve(k);
            v.emplace_back(d[seq],s);
            while (--k)
            {
                cin>>s;
                v.emplace_back(d[seq],s);
            }
        }
        else
        {
            if (v.back()<s)
            {
                v.reserve(v.size()+k);
                v.emplace_back(d[seq],s);
                while (--k)
                {
                    cin>>s;
                    v.emplace_back(d[seq],s);
                }
            }
            else
            {
                vector<token>tmp;
                tmp.reserve(k+v.size());
                for (i=0;v[i]<s;i++) tmp.push_back(v[i]);
                tmp.emplace_back(d[seq],s);
                while (--k)
                {
                    cin>>s;
                    for (;v[i]<s&&i<v.size();i++) tmp.push_back(v[i]);
                    tmp.emplace_back(d[seq],s);
                }
                for (;i<v.size();i++) tmp.push_back(v[i]);
                v.swap(tmp);
            }
        }
        mit->second.f=v.begin();
        e=std::max(e,v.back().e);
    }
    t="";
    for (s=1;s!=e;)
    {
        stop=false;
        near=nullptr;
        best=nullptr;
        for (mit=m.begin();mit!=m.end();)
        {
            vector<token>&tokens=mit->second.v;
            vector<token>::iterator&front=mit->second.f;
            vector<token>::iterator&back=--mit->second.v.end();
            if (back->e <= s) { mit=m.erase(mit);continue; }
            if (*back == s)
            {
                t+=back->t;
                s=back->e;
                mit=m.erase(mit);
                stop=true;break;
            }
            if (*back < s)
            {
                best=best_extension(*best,back);
                mit=m.erase(mit);
                break;
            }
            if (*front == s)
            {
                t+=*front->t;
                s=front->e;
                front++;
                stop=true;break;
            }
            if (*front > s)
            {
                near=nearest_neighbor(near,front,mit++);
                continue;
            }
            found=std::lower_bound(front,back,s);
            if (*found == s)
            {
                t+=*found->t;
                s=found->e;
                front=found+1;
                stop=true;break;
            }
            if ((--found)->e > s)
            {
                best=best_extension(best,found);
                front=found+1;
                mit++;
                break;
            }
            near=nearest_neighbor(near,++found,mit++);
        }
        if (stop) continue;
        if (best.unset())
        {
            n=*near-s;
            while (n--) t+=char_a;
            t+=*near->vit->t;
            s=near->vit->e;
            near->to_next_head();
            continue;
        }
        while (mit!=m.end() && s+mit->first >= best.e)
        {
            vector<token>&tokens=mit->second.v;
            vector<token>::iterator&front=mit->second.f;
            vector<token>::iterator&back=--mit->second.v.end();
            if (back->e <= s) { mit=m.erase(mit);continue; }
            if (*front > s) continue;
            if (*front == s)
            {
                best=best_extension(best,front++);
                mit++;
                continue;
            }
            if (*back <= s)
            {
                best=best_extension(best,back);
                mit=m.erase(mit);
                continue;
            }
            found=std::lower_bound(front,back,s);
            if (*found > s) --found;
            best=best_extension(best,found);
            front=found+1;
        }
        n=best-s;
        while (n++) t.pop_back();
        t+=*best.t;
        s=best.e;
    }
    cout<<t;
    return 0;
}