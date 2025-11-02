#include <bits/stdc++.h>
using namespace std;
struct token
{
    std::string_view t;int s=0,e=0;
    token()=default;
    token(const string&t):t(t),s(0),e(0){}
    token(const string&t,const int&s):t(t),s(s),e(s+static_cast<int>(t.length())){}
    int operator-(const int&i)const{return s-i;}
    bool operator!=(const token&tk)const{return s!=tk.s;}
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
    bool operator!()const{return s==0;}
    explicit operator bool()const{return s==0;}
    token&operator=(const int&i){s=i;return*this;}
};
inline int operator-(const int&i,const token&o){return i-o.s;}
inline bool operator!=(const int&i,const token&tk){return i!=tk.s;}
inline bool operator==(const int&i,const token&tk){return i==tk.s;}
inline bool operator<(const int&i,const token&tk){return i<tk.s;}
inline bool operator<=(const int&i,const token&tk){return i<=tk.s;}
inline bool operator>(const int&i,const token&tk){return i>tk.s;}
inline bool operator>=(const int&i,const token&tk){return i>=tk.s;}
struct input
{
    vector<token>v;
    vector<token>::iterator f;
    input()=default;
};
struct nearest
{
    input*inp=nullptr;
    vector<token>::iterator vit;
    nearest()=default;
    nearest(const vector<token>::iterator&vit,input&inp):inp(&inp),vit(vit){}
    nearest&shift_left(){inp->f=vit+1;return*this;}
    nearest&operator=(const int&i){inp=nullptr;return*this;}
    bool operator!()const{return inp==nullptr;}
    explicit operator bool()const{return inp==nullptr;}
    int operator-(const int&i)const{return*vit-i;}
};
inline int operator-(const int&i,const nearest&n){return i-*n.vit;}
const nearest& nearest_neighbor(const nearest&a,const nearest&b)
{
    if (!a) return b;
    if (*a.vit != *b.vit)
        return *a.vit < *b.vit ? a : b;
    return *a.vit > *b.vit ? a : b;
}
const nearest& nearest_neighbor(const nearest&a,const vector<token>::iterator&vit,input&inp)
{
    return nearest_neighbor(a,nearest(vit,inp));
}
const nearest& nearest_neighbor(const nearest&a,const vector<token>::iterator&vit,const map<int,input,greater<int>>::iterator&mit)
{
    return nearest_neighbor(a,vit,mit->second);
}
const token& best_extension(const token&a,const token&b)
{
    if (a.e != b.e)
        return a.e > b.e ? a : b;
    return a.s > b.s ? a : b;
}
const token& best_extension(const token&a,const vector<token>::iterator&b)
{
    return best_extension(a,*b);
}
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator mit;
    bool stop;string t;int x,s,e=INT_MIN;size_t n,k,i,seq=-1ull;cin>>n;
    vector<token>::iterator found;
    vector<string>d;d.reserve(static_cast<size_t>(n));
    token best;nearest near;
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        mit=m.try_emplace(static_cast<int>(t.length())).first;
        vector<token>&v=mit->second.v;
        if (v.empty())
        {
            v.reserve(static_cast<size_t>(k));
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
                    for (;i<v.size()&&v[i]<s;i++) tmp.push_back(v[i]);
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
        near=0;best=0;
        for (mit=m.begin();mit!=m.end();)
        {
            if (mit->second.v.back().e <= s) { mit=m.erase(mit);continue; }
            if (mit->second.v.back() == s)
            {
                t+=mit->second.v.back().t;
                s=mit->second.v.back().e;
                mit=m.erase(mit);
                stop=true;break;
            }
            if (mit->second.v.back() < s)
            {
                best=best_extension(best,mit->second.v.back());
                mit=m.erase(mit);
                break;
            }
            if (*mit->second.f == s)
            {
                t+=mit->second.f->t;
                s=mit->second.f->e;
                mit->second.f++;
                stop=true;break;
            }
            if (*mit->second.f > s)
            {
                near=nearest_neighbor(near,mit->second.f,mit++);
                continue;
            }
            found=std::lower_bound(mit->second.f,mit->second.v.end(),s);
            if (*found == s)
            {
                t+=found->t;
                s=found->e;
                mit->second.f=found+1;
                stop=true;break;
            }
            if ((--found)->e > s)
            {
                best=best_extension(best,found);
                mit->second.f=found+1;
                mit++;
                break;
            }
            near=nearest_neighbor(near,++found,mit++);
        }
        if (stop) continue;
        if (!best)
        {
            x=*near.vit-s;
            while (x--) t+=char_a;
            t+=near.vit->t;
            s=near.vit->e;
            near.shift_left();
            continue;
        }
        while (mit!=m.end() && s + mit->first >= best.e)
        {
            if (mit->second.v.back().e <= best.e) { mit=m.erase(mit);continue; }
            if (*mit->second.f > s) { mit++;continue; };
            if (*mit->second.f == s)
            {
                best=best_extension(best,mit->second.f++);
                mit++;
                continue;
            }
            if (mit->second.v.back() <= s)
            {
                best=best_extension(best,mit->second.v.back());
                mit=m.erase(mit);
                continue;
            }
            found=std::lower_bound(mit->second.f,mit->second.v.end(),s);
            if (*found > s) --found;
            best=best_extension(best,found);
            mit->second.f=found+1;
            mit++;
        }
        x=s-best;
        while (x--) t.pop_back();
        t+=best.t;
        s=best.e;
    }
    cout<<t;
    return 0;
}