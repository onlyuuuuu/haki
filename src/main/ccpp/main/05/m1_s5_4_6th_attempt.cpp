#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
static class input
{
public:
    string text;int start,end;
    input(){}
    input(string text,int start):text(text),start(start),end(start+static_cast<int>(text.length())){}
    input(string text,int start, int end):text(text),start(start),end(end){}
    int length() const{return text.length();}
};
static void merge_only_left(map<int,input>& m, input& top, map<int,input>::iterator& i)
{
    auto extracted=m.extract(i);
    extracted.mapped().text+=extracted.key()==top.start?top.text:top.text.substr(extracted.key()-top.start);
    extracted.key()=top.end;
    m.insert(std::move(extracted));
}
static void merge_only_right(map<int,input>& m, input& top, map<int,input>::iterator& i)
{
    i->second.text=(i->second.start==top.end?top.text:top.text.substr(0,i->second.start-top.start))+i->second.text;
    i->second.start=top.start;
}
static void merge_both_left_and_right(map<int,input>& m, input& top, map<int,input>::iterator& left, map<int,input>::iterator& right)
{
    left->second.text+=left->first==top.start?top.text:top.text.substr(left->first-top.start);
    right->second.text=(top.end==right->second.start?left->second.text:left->second.text.substr(0,right->second.start-left->second.start))+right->second.text;
    right->second.start=left->second.start;
    m.erase(left);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string result,t;int n,k,x,e;cin>>n;
    map<int,input>m;
    map<int,input>::iterator it;
    stack<int>st;
    cin>>t>>k>>x;

    while (--k)
    {
        cin>>x;

    }
    while (--n)
    {
        cin>>t>>k>>x;
        e=x+static_cast<int>(t.length());
        while (--k)
        {
            cin>>x;
            e=x+static_cast<int>(t.length());
        }
    }
    cout<<result;
    return 0;
}