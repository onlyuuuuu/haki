#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<string>s;
    s.insert("abc");
    s.insert("xyz");
    s.insert("abcc");
    s.insert("abcabc");
    for (auto it=s.begin();it!=s.end();it++)
        cout<<*it<<endl;
    return 0;
}
