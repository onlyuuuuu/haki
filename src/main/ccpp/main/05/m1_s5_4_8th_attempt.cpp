#include <bits/stdc++.h>
using namespace std;
struct input;
struct token
{
    int start,end;
    string text;
    token(int start,string text):start(start),end(start+static_cast<int>(text.length())),text(text){}
};
struct input
{
    map<int,token,greater<int>>tokens;
    input(){}
};
struct nor
{
    map<int,token,greater<int>>::iterator token_it;
    map<int,input,greater<int>>::iterator input_it;
    nor
    (
        map<int,token,greater<int>>::iterator token_it,
        map<int,input,greater<int>>::iterator input_it
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
optional<token> max_end_in_range
(
    optional<token> a,
    optional<token> b
)
{
    if (!a) return b;
    if (!b) return a;
    return a->end > b->end ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator it;
    map<int,token,greater<int>>::iterator h,found;
    optional<token> best;
    optional<nor> next;
    bool stop;string s,t;int n,k,start,end;cin>>n;
    while (n--)
    {
        cin>>t>>k>>start;
        auto&input=m.try_emplace(static_cast<int>(t.length())).first->second;
        auto&tokens=input.tokens;
        h=tokens.emplace(piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t)).first;
        while (--k)
        {
            cin>>start;
            h=tokens.emplace_hint(h,piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t));
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
                s+=it->second.tokens.rbegin()->second.text;
                start=it->second.tokens.rbegin()->second.end;
                it->second.tokens.erase(std::prev(it->second.tokens.end()));
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                stop=true;break;
            }
            if (it->second.tokens.begin()->first == start)
            {
                s+=it->second.tokens.begin()->second.text;
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
                best=max_end_in_range(best,it->second.tokens.begin()->second);
                it=m.erase(it);
                break;
            }
            found=it->second.tokens.lower_bound(start);
            if (found->first == start)
            {
                s+=found->second.text;
                start=found->second.end;
                it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found)); // O(n)
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                stop=true;break;
            }
            if (found->second.end <= start)
            {
                next=min_start_off_range(next,nor(it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found)),it)); // O(n)
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                continue;
            }
            best=max_end_in_range(best,found->second);
            it++;
            break;
        }
        if (stop) continue;
        if (!best)
        {
            n=next->token_it->second.start-start;
            while (n--) s+='a';
            s+=next->token_it->second.text;
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
        while (it != m.end() && start + it->first > best->end)
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
                best=max_end_in_range(best,std::prev(it->second.tokens.end())->second);
                it->second.tokens.erase(std::prev(it->second.tokens.end()));
                if (it->second.tokens.empty()) it=m.erase(it); else it++;
                continue;
            }
            if (it->second.tokens.begin()->first <= start)
            {
                best=max_end_in_range(best,it->second.tokens.begin()->second);
                it=m.erase(it);
                continue;
            }
            found=it->second.tokens.lower_bound(start);
            best=max_end_in_range(best,found->second);
            it->second.tokens.erase(found);
            if (it->second.tokens.empty()) it=m.erase(it); else it++;
        }
        n=start-best->start;
        while (n--) s.pop_back();
        s+=best->text;
        start=best->end;
    }
    cout<<s;
    return 0;
}