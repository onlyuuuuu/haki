#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M,N,K,i;cin>>M>>N>>K;
    priority_queue<pair<int,bool>,vector<pair<int,bool>>,greater<pair<int,bool>>>qa,qb;
    vector<int>va,vb;va.reserve(M);vb.reserve(N);unordered_map<bool,vector<int>>m;m.reserve(2);m[false]=va;m[true]=vb;

    return 0;
}