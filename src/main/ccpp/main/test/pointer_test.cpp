#include <bits/stdc++.h>
using namespace std;
struct inner
{
    int something=-2;
    inner()=default;
};
static inner nil_inner;
struct object
{
    int id=-1;
    bool set=false;
    std::string_view txt;
    vector<inner>v;
    vector<inner>::iterator vit;
    inner&inn=nil_inner;
    object();
    object&modify()
    {
        inn.something=99;
        return*this;
    }
};
int main()
{
    string s="canknkdcdsac";
    object o;
    o.txt=s;
    inner i1;
    inner i2;
    vector<inner>v;
    v.emplace_back(i1);
    v.emplace_back(i2);
    o.vit=v.begin();
    o.vit++;
    return 0;
}