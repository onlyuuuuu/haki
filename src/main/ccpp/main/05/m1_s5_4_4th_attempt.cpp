#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
static vector<string> dictionary;
class input
{
public:
    int id,start,end;
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
    int start,end;
    entry(string text,int start)
    {
        this->text=text;
        this->start=start;
        this->end=start+static_cast<int>(text.length());
    }
    entry(string text,int start,int end)
    {
        this->text=text;
        this->start=start;
        this->end=end;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;int start=INT_MAX,end=INT_MIN,n,k,x,e;cin>>n;dictionary.reserve(n);
    priority_queue<input,vector<input>,input_comparator>q;
    map<int,entry>m;
    map<int,entry>::iterator it;
    pair<map<int,entry>::iterator,map<int,entry>::iterator>f;
    for (int i=0;i<n;i++)
    {
        cin>>t>>k>>x;dictionary.push_back(t);
        e=x+static_cast<int>(t.length());
        start=min(start,x);
        q.emplace(i,x,e);
        for (--k;k>1;k--)
        {
            cin>>x;
            q.emplace(i,x);
        }
        if (k==0){end=max(end,e);continue;}
        cin>>x;e=x+static_cast<int>(t.length());
        end=max(end,e);
        q.emplace(i,x,e);
    }
    input top=q.top();q.pop();
    m.emplace(piecewise_construct,forward_as_tuple(top.end),forward_as_tuple(top.text(),top.start,top.end));
    for (;!q.empty() && ( m.begin()->second.start==start && m.begin()->second.end==end );q.pop())
    {
        top=q.top();
        f=m.equal_range(top.start);
        if (f.first == m.end() || f.first->second.start > top.end)
        {
            m.emplace_hint
            (
                m.begin(),
                piecewise_construct,
                forward_as_tuple(top.end),
                forward_as_tuple(top.text(),top.start,top.end)
            );
            continue;
        }
        if (f.first->second.start <= top.start && f.first->second.end >= top.end) continue;
        if (f.first->second.start < top.start)
        {
            if (f.second == m.end() || f.second->second.start > top.end)
            {
                auto node=m.extract(f.first);
                node.key()=top.end;
                node.mapped().end=top.end;
                node.mapped().text+=top.text().substr( node.mapped().start - top.start );
                m.insert(move(node));
            }
            else
            {

            }
        }
        if (f.first->second.start > top.start)
        {

        }
    }
    return 0;
}