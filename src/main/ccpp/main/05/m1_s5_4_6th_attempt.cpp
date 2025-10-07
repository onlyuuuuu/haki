#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
static vector<string> dictionary;
class input
{
public:
    int _id,_start;
    input(){}
    input(int id,int start):_id(id),_start(start){}
    string get_text() const
    {
        return dictionary[_id];
    }
    int length() const
    {
        return dictionary[_id].length();
    }
    void replace_longer_string(int id,int start)
    {
        if (dictionary[id].length()>dictionary[_id].length())
        {
            this->_id=id;
            this->_start=start;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string result,t;int n,k,x,e,i=-1;cin>>n;
    map<int,input>m;
    map<int,input>::iterator it;
    cin>>t>>k>>x;
    dictionary.push_back(t);++i;
    it=m.emplace(piecewise_construct,forward_as_tuple(x+static_cast<int>(t.length())),forward_as_tuple(i,x)).first;
    while (--k)
    {
        cin>>x;
        it=m.emplace_hint(it,piecewise_construct,forward_as_tuple(x+static_cast<int>(t.length())),forward_as_tuple(i,x));
    }
    while (--n)
    {
        cin>>t>>k>>x;
        dictionary.push_back(t);++i;
        e=x+static_cast<int>(t.length());
        while (--k)
        {
            cin>>x;
            e=x+static_cast<int>(t.length());
        }
    }
    if (m.rbegin()->second._start==1)
    {
        cout<<m.rbegin()->second.get_text();
        return 0;
    }
    cout<<result;
    return 0;
}