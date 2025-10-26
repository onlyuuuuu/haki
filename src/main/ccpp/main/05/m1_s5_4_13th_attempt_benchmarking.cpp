#include <bits/stdc++.h>
using namespace std;
struct token
{
    const string* t;
    int s,e;
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
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<size_t,vector<token>,greater<size_t>>m;
    map<size_t,vector<token>,greater<size_t>>::iterator mit;
    queue<token>q;
    string t;int n,k,s,i,seq=-1;cin>>n;
    vector<string>d;d.reserve(n);
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        auto&v=m.try_emplace(t.length()).first->second;
        if (v.empty())
        {
            v.reserve(k);
            v.emplace_back(&t,s);
            while (--k)
            {
                cin>>s;
                v.emplace_back(&t,s);
            }
        }
        else
        {
            if (v.back()<s)
            {
                v.reserve(v.size()+k);
                v.emplace_back(&t,s);
                while (--k)
                {
                    cin>>s;
                    v.emplace_back(&t,s);
                }
            }
            else
            {
                vector<token>tmp;
                tmp.reserve(k+v.size());
                for (i=0;v[i]<s;i++) tmp.push_back(v[i]);
                tmp.emplace_back(&t,s);
                while (--k)
                {
                    cin>>s;
                    for (;v[i]<s&&i<v.size();i++) tmp.push_back(v[i]);
                    tmp.emplace_back(&t,s);
                }
                for (;i<v.size();i++) tmp.push_back(v[i]);
                v=tmp;
            }
        }
    }
    return 0;
}