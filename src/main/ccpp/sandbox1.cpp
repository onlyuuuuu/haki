#include <bits/stdc++.h>
using namespace std;
static const string NEW_LINE = "\n";
static const int    MAX_SIZE = 10000;
static string output = "";
static int temp, max, min, total, avg, ans, result;
static int i, j, k, l, m, n;
static stack<int>  _stack;
static queue<int>  _queue;
static deque<int>  _deque;
static vector<int> _vector(MAX_SIZE);
static auto compareForMax = [](int i1, int i2) { return _vector[i1] < _vector[i2]; };
static auto compareForMin = [](int i1, int i2) { return _vector[i1] > _vector[i2]; };
static priority_queue<int, vector<int>, decltype(compareForMax)> maxIndexHeap(compareForMax);
static priority_queue<int, vector<int>, decltype(compareForMin)> minIndexHeap(compareForMin);
static priority_queue<int>                                       maxHeap;
static priority_queue<int, vector<int>, greater<int>>            minHeap;
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();
#define clearo(o)         obj = {};
#define clearv(v, size)   v = vector<int>(size);
#define clearimaxh(imaxh) imaxh = priority_queue<int, vector<int>, decltype(compareForMax)>(compareForMax);
#define cleariminh(iminh) iminh = priority_queue<int, vector<int>, decltype(compareForMin)>(compareForMin);
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
