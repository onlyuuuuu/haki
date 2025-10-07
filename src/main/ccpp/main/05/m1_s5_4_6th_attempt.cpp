#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
class input
{
public:
    string _text;int _start;
    input(){}
    input(string text,int start):_text(text),_start(start){}
    input(string text,int start, int end):_text(text),_start(start){}
    int length() const
    {
        return _text.length();
    }

};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string result,t;int n,k,x,e;cin>>n;
    map<int,input>m;
    map<int,input>::iterator it;
    cin>>t>>k>>x;
    it=m.emplace(piecewise_construct,forward_as_tuple(x+static_cast<int>(t.length())),forward_as_tuple(i,x)).first;
    while (--k)
    {
        cin>>x;
        it=m.emplace_hint(it,piecewise_construct,forward_as_tuple(x+static_cast<int>(t.length())),forward_as_tuple(i,x));
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