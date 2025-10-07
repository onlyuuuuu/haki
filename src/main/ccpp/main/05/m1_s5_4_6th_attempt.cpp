#include <bits/stdc++.h>
using namespace std;
static constexpr char char_a='a';
static class input
{
public:
    string text;int start;
    input(){}
    input(string text,int start):text(text),start(start){}
    input(string text,int start, int end):text(text),start(start){}
    int length() const{return text.length();}
};
static void merge_only_left(map<int,input>& m, int start, int end, string text, map<int,input>::iterator& i)
{
    auto extracted=m.extract(i);
    extracted.mapped().text+=extracted.key()==start?text:text.substr(extracted.key()-start);
    extracted.key()=end;
    m.insert(std::move(extracted));
}
static void merge_only_right(map<int,input>& m, int start, int end, string text, map<int,input>::iterator& i)
{
    i->second.text=(i->second.start==end?text:text.substr(0,i->second.start-start))+i->second.text;
    i->second.start=start;
}
static void merge_both_left_and_right(map<int,input>& m, int start, int end, string text, map<int,input>::iterator& left, map<int,input>::iterator& right)
{
    left->second.text+=left->first==start?text:text.substr(left->first-start);
    right->second.text=(end==right->second.start?left->second.text:left->second.text.substr(0,right->second.start-left->second.start))+right->second.text;
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
    for (;n--;)
    {
        cin>>t>>k;
        for (;k--;)
        {
            cin>>x;
            st.emplace(x);
        }
        e=st.top()+static_cast<int>(t.length());
        m.emplace(piecewise_construct,forward_as_tuple(e),forward_as_tuple(t,st.top()));
        for (st.pop();!st.empty();st.pop())
        {
            e=st.top()+static_cast<int>(t.length());
            it=m.lower_bound(e);
            if (it==m.end()||it->second.start>e)
            {
                m.emplace(piecewise_construct,forward_as_tuple(e),forward_as_tuple(t,st.top()));
                continue;
            }
            if (it->second.start<=st.top()&&it->first>=e) continue;
            for (;it!=m.end()&&it->second.start<=e;it++)
            {
                if (it->second.start<st.top()&&it->first>=st.top()&&it->first<e)
                    merge_only_left(m,st.top(),e,t,it);
                
            }
        }
    }
    cout<<result;
    return 0;
}