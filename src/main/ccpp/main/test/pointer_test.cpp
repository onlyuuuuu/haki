#include <bits/stdc++.h>
using namespace std;
struct object
{
    int&i;
    object();
    object(int&i):i(i){}
};
void func(object*op)
{
    op->i=99;
}
void func2(object*&op)
{
    op->i=99;
}
int main()
{
    int i=1;
    func(new object(i));
    object* p=new object(i);
    func2(p);
}
