#include<bits/stdc++.h>
using namespace std;
struct token
{
    std::string_view txt;
    int str=0,end=0;
    token()=default;
    token(const string&t,const int&s):txt(t),str(s),end(s+t.length()){}
};
struct input
{
    vector<token>::iterator front;
    vector<token>tokens;
    input()=default;
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
        end=std::max(end,v.back().end);
    }
    cout<<t<<'\n';
    return 0;
}