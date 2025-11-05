#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;
    s.insert(8);
    s.insert(2);
    s.insert(4);
    s.insert(11);

    cout<<*s.find(4)<<endl;
    cout<<*--s.find(4)<<endl;
    cout<<*++s.find(4)<<endl;
    
    return 0;
}
