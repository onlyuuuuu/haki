#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
static vector<string> dictionary;
class input
{
public:
    int id,start,end;
    input()
    {
        this->id=-1;
        this->start=0;
        this->end=0;
    }
    input(int id,int start)
    {
        this->id=id;
        this->start=start;
        this->end=start+static_cast<int>(dictionary[id].length());
    }
    input(int id,int start,int end)
    {
        this->id=id;
        this->start=start;
        this->end=end;
    }
    string text() const
    {
        return dictionary[id];
    }
    int length() const
    {
        return static_cast<int>(dictionary[id].length());
    }
};
struct input_comparator
{
    bool operator()(const input&a, const input&b) const
    {
        return a.length()!=b.length()?a.length()<b.length():a.end<b.end;
    }
};
class entry
{
public:
    string text;
    int start;
    entry()
    {
        this->text="";
        this->start=0;
    }
    entry(string text,int start)
    {
        this->text=text;
        this->start=start;
    }
    entry(string text,int start,int end)
    {
        this->text=text;
        this->start=start;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;int _start=INT_MAX,_end=INT_MIN,n,k,x,e;cin>>n;dictionary.reserve(n);
    priority_queue<input,vector<input>,input_comparator>q;
    map<int,entry>m;
    map<int,entry>::node_type extracted;
    pair<map<int,entry>::iterator,map<int,entry>::iterator>f;
    for (int i=0;i<n;i++)
    {
        cin>>t>>k>>x;dictionary.push_back(t);
        e=x+static_cast<int>(t.length());
        _start=min(_start,x);
        q.emplace(i,x,e);
        for (--k;k>1;k--)
        {
            cin>>x;
            q.emplace(i,x);
        }
        if (k==0){_end=max(_end,e);continue;}
        cin>>x;e=x+static_cast<int>(t.length());
        _end=max(_end,e);
        q.emplace(i,x,e);
    }
    entry deleted;input top=q.top();q.pop();
    m.emplace(piecewise_construct,forward_as_tuple(top.end),forward_as_tuple(top.text(),top.start,top.end));
    for (;!q.empty() && !( m.begin()->second.start==_start && m.begin()->first==_end );q.pop())
    {
        top=q.top();
        f=m.equal_range(top.start);
        if (f.first == m.end() || f.first->second.start > top.end)
        {
            m.emplace(piecewise_construct,forward_as_tuple(top.end),forward_as_tuple(top.text(),top.start,top.end));
            continue;
        }
        if (f.first->second.start <= top.start && f.first->first >= top.end)
            continue;
        if (f.first->second.start < top.start)
        {
            if (f.second == m.end() || f.first == f.second || f.second->second.start > top.end)
            {
                extracted=m.extract(f.first);
                extracted.mapped().text+=extracted.key()==top.start?top.text():top.text().substr(extracted.key()-top.start);
                extracted.key()=top.end;
                m.insert(move(extracted));
                continue;
            }
            else
            {
                k=f.first->first;deleted=f.first->second;m.erase(f.first);
                deleted.text+=k==top.start?top.text():top.text().substr(n);
                f.second->second.text=(top.end==f.second->second.start?deleted.text:deleted.text.substr(0,f.second->second.start-deleted.start))+f.second->second.text;
                f.second->second.start=deleted.start;
                continue;
            }
        }
        f.first->second.text=(f.first->second.start==top.end?top.text():top.text().substr(0,f.first->second.start-top.start))+f.second->second.text;
        f.first->second.start=top.start;
    }
    n=1;
    for (const auto&[end,entry]:m)
    {
        for (k=entry.start-n;k>0;k--)cout<<char_a;
        cout<<entry.text;
        n=end;
    }
    return 0;
}