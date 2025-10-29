#include <bits/stdc++.h>
using namespace std;
struct object
{
    int id=0;
    object(const int&id):id(id){}
};
int main()
{
    // int i = 6;
    // int* p1 = &i;
    // cout<<i<<endl;
    // *p1 = 7;
    // cout<<i<<endl;
    // int* p2 = p1;
    // *p2 = 8;
    // cout<<i<<endl;
    // return 0;
    object o1(6),o2(9);
    cout<<o1.id<<" - "<<o2.id<<endl;
    object* p;
    p=&o1;
    auto&id=p->id;
    id=-1;
    cout<<o1.id<<" - "<<o2.id<<endl;
    p=&o2;
    id=-5;
    cout<<o1.id<<" - "<<o2.id<<endl;
}
