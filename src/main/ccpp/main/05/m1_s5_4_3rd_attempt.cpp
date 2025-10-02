#include <bits/stdc++.h>
using namespace std;
struct entry{string t;int s,e;};
struct compare{bool operator()(const entry&a,const entry&b)const{return(a.t.length()!=b.t.length())?a.t.length()<b.t.length():a.e<b.e;}};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}