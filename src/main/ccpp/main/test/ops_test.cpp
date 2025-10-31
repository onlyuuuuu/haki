#include <bits/stdc++.h>
using namespace std;
struct object
{
    int id;
    object()=default;
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
    int operator+(const int&i)const
    {
        return id+i;
    }
};
int main()
{
    object o(-1);
    int result=o+1;
    cout<<result<<endl;
    //result=1+o; // not working
    return 0;
}
