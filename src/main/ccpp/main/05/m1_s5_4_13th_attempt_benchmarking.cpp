#include <bits/stdc++.h>
using namespace std;
struct token
{
    const string* t;
    int s,e;
    token(const string*t,const int&s):t(t),s(s),e(s+t->length()){}
};
static constexpr char char_a='a';
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<size_t,vector<token>,greater<size_t>>m;
    map<size_t,vector<token>,greater<size_t>>::iterator mit;
    queue<token>q;
    string t;int n,k,s,i,seq=-1;cin>>n;
    vector<string>d;d.reserve(n);
    while (n--)
    {
        cin>>t>>k>>s;
        d.emplace_back(t);++seq;
        vector<token>&v=m.try_emplace(t.length()).first->second;
        if (v.empty())
        {
            v.reserve(k);
            v.emplace_back(&t,s);
            while (--k)
            {
                cin>>s;
                v.emplace_back(&t,s);
            }
        }
        else
        {
            if (s > v.back().s)
            {
                v.reserve(v.size() + k);
                v.emplace_back(&t,s);
                while (--k)
                {
                    cin>>s;
                    v.emplace_back(&t,s);
                }
            }
            else
            {
                for (i=0;v[i].s<s;i++) q.push(v[i]);
                q.emplace(&t,s);
                while (--k)
                {
                    cin>>s;
                    for (;v[i].s < s && i < v.size();i++) q.push(v[i]);
                    q.emplace(&t,s);
                }
                for (;i < v.size();i++) q.push(v[i++]);
                v.reserve(q.size());
                for (i=0;i<v.size();i++)
                {
                    v[i]=q.front();
                    q.pop();
                }
                while (!q.empty())
                {
                    v.push_back(q.front());
                    q.pop();
                }
            }
        }
    }

    return 0;
}