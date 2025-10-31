#include <bits/stdc++.h>
using namespace std;
struct inner
{
    int something=-2;
    inner();
};
struct object
{
    int id=-1;
    bool set=false;
    const string&txt;
    inner&inn;
    object();
    object(const string&t):txt(t){};
    object&modify()
    {
        inn.something=99;
        return*this;
    }
};
int main()
{
    object o("");
    o.modify();
    return 0;
}