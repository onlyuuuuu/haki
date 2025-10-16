#include <bits/stdc++.h>
using namespace std;
class token
{
public:
    int start,end;
    string text;
    token(const int start,const int end,const string&text):start(start),end(end),text(text){}
};
class input
{
public:
    int length;
    map<int,token,greater<int>>tokens;
    explicit input(const string&text):length(static_cast<int>(text.length())){}
    explicit input(const size_t&size):length(static_cast<int>(size)){}
    token min() const{return tokens.rbegin()->second;}
    token max() const{return tokens.begin()->second;}
    int min_start() const{return tokens.rbegin()->second.start;}
    int max_start() const{return tokens.begin()->second.start;}
    const token* before(const int pos) const
    {
        if (tokens.rbegin()->second.start > pos) return nullptr;
        if (tokens.rbegin()->second.start == pos) return &tokens.rbegin()->second;
        if (tokens.begin()->second.start <= pos) return &tokens.begin()->second;
        return &tokens.lower_bound(pos)->second;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator it;
    return 0;
}