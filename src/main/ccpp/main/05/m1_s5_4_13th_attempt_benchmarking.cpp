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
    token&operator=(const int&i){s=0;return*this;}
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
    if (!b) return a;
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
    bool stop;string t;int n,k,s,i,seq=-1,e=INT_MIN;cin>>n;
    vector<token>::iterator found;
    vector<string>d;d.reserve(n);
    token best;nearest near;
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        mit=m.try_emplace(static_cast<int>(t.length())).first;
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
                v.reserve(static_cast<int>(v.size())+k);
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
                tmp.reserve(k+static_cast<int>(v.size()));
                for (i=0;v[i]<s;i++) tmp.push_back(v[i]);
                tmp.emplace_back(d[seq],s);
                while (--k)
                {
                    cin>>s;
                    for (;i<static_cast<int>(v.size())&&v[i]<s;i++) tmp.push_back(v[i]);
                    tmp.emplace_back(d[seq],s);
                }
                for (;i<static_cast<int>(v.size());i++) tmp.push_back(v[i]);
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
            auto&tokens=mit->second.v;
            auto&front=mit->second.f;
            auto&back=--mit->second.v.end();
            auto&front_token=*front;
            auto&back_token=*back;
            if (back_token.e <= s) { mit=m.erase(mit);continue; }
            if (back_token == s)
            {
                t+=back_token.t;
                s=back_token.e;
                mit=m.erase(mit);
                stop=true;break;
            }
            if (back_token < s)
            {
                best=best_extension(best,back);
                mit=m.erase(mit);
                break;
            }
            if (front_token == s)
            {
                t+=front_token.t;
                s=front_token.e;
                front++;
                stop=true;break;
            }
            if (front_token > s)
            {
                near=nearest_neighbor(near,front,mit++);
                continue;
            }
            found=std::lower_bound(front,back,s);
            auto&found_token=*found;
            if (found_token == s)
            {
                t+=found_token.t;
                s=found_token.e;
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
        if (!best)
        {
            auto&token=*near.shift_left().vit;
            n=token-s;
            while (n--) t+=char_a;
            t+=token.t;
            s=token.e;
            continue;
        }
        while (mit!=m.end() && s+mit->first >= best.e)
        {
            auto&tokens=mit->second.v;
            auto&front=mit->second.f;
            auto&back=--mit->second.v.end();
            auto&front_token=*front;
            auto&back_token=*back;
            if (back_token.e <= s) { mit=m.erase(mit);continue; }
            if (front_token > s) { mit++;continue; };
            if (front_token == s)
            {
                best=best_extension(best,front++);
                mit++;
                continue;
            }
            if (back_token <= s)
            {
                best=best_extension(best,back);
                mit=m.erase(mit);
                continue;
            }
            found=std::lower_bound(front,back,s);
            if (*found > s) --found;
            best=best_extension(best,found);
            front=found+1;
            mit++;
        }
        n=s-best;
        while (n--) t.pop_back();
        t+=best.t;
        s=best.e;
    }
    cout<<t;
    return 0;
}