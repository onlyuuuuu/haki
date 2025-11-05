#include <bits/stdc++.h>
using namespace std;
struct token
{
    const string* t;int s,e;
    token(const int&s):s(s){}
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
struct token_compare_lt
{
    using is_transparent=void;
    bool operator()(const token&a,const int&b)const{return a.s<b;}
    bool operator()(const int&a,const token&b)const{return a<b.s;}
    bool operator()(const int&a,const int&b)const{return a<b;}
};
struct token_compare_gt
{
    using is_transparent=void;
    bool operator()(const token&a,const int&b)const{return a.s>b;}
    bool operator()(const int&a,const token&b)const{return a>b.s;}
    bool operator()(const int&a,const int&b)const{return a>b;}
};
int main()
{
    vector<token>v;v.reserve(7);
    v.push_back(token(1));
    v.push_back(token(2));
    v.push_back(token(3));
    v.push_back(token(4));
    v.push_back(token(5));
    v.push_back(token(6));
    v.push_back(token(7));
    vector<token>::iterator it;int result;
    it=std::lower_bound(v.begin(),v.end(),5);
    cout<<it->s<<" - "<<it-v.begin()<<endl;
    it=std::upper_bound(v.begin(),v.end(),5,token_compare_lt{});
    cout<<it->s<<" - "<<it-v.begin()<<endl;
    it=std::lower_bound(v.begin()+1,v.end(),2);
    cout<<it->s<<" - "<<it-v.begin()<<endl;
    it=std::lower_bound(v.begin()+2,v.end(),2);
    cout<<it->s<<" - "<<it-v.begin()<<endl;
    it=std::lower_bound(v.begin()+3,v.end(),2);
    cout<<it->s<<" - "<<it-v.begin()<<endl;
    it=std::lower_bound(v.begin()+4,v.end(),2);
    cout<<it->s<<" - "<<it-v.begin()<<endl;
    return 0;
}
