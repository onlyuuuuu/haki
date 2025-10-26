#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i = 6;
    int* p1 = &i;
    cout<<i<<endl;
    *p1 = 7;
    cout<<i<<endl;
    int* p2 = p1;
    *p2 = 8;
    cout<<i<<endl;
    return 0;
}
