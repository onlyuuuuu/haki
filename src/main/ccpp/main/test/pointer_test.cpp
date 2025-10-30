#include <bits/stdc++.h>
using namespace std;
// struct object1
// {
//     const int&id=0;
//     object1(const int&id):id(id){}
// };
// struct object2
// {
//     int id=0;
//     object2(const int&id):id(id){}
// };
// struct object3
// {
//     int*id=0;
//     object3(int*id):id(id){}
// };
// struct object4
// {
//     object1&o1;
//     object4(object1&):o1(o1){}
// };
struct object
{
    vector<int>::iterator&it;
    object(vector<int>::iterator&it):it(it){}
};
struct object2
{
    vector<int>v;
    object2();
};
int main()
{
    vector<int>v;v.push_back(0);
    // object o(v.begin()); // not working
    object2 o2;
    vector<int>&vo2=o2.v;
    // object o(o2.v); // not working
    // object o(vo2.begin()); // not working
}
