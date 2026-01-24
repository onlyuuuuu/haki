#include<bits/stdc++.h>
using namespace std;
struct cst_map
{
    int s,n,p=0;
    map<int,queue<int>>m;
    cst_map(const int&s,const int&n):s(s),n(n-1){}
    auto poll()
    {
        --s;
        auto p=std::make_pair(m.begin()->first,m.begin()->second.front());
        m.begin()->second.pop();
        if(m.begin()->second.empty()) m.erase(m.begin());
        return p;
    }
    auto poph()
    {
        s-=m.begin()->second.size();
        return m.erase(m.begin());
    }
    bool push(const int&i,const int&x)
    {
        if(i>x-n) return false;
        auto e=m.try_emplace(i);
        if(e.second)
        {
            queue<int>q;
            q.push(++p);
            e.first->second=q;
            ++s;
            return false;
        }
        long sum = e.first->second.size() * e.first->first + i;
        if(sum == x) return true;
        if(sum > x)  return false;
        if(e.first->second.size() == n) return false;
        e.first->second.push(++p);
        ++s;
        return false;
    }
}
vector<int> solve(const int&n,const int&s,cst_map&cm)
{
    vector<int>v;
    return v;
}
int main()
{
    
    int n,x;
    cin>>n>>x;
    cst_map cm();
    vector<int>v=solve();
    return 0;
}