#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = -1;
    cin >> arr[1];
    stack<int> st;
    st.push(0);
    st.push(1);
    cout << "0 ";
    for (int i = 2; i <= n; ++i)
    {
        cin >> arr[i];
        while (arr[st.top()] >= arr[i])
            st.pop();
        cout << to_string(st.top()) + " ";
        st.push(i);
    }
    return 0;
}
