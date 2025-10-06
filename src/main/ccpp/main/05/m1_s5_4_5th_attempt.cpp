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
    pair<map<int,input>::iterator,bool>irp;
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
        it=m.emplace(piecewise_construct,forward_as_tuple(e),forward_as_tuple(i,x)).first;
        it->second.replace_longer_string(i,x);
        while (--k)
        {
            cin>>x;
            e=x+static_cast<int>(t.length());
            it=m.emplace_hint(it,piecewise_construct,forward_as_tuple(e),forward_as_tuple(i,x));
            it->second.replace_longer_string(i,x);
        }
    }
    if (m.rbegin()->second._start==1)
    {
        cout<<m.rbegin()->second.get_text();
        return 0;
    }
    n=m.rbegin()->second._start;
    result=m.rbegin()->second.get_text();
    m.erase(--m.end());
    for (it=m.lower_bound(n);!m.empty();it=m.lower_bound(n))
    {
        if (it->second._start==1)
        {
            cout<<((it->first==n)?it->second.get_text():it->second.get_text().substr(0,n-it->second._start))<<result;
            return 0;
        }
        while (it!=m.end() && it->second._start>=n) it=m.erase(it);
        if (it==m.end())
        {
            --it;
            for (k=n-it->first;k--;) result=char_a+result;
            result=it->second.get_text()+result;
        }
        else result=((it->first==n)?it->second.get_text():it->second.get_text().substr(0,n-it->second._start))+result;
        n=it->second._start;
    }
    for (k=n-1;k--;) cout<<char_a;
    cout<<result;
    return 0;
}