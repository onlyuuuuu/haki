#include <bits/stdc++.h>
using namespace std;
static const int    MAX_SIZE = 10000;
static const string NEW_LINE = "\n";
static string       output   = "";
static int temp, most, least, total, sum, avg, ans, result, chosen;
static int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, x, y, z, w;
//static stack<int>  stk;
//static queue<int>  que;
//static deque<int>  deq;
//static vector<int> vct(MAX_SIZE);
//static auto compare_for_max_or_asc  = [](int i1, int i2){ return vct[i1] < vct[i2]; };
//static auto compare_for_min_or_desc = [](int i1, int i2){ return vct[i1] > vct[i2]; };
//static priority_queue<int, vector<int>, decltype(compare_for_max_or_asc)>  max_index_heap(compare_for_max_or_asc);
//static priority_queue<int, vector<int>, decltype(compare_for_min_or_desc)> min_index_heap(compare_for_min_or_desc);
//static priority_queue<int>                                                 max_heap;
//static priority_queue<int, vector<int>, greater<int>>                      min_heap;
//static set<int>                                                            uset;
//static set<int>::iterator                                                  uset_it;
//static set<int, greater<int>>                                              uset_desc;
//static set<int, greater<int>>::iterator                                    uset_desc_it;
//static multiset<int>                                                       dset;
//static multiset<int>::iterator                                             dset_it;
//static multiset<int, greater<int>>                                         dset_desc;
//static multiset<int, greater<int>>::iterator                               dset_desc_it;
//static set<int, decltype(compare_for_max_or_asc)>                          index_uset(compare_for_max_or_asc);
//static set<int, decltype(compare_for_max_or_asc)>::iterator                index_uset_it;
//static set<int, decltype(compare_for_min_or_desc)>                         index_uset_desc(compare_for_min_or_desc);
//static set<int, decltype(compare_for_min_or_desc)>::iterator               index_uset_desc_it;
//static multiset<int, decltype(compare_for_max_or_asc)>                     index_dset(compare_for_max_or_asc);
//static multiset<int, decltype(compare_for_max_or_asc)>::iterator           index_dset_it;
//static multiset<int, decltype(compare_for_min_or_desc)>                    index_dset_desc(compare_for_min_or_desc);
//static multiset<int, decltype(compare_for_min_or_desc)>::iterator          index_dset_desc_it;
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();
int main(int argc, char **argv)
{
    vector<vector<int>> v;
    vector<int> v0 = { 5 };
    vector<int> v1 = { 12 };
    vector<int> v2 = { 8 };
    vector<int> v3 = { 5 };
    vector<int> v4 = { 12 };
    vector<int> v5 = { 8 };
    v.push_back(v0);
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    auto compare_for_desc = [&v] (int i1, int i2) {
        if (v[i1][0] != v[i2][0])
            return v[i1][0] > v[i2][0];
        i1 = i1 == 0 ? INT8_MAX : i1;
        i2 = i2 == 0 ? INT8_MAX : i2;
        return i1 > i2;
    };

    set<int, decltype(compare_for_desc)>           tree(compare_for_desc);
    set<int, decltype(compare_for_desc)>::iterator tree_it;

    tree.insert(0);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);

    for (tree_it = tree.cbegin(); tree_it != tree.cend(); tree_it++)
        cout << *tree_it << " - " << v[*tree_it][0] << endl;
    cout << endl;

//    x = 2;
//    tree.erase(x);
//
//    for (tree_it = tree.cbegin(); tree_it != tree.cend(); tree_it++)
//        cout << *tree_it << " - " << v[*tree_it][0] << endl;
//    cout << endl;

    return 0;
}
