#include <bits/stdc++.h>
using namespace std;
struct token
{
    std::string_view txt;
    int str=0,end=0;
    token()=default;
    token(const string&t,const int&s):txt(t),str(s),end(s+static_cast<int>(t.length())){}
};
struct input
{
    vector<token>::iterator frt;
    vector<token>v;
    input()=default;
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;
    cout<<t;
    return 0;
}