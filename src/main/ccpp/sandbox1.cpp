#include <bits/stdc++.h>
using namespace std;
string output = "";
int temp, max, min, total, avg, ans, result;
int i, j, k, l, m, n;
const int MAX_SIZE = 10000;
//static int a[MAX_SIZE];
static vector<int> a(MAX_SIZE);
static auto compareForMax = [](int i1, int i2) { return a[i1] < a[i2]; };
static auto compareForMin = [](int i1, int i2) { return a[i1] > a[i2]; };
static priority_queue<int, vector<int>, decltype(compareForMax)> maxIndexHeap(compareForMax);
static priority_queue<int, vector<int>, decltype(compareForMin)> minIndexHeap(compareForMin);
static priority_queue<int> maxHeap;
static priority_queue<int, vector<int>, greater<int>> minHeap;
#define NEW_LINE "\n";
// DON'T do these kinds of clearing in development, just for performance only O(n) -> O(1), since we are working with
// https://cplusplus.com/reference/type_traits/is_trivially_destructible/
#define clearo(o)       obj = {};
#define clearv(v, size) v = vector<int>(size);
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return NULL; }();
int main()
{
    vector<int> v(10);
    for (i = 0; i < 10; i++) v[i] = i + 1;
    for (i = 0; i < 10; i++) cout << v[i] << " ";
    clearv(v, 10);
    cout << endl << v.size() << endl;
    cout << v[0] << endl;

    stack<int> st;
    st.push(1);
    cout << st.top() << endl;
    //st = stack<int>();
    st = {};
    cout << st.size() << endl;
    st.push(2);
    cout << st.top() << endl;

//    queue<int> q;
//    q.push(1);
//    cout << q.front() << endl;
//    q = {};
//    cout << q.size() << endl;
//    q.push(2);
//    cout << q.front() << endl;

    deque<int> dq;
    dq.clear();

    cout << output;
    return 0;
}
