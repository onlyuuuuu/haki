#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<int> buf;
    // buf.reserve(1000);  // reserve space for 1000 elements
    // priority_queue pq(less<int>(), move(buf));

    vector<pair<int,bool>>A,B;A.reserve(10);B.reserve(10);
    priority_queue qa(greater<pair<int,bool>>(),move(A));
    priority_queue qb(greater<pair<int,bool>>(),move(B));

    return 0;
}