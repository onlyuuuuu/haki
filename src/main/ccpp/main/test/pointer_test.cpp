#include <bits/stdc++.h>
using namespace std;
struct object
{
    int&i;
    object();
    object(int&i):i(i){}
    object& operator=(const int&id){i=id;return*this;}
    object& operator=(const object*op)
    {
        if (!op)
        {
            i=0;
            return*this;
        }
        i=op->i;
        return*this;
    }
    bool operator==(const int&id){return i==id;}
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
    // func(new object(i));
    // object* p=new object(i);
    // func2(p);
    object o=i;
    if ((o=2) == 2) cout<<"it works!"<<endl;
    if ((o=nullptr) == 0) cout<<"it works again!"<<endl;
    func(&(o=3));
    if (o==99) cout<<"yay"<<endl;
}
