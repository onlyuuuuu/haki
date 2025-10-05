#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
class input
{
public:
    string text;
    int start,end;
    input(){}
    input(string text,int start)
    {
        this->text=text;
        this->start=start;
        this->end=start+static_cast<int>(text.length())-1;
    }
    input(string text,int start,int end)
    {
        this->text=text;
        this->start=start;
        this->end=end;
    }
};
struct comparator
{
    bool operator()(const input&a, const input&b) const
    {
        return (a.end != b.end) ? a.end > b.end : a.text.length() < b.text.length();
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string result,t;int n,k,x;cin>>n;
    multiset<input,comparator>s;
    multiset<input,comparator>::iterator i;
    for (;n>0;n--)
    {
        cin>>t>>k>>x;
        i=s.emplace(t,x);
        for (--k;k>0;k--)
        {
            cin>>x;
            s.emplace_hint(i,t,x);
        }
    }
    for (;!s.empty();)
    {

    }
    cout<<result;
    return 0;
}