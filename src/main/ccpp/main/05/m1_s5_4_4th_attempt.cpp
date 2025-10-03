#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
struct entry{string text;int start,end;};
struct compare
{
    bool operator()(const string& a,const string& b) const
    {
        if (a.length() != b.length())
            return a.length() < b.length();
        return a < b;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string,set<int,greater<>>,compare>input;
    map<int,entry>m;
    map<int,entry>::iterator it;
    string s;int start=INT_MAX,end=INT_MIN,n,k,x;cin>>n;
    for (;n>0;n--)
    {
        cin>>s>>k>>x;
        start=min(start,x);
        set<int,greater<>>st;st.insert(x);input[s]=st;
        for (--k;k>1;k--)
        {
            cin>>x;
            input[s].insert(input[s].begin(),x);
        }
        if (k==0)
        {
            end=max(end,x+static_cast<int>(s.length()));
            continue;
        }
        cin>>x;
        input[s].insert(input[s].begin(),x);
        end=max(end,x+static_cast<int>(s.length()));
    }
    return 0;
}