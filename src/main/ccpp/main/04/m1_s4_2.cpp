#include <bits/stdc++.h>
using namespace std;
int main()
{
    int M,N,K,n;
    vector<int> v(M);
    priority_queue<int,vector<int>,greater<int>> q;
    cin>>M>>N>>K;
    for (int i = 0; i < M; i++) { cin>>v[i]; }
    for (int i = 0; i < N; i++)
    {
        cin>>n;
        for (const auto& j : v)
            q.push(n + j);
    }
    for (int i = 0; i < K && !q.empty(); i++)
    {
        cout<<q.top()<<"\n";
        q.pop();
    }
    return 0;
}