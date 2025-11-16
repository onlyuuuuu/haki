#include<bits/stdc++.h>
using namespace std;
void func(const vector<int>::iterator&it)
{
    cout<<"I'm working with "<<*it<<'\n';
}
void func(const vector<int>::iterator&it,const vector<int>::iterator&it2)
{
    cout<<"I'm working with "<<*it<<'\n';
    cout<<"I'm also working with "<<*it2<<'\n';
}
void func2(const int&i)
{
    cout<<"I'm working with "<<i<<'\n';
}
struct object
{
    vector<int>::iterator vit;
    vector<int>vec;
    object()=default;
    object(const vector<int>::iterator&vit,const vector<int>&vec):vit(vit),vec(vec){}
};
int main()
{
    vector<int>v={1,-2,3,-4,5};
    vector<int>v2={4,3,5};
    vector<int>::iterator it=v.begin();
    func(it++,it);
    func2(*it++);
    cout<<"it = "<<*it<<'\n';
    func2(*(it++));
    cout<<"it = "<<*it<<'\n';
    vector<object>v3;
    v3.emplace_back(v.begin(),v);
    v3.emplace_back(v2.begin(),v2);
    vector<object>::iterator i=v3.begin();
    func(i++->vit++);
    cout<<"i->vit = "<<*(i->vit)<<" | "<<(i==v3.begin() ? "i still at v3.begin()" : "no longer at v3.begin()")<<'\n';
    func(i++->vit++);
    cout<<"[END]i->vit = "<<*((--i)->vit)<<" | "<<(i==v3.end() ? "i is at v3.end()" : "i is not at v3.end()")<<'\n';
    cout<<"v3.begin()->vit = "<<*(v3.begin()->vit)<<'\n';
    it=v.begin();
    if(it==v.begin() || *++it==-2) cout<<"1st condition met!"<<'\n';
    cout<<"it = "<<*it<<'\n';
    if(it!=v.begin() || *++it==-2) cout<<"2nd condition met!"<<'\n';
    cout<<"it = "<<*it<<'\n';
}