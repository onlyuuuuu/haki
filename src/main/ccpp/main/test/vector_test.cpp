#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int>v={1,2,3,4,5};
    // vector<int>v2={1,2,3,4,5,6,7,8,9,10};
    // v=v2;
    int n=3;
    // vector<int>v;v.reserve(n);
    vector<int>v;v.assign(n,0);
    cin>>v[0];
    cin>>v[1];
    cin>>v[2];
    for (auto&val:v)cout<<val<<" ";
    return 0;
}
