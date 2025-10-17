#include <bits/stdc++.h>
using namespace std;
struct input;
struct token
{
    int end;
    string text;
    input*owner;
    token(int start,string&text,input*owner):end(start+static_cast<int>(text.length())),text(text),owner(owner){}
};
struct input
{
    map<int,token,greater<int>>tokens;
    map<int,input,greater<int>>*inputs;
    input(map<int,input,greater<int>>*inputs):inputs(inputs){}
};
map<int,token,greater<int>>::iterator min_start_off_range(map<int,token,greater<int>>::iterator a, map<int,token,greater<int>>::iterator b)
{
    if (a->first < b->first) return a;
    return b;
}
token* max_end_in_range(token& a, token& b)
{
    if (a.end > b.end) return &a;
    return &b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int,input,greater<int>>m;
    map<int,input,greater<int>>::iterator it;
    map<int,token,greater<int>>::iterator h,next,found;
    string s,t;int n,k,start,end;cin>>n;
    bool stop,next_off_range_found,need_further_inspection;
    token* best;
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
        stop=false;
        next_off_range_found=false;
        need_further_inspection=false;
        for (it=m.begin();it!=m.end();)
        {
            if (it->second.tokens.rbegin()->first == start)
            {
                s+=it->second.tokens.rbegin()->second.text;
                start=it->second.tokens.rbegin()->second.end;
                if (it->second.tokens.size()==1) it=m.erase(it);
                else it->second.tokens.erase(--(it->second.tokens.end()));
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
                if (!next_off_range_found)
                {
                    next=--(it->second.tokens.end());
                    next_off_range_found=true;
                }
                else next=min_start_off_range(next,--(it->second.tokens.end()));
                it++;
            }
            else if (it->second.tokens.begin()->first < start)
            {
                if (it->second.tokens.begin()->second.end <= start)
                    it=m.erase(it);
                else
                {
                    need_further_inspection=true;
                    best=!best?&(it->second.tokens.begin()->second):max_end_in_range(*best,it->second.tokens.begin()->second);
                    it=m.erase(it);
                    break;
                }
            }
            else
            {
                found=it->second.tokens.lower_bound(start);
                if (found->first == start)
                {
                    s+=found->second.text;
                    start=found->second.end;
                    it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found));
                    stop=true;break;
                }
                else if (found->second.end <= start)
                {
                    if (!next_off_range_found)
                    {
                        next=it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found));
                        next_off_range_found=true;
                    }
                    else next=min_start_off_range(next,it->second.tokens.erase(it->second.tokens.begin(),it->second.tokens.erase(found)));
                    it++;
                }
                else
                {
                    need_further_inspection=true;
                    best=!best?&(found->second):max_end_in_range(*best,found->second);
                    it++;
                    break;
                }
            }
        }
        if (stop) continue;
        if (!need_further_inspection)
        {
            n=next->first-start;
            while (n--) s+='a';
            s+=next->second.text;
            start=next->second.end;
            auto&tokens=next->second.owner->tokens;
            tokens.erase(next);
            continue;
        }
        for (;it!=m.end();)
        {

        }
    }
    return 0;
}
