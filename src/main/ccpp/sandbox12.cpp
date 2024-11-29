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
    map<int, vector<int>> m;
    map<int, vector<int>>::iterator it;
    vector<int> v0 = { 2, 3, 1 }; m[2] = v0;
    vector<int> v1 = { 7, 1, 0 }; m[0] = v1;
    vector<int> v2 = { 5, 9, 2 }; m[5] = v2;
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " - ";
        for (i = 0; i < (int)it->second.size(); i++)
            cout << it->second[i] << "  ";
        cout << endl;
    }
    for (it = m.lower_bound(2); it != m.end(); ++it)
    {
        cout << it->first << " - ";
        for (i = 0; i < (int)it->second.size(); i++)
            cout << it->second[i] << "  ";
        cout << endl;
    }
    for (it = m.upper_bound(2); it != m.end(); ++it)
    {
        cout << it->first << " - ";
        for (i = 0; i < (int)it->second.size(); i++)
            cout << it->second[i] << "  ";
        cout << endl;
    }
    return 0;
}
