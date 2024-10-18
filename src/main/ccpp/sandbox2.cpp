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
static set<int>                    _set;
static set<int, greater<int>>      _set_desc;
static multiset<int>               _multiset;
static multiset<int, greater<int>> _multiset_desc;
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return NULL; }();
#define clearo(o)         obj = {};
#define clearv(v, size)   v = vector<int>(size);
#define clearimaxh(imaxh) imaxh = priority_queue<int, vector<int>, decltype(compareForMax)>(compareForMax);
#define cleariminh(iminh) iminh = priority_queue<int, vector<int>, decltype(compareForMin)>(compareForMin);
int main()
{
//    _set.insert(10);
//    _set.insert(5);
//    _set.insert(12);
//    _set.insert(3);
//
//    for (int item : _set)
//        cout << item << endl;

//    _set_desc.insert(10);
//    _set_desc.insert(5);
//    _set_desc.insert(12);
//    _set_desc.insert(3);
//
//    for (int item : _set_desc)
//        cout << item << endl;

//    _multiset.insert(10);
//    _multiset.insert(5);
//    _multiset.insert(12);
//    _multiset.insert(3);
//    _multiset.insert(5);
//    _multiset.insert(10);
//
//    for (int item : _multiset)
//        cout << item << endl;

    _multiset_desc.insert(10);
    _multiset_desc.insert(5);
    _multiset_desc.insert(12);
    _multiset_desc.insert(3);
    _multiset_desc.insert(5);
    _multiset_desc.insert(10);

    for (int item : _multiset_desc)
        cout << item << endl;
    
    cout << output;
    return 0;
}
