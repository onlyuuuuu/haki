#include <bits/stdc++.h>
using namespace std;
struct input;
struct token
{
    int start,end;
    token(int start,size_t length):start(start),end(start+static_cast<int>(length)){}
};
struct input
{
    map<int,token,greater<int>>tokens;
    input(){}
};
struct string_compare
{
    bool operator()(const string& a, const string& b) const
    {
        return a.length() > b.length();
    }
};
struct bir
{
    token tkn;
    string txt;
    bir(token tkn,string txt):tkn(tkn),txt(txt){}
};
struct nor
{
    map<int,token,greater<int>>::iterator token_it;
    multimap<string,input,string_compare>::iterator input_it;
    nor
    (
        map<int,token,greater<int>>::iterator token_it,
        multimap<string,input,string_compare>::iterator input_it
    ):token_it(token_it),input_it(input_it){}
};
optional<nor> min_start_off_range
(
    optional<nor> a,
    optional<nor> b
)
{
    if (!a) return b;
    if (!b) return a;
    return a->token_it->second.start < b->token_it->second.start ? a : b;
}
optional<bir> max_end_in_range
(
    optional<bir> a,
    optional<bir> b
)
{
    if (!a) return b;
    if (!b) return a;
    return a->tkn.end > b->tkn.end ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    multimap<string,input,string_compare>m;
    multimap<string,input,string_compare>::iterator it;
    map<int,token,greater<int>>::iterator h,found;
    optional<bir> best;
    optional<nor> next;
    bool stop;string s,t;int n,k,start,end=0;cin>>n;
    while (n--)
    {
        cin>>t>>k>>start;
        auto&input=m.emplace(piecewise_construct,forward_as_tuple(t),forward_as_tuple())->second;
        auto&tokens=input.tokens;
        h=tokens.emplace(piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t.length())).first;
        while (--k)
        {
            cin>>start;
            h=tokens.emplace_hint(h,piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t.length()));
        }
        end=max(end,h->second.end);
    }
    for (start=1;start!=end;)
    {
        stop=false;
        best.reset();
        next.reset();
        for (it=m.begin();it!=m.end();)
        {
            if (it->second.tokens.empty())
            {
                it=m.erase(it);
                continue;
            }
            if (it->second.tokens.rbegin()->first == start)
            {
                s+=it->first;
                start=it->second.tokens.rbegin()->second.end;
                it->second.tokens.erase(std::prev(it->second.tokens.end()));
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                stop=true;break;
            }
            if (it->second.tokens.begin()->first == start)
            {
                s+=it->first;
                start=it->second.tokens.begin()->second.end;
                it=m.erase(it);
                stop=true;break;
            }
            if (it->second.tokens.rbegin()->first > start)
            {
                next=min_start_off_range(next,nor(std::prev(it->second.tokens.end()),it));
                it++;
                continue;
            }
            if (it->second.tokens.begin()->first < start)
            {
                if (it->second.tokens.begin()->second.end <= start)
                {
                    it=m.erase(it);
                    continue;
                }
                best=max_end_in_range(best,bir(it->second.tokens.begin()->second,it->first));
                it=m.erase(it);
                break;
            }
            found=it->second.tokens.lower_bound(start);
            if (found->first == start)
            {
                s+=it->first;
                start=found->second.end;
                it->second.tokens.erase(found,it->second.tokens.end()); // O(n)
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                stop=true;break;
            }
            if (found->second.end <= start)
            {
                next=min_start_off_range(next,nor(std::prev(it->second.tokens.erase(found,it->second.tokens.end())),it)); // O(n)
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                continue;
            }
            best=max_end_in_range(best,bir(found->second,it->first));
            it++;
            break;
        }
        if (stop) continue;
        if (!best)
        {
            n=next->token_it->second.start-start;
            while (n--) s+='a';
            s+=next->input_it->first;
            start=next->token_it->second.end;
            next->input_it->second.tokens.erase(next->token_it);
            if (next->input_it->second.tokens.empty()) m.erase(next->input_it);
            continue;
        }
        if (it->second.tokens.empty())
        {
            it=m.erase(it);
            continue;
        }
        while (it != m.end() && start + static_cast<int>(it->first.length()) > best->tkn.end)
        {
            if (it->second.tokens.empty())
            {
                it=m.erase(it);
                continue;
            }
            if (it->second.tokens.rbegin()->first > start)
            {
                it++;
                continue;
            }
            if (it->second.tokens.rbegin()->first == start)
            {
                best=max_end_in_range(best,bir(std::prev(it->second.tokens.end())->second,it->first));
                it->second.tokens.erase(std::prev(it->second.tokens.end()));
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                continue;
            }
            if (it->second.tokens.begin()->first <= start)
            {
                best=max_end_in_range(best,bir(it->second.tokens.begin()->second,it->first));
                it=m.erase(it);
                continue;
            }
            found=it->second.tokens.lower_bound(start);
            best=max_end_in_range(best,bir(found->second,it->first));
            it->second.tokens.erase(found,it->second.tokens.end()); // O(n)
            if (it->second.tokens.empty()) it=m.erase(it); else it++;
        }
        n=start-best->tkn.start;
        while (n--) s.pop_back();
        s+=best->txt;
        start=best->tkn.end;
    }
    cout<<s;
    return 0;
}