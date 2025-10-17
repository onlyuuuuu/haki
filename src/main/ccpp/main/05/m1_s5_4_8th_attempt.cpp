#include <bits/stdc++.h>
using namespace std;
struct input;
struct token
{
    int end;
    string text;
    input*inp;
    token(int start,string&text,input*inp):end(start+static_cast<int>(text.length())),text(text),inp(inp){}
};
struct input
{
    map<int,token,greater<int>>tokens;
    map<int,input,greater<int>>*inputs;
    input(map<int,input,greater<int>>*inputs):inputs(inputs){}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator it,closest;
    map<int,token,greater<int>>::iterator h;
    string s,t;int n,k,start,end;cin>>n;
    const token* found;
    while (n--)
    {
        cin>>t>>k>>start;
        auto&input=m.try_emplace(static_cast<int>(t.length()),&m).first->second;
        auto&tokens=input.tokens;
        h=tokens.emplace(piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t,&input)).first;
        while (--k)
        {
            cin>>start;
            h=tokens.emplace_hint(h,piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t,&input));
        }
        end=max(end,h->second.end);
    }
    for (start=1;start!=end;)
    {
        closest=m.begin();
        for (it=m.begin();it!=m.end();it++)
        {

        }
        if (!found)
        {

        }
        n=found->end;
        for (++it;it!=m.end();it++)
        {

        }
    }
    return 0;
}