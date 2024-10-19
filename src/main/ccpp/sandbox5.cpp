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
static auto compare_for_max_or_asc  = [](int i1, int i2){ return _vector[i1] < _vector[i2]; };
static auto compare_for_min_or_desc = [](int i1, int i2){ return _vector[i1] > _vector[i2]; };
static priority_queue<int, vector<int>, decltype(compare_for_max_or_asc)>  _maxIndexHeap(compare_for_max_or_asc);
static priority_queue<int, vector<int>, decltype(compare_for_min_or_desc)> _minIndexHeap(compare_for_min_or_desc);
static priority_queue<int>                                                 _maxHeap;
static priority_queue<int, vector<int>, greater<int>>                      _minHeap;
static set<int>                                                            _set;
static set<int, greater<int>>                                              _set_desc;
static multiset<int>                                                       _multiset;
static multiset<int, greater<int>>                                         _multiset_desc;
static set<int, decltype(compare_for_max_or_asc)>                          _index_set(compare_for_max_or_asc);
static set<int, decltype(compare_for_min_or_desc)>                         _index_set_desc(compare_for_min_or_desc);
static set<int, decltype(compare_for_max_or_asc)>                          _index_multiset(compare_for_max_or_asc);
static set<int, decltype(compare_for_min_or_desc)>                         _index_multiset_desc(compare_for_min_or_desc);
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return NULL; }();
#define clearo(o)         obj = {};
#define clearv(v, size)   v = vector<int>(size);
#define clearimaxh(imaxh) imaxh = priority_queue<int, vector<int>, decltype(compare_for_max_or_asc)>(compare_for_max_or_asc);
#define cleariminh(iminh) iminh = priority_queue<int, vector<int>, decltype(compare_for_min_or_desc)>(compare_for_min_or_desc);
int main()
{
    multiset<int> tree1;
    multiset<int> tree2;
    multiset<int> &ref = tree1;

    tree1.insert(12);
    tree1.insert(5);
    tree1.insert(9);
    tree1.insert(17);

    tree2.insert(0);
    tree2.insert(11);
    tree2.insert(3);
    tree2.insert(9);

    for (multiset<int>::iterator it = ref.begin(); it != ref.end(); it++)
        cout << *it << " ";
    cout << endl;

    ref = tree2;

    for (multiset<int>::iterator it = ref.begin(); it != ref.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
