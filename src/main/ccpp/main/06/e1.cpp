#include<bits/stdc++.h>
using namespace std;
struct cst_map
{
    int s,n,p=0;
    map<int,queue<int>>m;
    cst_map(const int&s,const int&n):s(s),n(n){}
    auto poll()
    {
        --s;
        auto p=std::make_pair(m.begin()->first,m.begin()->second.front());
        m.begin()->second.pop();
        if(m.begin()->second.empty()) m.erase(m.begin());
        return p;
    }
    bool push(const int&i,const int&x)
    {
        if(i>x-n+1) return false;
        auto e=m.try_emplace(i);
        if(e.second)
        {
            queue<int>q;
            q.push(++p);
            e.first->second=q;
            return false;
        }
        int sum=e.first->second.size() * e.first->first + i;
        if(sum == x) return true;
        if(sum > x)  return false;
        e.first->second.push(++p);
        return false;
    }
}
queue<int> solve()
{
    
}
int main()
{
    
    int n,x;
    
    queue<int>q=solve()
}