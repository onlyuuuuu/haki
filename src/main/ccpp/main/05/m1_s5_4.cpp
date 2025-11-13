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
    string t;int i,k,n;int start,end=INT_MAX;cin>>n;
    vector<string>d;d.reserve(n);
    while(n--)
    {
        cin>>t>>k>>start;
        d.emplace_back(t);
        auto&v=m.try_emplace(t.length()).first->second.tokens;
        
        end=std::max(end,v.back().end);
    }
    cout<<t<<'\n';
    return 0;
}