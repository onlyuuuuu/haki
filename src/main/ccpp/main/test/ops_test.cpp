#include <bits/stdc++.h>
using namespace std;
void func(const int& i)
{
    cout<<"Passed in: "<<i<<endl;
}
int main()
{
    int i=1;
    func(i++);
    func(++i);
    cout<<"Final result: "<<i<<endl;
    return 0;
}
