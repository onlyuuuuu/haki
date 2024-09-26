#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    unsigned int arr[n];
    stack<unsigned int> st;
    st.push(1);
    cin >> arr[0];
    string result = "0 ";
    for (int i = 1; i < n; ++i)
    {
        cin >> arr[i];
        if (arr[st.top() - 1] < arr[i])
        {
            result.append(to_string(st.top()) + " ");
            st.push(i + 1);
            continue;
        }
        while (!st.empty() && arr[st.top() - 1] >= arr[i])
            st.pop();
        if (st.empty())
            result.append("0 ");
        else result.append(to_string(st.top()) + " ");
        st.push(i + 1);
    }
    cout << result << endl;
    return 0;
}
