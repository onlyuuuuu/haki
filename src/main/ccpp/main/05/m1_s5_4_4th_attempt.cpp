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
        this->id=0;
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
};
void merge_only_left(map<int,entry>& m, input& top, map<int,entry>::iterator& i)
{
    auto extracted=m.extract(i);
    extracted.mapped().text+=extracted.key()==top.start?top.text():top.text().substr(extracted.key()-top.start);
    extracted.key()=top.end;
    m.insert(std::move(extracted));
}
void merge_only_right(map<int,entry>& m, input& top, map<int,entry>::iterator& i)
{
    i->second.text=(i->second.start==top.end?top.text():top.text().substr(0,i->second.start-top.start))+i->second.text;
    i->second.start=top.start;
}
void merge_both_left_and_right(map<int,entry>& m, input& top, map<int,entry>::iterator& left, map<int,entry>::iterator& right)
{
    left->second.text+=left->first==top.start?top.text():top.text().substr(left->first-top.start);
    right->second.text=(top.end==right->second.start?left->second.text:left->second.text.substr(0,right->second.start-left->second.start))+right->second.text;
    right->second.start=left->second.start;
    m.erase(left);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string t;int _start=INT_MAX,_end=INT_MIN,n,k,x,e;cin>>n;dictionary.reserve(n);
    priority_queue<input,vector<input>,input_comparator>q;
    map<int,entry>m;
    pair<map<int,entry>::iterator,map<int,entry>::iterator>r;
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
    m.emplace(piecewise_construct,forward_as_tuple(top.end),forward_as_tuple(top.text(),top.start));
    for (;!q.empty() && !( m.begin()->second.start==_start && m.begin()->first==_end );q.pop())
    {
        top=q.top();
        r=m.equal_range(top.start);
        if (r.first == m.end() || r.first->second.start > top.end)
        {
            m.emplace(piecewise_construct,forward_as_tuple(top.end),forward_as_tuple(top.text(),top.start));
            continue;
        }
        if (r.first->second.start <= top.start && r.first->first >= top.end) continue;
        r.second = r.first == r.second ? ++r.second : r.second;
        if (r.first->second.start < top.start)
        {
            if (r.second != m.end() && r.second->second.start > top.start && r.second->second.start <= top.end)
                merge_both_left_and_right(m,top,r.first,r.second);
            else merge_only_left(m,top,r.first);
        }
        else merge_only_right(m,top,r.first);
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