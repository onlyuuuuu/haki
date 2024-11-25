#include <bits/stdc++.h>
using namespace std;
static const int    MAX_SIZE = 10000;
static const string NEW_LINE = "\n";
static string       output = "";
static int temp, most, least, total, sum, avg, ans, result, chosen;
static int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, x, y, z, w;
//static stack<int>  stk;
//static queue<int>  que;
//static deque<int>  deq;
//static vector<int> vct(MAX_SIZE);
//static auto compare_for_max_or_ascn = [](int i1, int i2) { return vct[i1] < vct[i2]; };
//static auto compare_for_min_or_desc = [](int i1, int i2) { return vct[i1] > vct[i2]; };
//static priority_queue<int, vector<int>, decltype(compare_for_max_or_ascn)> max_index_heap(compare_for_max_or_ascn);
//static priority_queue<int, vector<int>, decltype(compare_for_min_or_desc)> min_index_heap(compare_for_min_or_desc);
//static priority_queue<int>                                                 max_heap;
static priority_queue<int, vector<int>, greater<int>>                      min_heap;
//static set<int>                                                            uset;
//static set<int>::iterator                                                  uset_it;
//static set<int, greater<int>>                                              uset_desc;
//static set<int, greater<int>>::iterator                                    uset_desc_it;
//static multiset<int>                                                       dset;
//static multiset<int>::iterator                                             dset_it;
//static multiset<int, greater<int>>                                         dset_desc;
//static multiset<int, greater<int>>::iterator                               dset_desc_it;
//static set<int, decltype(compare_for_max_or_ascn)>                         index_uset(compare_for_max_or_ascn);
//static set<int, decltype(compare_for_max_or_ascn)>::iterator               index_uset_it;
//static set<int, decltype(compare_for_min_or_desc)>                         index_uset_desc(compare_for_min_or_desc);
//static set<int, decltype(compare_for_min_or_desc)>::iterator               index_uset_desc_it;
//static multiset<int, decltype(compare_for_max_or_ascn)>                    index_dset(compare_for_max_or_ascn);
//static multiset<int, decltype(compare_for_max_or_ascn)>::iterator          index_dset_it;
//static multiset<int, decltype(compare_for_min_or_desc)>                    index_dset_desc(compare_for_min_or_desc);
//static multiset<int, decltype(compare_for_min_or_desc)>::iterator          index_dset_desc_it;
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

static vector<vector<int>> movies;
static auto compare_for_max_or_ascn = [](int i1, int i2) { return (movies[i1][0] == movies[i2][0]) ? movies[i1][1] < movies[i2][1] : movies[i1][0] < movies[i2][0]; };
static multiset<int, decltype(compare_for_max_or_ascn)>           index_dset(compare_for_max_or_ascn);
static multiset<int, decltype(compare_for_max_or_ascn)>::iterator index_dset_it;

int max_depth(int start_index)
{
    return 0;
}

int main(int argc, char** argv)
{
    cin >> n;
    cin >> k;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        vector<int> v = {a, b};
        movies.push_back(v);
        index_dset.insert(i);
    }
    total = 1;
    min_heap.push(movies[*index_dset.cbegin()][1]);
    index_dset_it = ++index_dset.cbegin();
    //cout << endl;
    for (; index_dset_it != index_dset.cend(); index_dset_it++)
    {
        //cout << movies[*index_dset_it][0] << " " << movies[*index_dset_it][1] << endl;
        if ((int)min_heap.size() < k)
        {
            min_heap.push(movies[*index_dset_it][1]);
            ++total;
            continue;
        }
        if ((int)min_heap.size() == k && movies[*index_dset_it][0] < min_heap.top())
            continue;
        min_heap.pop();
        min_heap.push(movies[*index_dset_it][1]);
        ++total;
    }
    //cout << min_heap.top() << endl;
    cout << total << endl;
    return 0;
}
