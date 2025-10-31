#include <bits/stdc++.h>
using namespace std;
struct object
{
    int id;
    object();
    object(const int&i):id(i){}
    explicit operator bool() const
    {
        return id==0;
    }
    bool operator!() const
    {
        return id==0;
    }
    object&operator=(const int&i)
    {
        id=i;
        return*this;
    }
    object&operator=(object*op)
    {
        if (!op)
        {
            id=0;
            return*this;
        }
        id=op->id;
        return*this;
    }
};
int main()
{
    object o(-1);
    if (!o) cout<<"ID=0, meaning that this object is unset!";
    else cout<<"ID!=0, meaning that this object is set!";
    o=0;
    o=nullptr;
    o=new object(-99);
    return 0;
}
