#include <bits/stdc++.h>
using namespace std;
struct input;
struct token
{
    int end;
    string text;
    input*owner;
    token(int start,string text,input*owner):end(start+static_cast<int>(text.length())),text(text),owner(owner){}
};
struct input
{
    map<int,token,greater<int>>tokens;
    map<int,input,greater<int>>*inputs;
    input(map<int,input,greater<int>>*inputs):inputs(inputs){}
};
optional<map<int,token,greater<int>>::iterator> min_start_off_range
(
    const optional<map<int,token,greater<int>>::iterator>& a,
    const optional<map<int,token,greater<int>>::iterator>& b
)
{
    if (!a) return b;
    if (!b) return a;
    return ((*a)->first < (*b)->first) ? a : b;
}
optional<map<int,token,greater<int>>::iterator> max_end_in_range
(
    const optional<map<int,token,greater<int>>::iterator>& a,
    const optional<map<int,token,greater<int>>::iterator>& b
)
{
    if (!a) return b;
    if (!b) return a;
    return ((*a)->second.end > (*b)->second.end) ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator it;
    map<int,token,greater<int>>::iterator h,found;
    optional<map<int,token,greater<int>>::iterator> next,best;
    string s,t;int n,k,start,end;cin>>n;
    while (n--)
    {
        cin>>t>>k>>start;
        auto&input=m.try_emplace(static_cast<int>(t.length()),&m).first->second;
        auto&tokens=input.tokens;
        h=tokens.emplace(piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t,&input)).first;
        while (--k)
        {
            cin>>start;
            h=tokens.emplace_hint(h,piecewise_construct,forward_as_tuple(start),forward_as_tuple(start,t,&input));
        }
        end=max(end,h->second.end);
    }
    for (start=1;start!=end;)
    {
        [&]{
            for (it=m.begin();it!=m.end();)
            {
                if (it->second.tokens.rbegin()->first == start)
                {
                    s+=it->second.tokens.rbegin()->second.text;
                    start=it->second.tokens.rbegin()->second.end;
                    if (it->second.tokens.size()==1)
                        it=m.erase(it);
                    else
                    {
                        it->second.tokens.erase(std::prev(it->second.tokens.end()));
                        it++;
                    }
                    return;
                }
                if (it->second.tokens.begin()->first == start)
                {
                    s+=it->second.tokens.begin()->second.text;
                    start=it->second.tokens.begin()->second.end;
                    it=m.erase(it);
                    return;
                }
                if (it->second.tokens.rbegin()->first > start)
                {
                    next=min_start_off_range(next,std::prev(it->second.tokens.end()));
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
                    best=max_end_in_range(best,it->second.tokens.begin());
                    it=m.erase(it);
                    break;
                }
                found=it->second.tokens.lower_bound(start);
                if (found->first == start)
                {
                    s+=found->second.text;
                    start=found->second.end;
                    it->second.tokens.erase(found);
                    //it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found));
                    it++;
                    return;
                }
                if (found->second.end <= start)
                {
                    //next=min_start_off_range(next,found++);
                    //next=min_start_off_range(next,std::next(found));
                    next=min_start_off_range(next,it->second.tokens.erase(found));
                    //next=min_start_off_range(next,it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found)));
                    it++;
                    continue;
                }
                best=max_end_in_range(best,found);
                it++;
                break;
            }
            if (!best)
            {
                auto&nx=*next;
                n=nx->first-start;
                while (n--) s+='a';
                s+=nx->second.text;
                start=nx->second.end;
                nx->second.owner->tokens.erase(nx);
                return;
            }
            auto&bs=*best;
            while (it!=m.end() && start+it->first>bs->second.end)
            {
                if (it->second.tokens.rbegin()->first == start)
                {
                    best=max_end_in_range(best,std::prev(it->second.tokens.end()));
                    if (it->second.tokens.size()==1)
                        it=m.erase(it);
                    else
                    {
                        it->second.tokens.erase(std::prev(it->second.tokens.end()));
                        it++;
                    }
                    continue;
                }
                if (it->second.tokens.begin()->first == start)
                {
                    best=max_end_in_range(best,it->second.tokens.begin());
                    it=m.erase(it);
                    continue;
                }
                if (it->second.tokens.rbegin()->first > start)
                {
                    it++;
                    continue;
                }
                if (it->second.tokens.begin()->first < start)
                {
                    best=max_end_in_range(best,it->second.tokens.begin());
                    it=m.erase(it);
                    continue;
                }
                if (it->second.tokens.begin()->first <= start)
                {
                    best=it->second.tokens.begin();
                    it=m.erase(it);
                    continue;
                }
                found=it->second.tokens.lower_bound(start);
                best=max_end_in_range(best,found);
                it++;
            }
            n=bs->first-start;
            while (n--) s.pop_back();
            s+=bs->second.text;
            start=bs->second.end;
        }();
    }
    cout<<s;
    return 0;
}
