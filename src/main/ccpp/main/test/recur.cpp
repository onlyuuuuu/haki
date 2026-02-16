#include<bits/stdc++.h>
using namespace std;
static vector<int>v;
static void f(const int&i)
{
    if (i==3)
    {
        for (auto j:v)
            cout<<j<<' ';
        cout<<'\n';
        return;
    }
    f(i+1);
    v.push_back(i);
    f(i+1);
    v.pop_back();
}
int main()
{
    f(0);
    return 0;
}