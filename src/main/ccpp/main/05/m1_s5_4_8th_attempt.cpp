#include <bits/stdc++.h>
using namespace std;
class token
{
public:
    int start,end;
    string text;
    token(int start,string text):start(start),end(start+static_cast<int>(text.length())),text(text){}
    token(int start,int end,string text):start(start),end(end),text(text){}
};
static constexpr auto compare_token=[](const token&a,const token&b){return a.start<b.start;};
class input
{
public:
    int length;
    set<token,decltype(compare_token)>tokens;
    input(string t):length(static_cast<int>(t.length())){};
};
static constexpr auto compare_input=[](const input&a,const input&b){return false;};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}