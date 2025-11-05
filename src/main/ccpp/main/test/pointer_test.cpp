#include <bits/stdc++.h>
using namespace std;
struct object
{
    vector<int>v;
    vector<int>::iterator vit;
    object()=default;
};
int main()
{
    object o;
    auto&v=o.v;
    v.emplace_back(0);
    v.emplace_back(1);
    v.emplace_back(2);
    auto&vit=o.vit;
    vit=v.begin();
    cout<<*o.vit<<endl;
    vit++;
    cout<<*o.vit<<endl;
    vector<int>v2(1,99);
    vit=v2.begin();
    cout<<*o.vit<<endl;
    return 0;
}