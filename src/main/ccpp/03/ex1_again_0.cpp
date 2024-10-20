#include <bits/stdc++.h>
using namespace std;
static const string NEW_LINE = "\n";
static const int    MAX_SIZE = 10000;
static string output = "";
static int temp, maxv, minv, total, sum, avg, ans, result, chosen;
static int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, x, y, z, w;
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
static multiset<int>                                                       _multiset, tree1, tree2, tree3;
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
    // input
    cin >> m;
    cin >> n;
    cin >> k;
    for (i = 0; i < m; i++)
    {
        cin >> temp;
        tree1.insert(temp);
    }
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        tree2.insert(temp);
    }
    while ( (int)tree3.size() < k )
    {
        if ( tree1.empty() || tree2.empty() ) break;
        if ( (int)*tree1.cbegin() > (int)*tree2.cbegin() )
            tree1.swap(tree2);
        chosen = (int)*tree1.cbegin();
        tree1.erase(tree1.cbegin());
        for ( int i : tree2 )
        {
            sum = chosen + i;
            if ( (int)tree3.size() < k )
            {
                tree3.insert(sum);
                continue;
            }
            if ( sum >= (int)*prev(tree3.cend()) ) break;
            tree3.erase(prev(tree3.cend()));
            tree3.insert(sum);
        }
    }
    multiset<int>::iterator it;
    while ( true )
    {
        if ( tree1.empty() || tree2.empty() ) break;
        if ( (int)*tree1.cbegin() > (int)*tree2.cbegin() )
            tree1.swap(tree2);
        chosen = (int)*tree1.cbegin();
        tree1.erase(tree1.cbegin());
        it = tree2.cbegin();
        sum = chosen + (int)*it;
        maxv = (int)*prev(tree3.cend());
        if ( sum >= maxv ) break;
        tree3.erase(prev(tree3.cend()));
        tree3.insert(sum);
        for ( it++; it != tree2.cend(); it++ )
        {
            sum = chosen + (int)*it;
            maxv = (int)*prev(tree3.cend());
            if ( sum >= maxv ) break;
            tree3.erase(prev(tree3.cend()));
            tree3.insert(sum);
        }
    }
    for ( int i : tree3 )
        cout << i << endl;
    return 0;
}
