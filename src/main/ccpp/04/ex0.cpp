#include <bits/stdc++.h>
using namespace std;
//static const int    MAX_SIZE = 10000;
//static const string NEW_LINE = "\n";
//static string       output = "";
//static int temp, most, least, total, sum, avg, ans, result, chosen;
//static int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, x, y, z, w;
//static stack<int>  stk;
//static queue<int>  que;
//static deque<int>  deq;
//static vector<int> vct(MAX_SIZE);
//static auto compare_for_max_or_asc = [](int i1, int i2) { return vct[i1] < vct[i2]; };
//static auto compare_for_min_or_desc = [](int i1, int i2) { return vct[i1] > vct[i2]; };
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
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();

int minimumLoss(vector<long> prices)
{
    auto compare_for_min_or_desc = [&prices](int ia, int ib) { return prices[ia] > prices[ib]; };
    set<long, decltype(compare_for_min_or_desc)>           index_uset_desc(compare_for_min_or_desc);
    set<long, decltype(compare_for_min_or_desc)>::iterator index_uset_desc_it;
    set<long, decltype(compare_for_min_or_desc)>::iterator a;
    set<long, decltype(compare_for_min_or_desc)>::iterator b;
    set<long, decltype(compare_for_min_or_desc)>::iterator c;
    long min = LONG_MAX;
    long diff;
    for (int i = 0; i < prices.size(); i++)
        index_uset_desc.insert(i);
    while ((int)index_uset_desc.size() >= 3)
    {
        index_uset_desc_it = index_uset_desc.cbegin();
        a = index_uset_desc_it;
        b = ++index_uset_desc_it;
        c = ++index_uset_desc_it;
        if (*a > *b)
        {
            index_uset_desc.erase(a);
            continue;
        }
        diff = prices[*a] - prices[*b];
        if (diff < min) min = diff;
        if (*b < *c)
            index_uset_desc.erase(a);
        else
            index_uset_desc.erase(b);
    }
    index_uset_desc_it = index_uset_desc.cbegin();
    a = index_uset_desc_it;
    b = ++index_uset_desc_it;
    if (*a > *b)
        return min;
    diff = prices[*a] - prices[*b];
    if (diff < min)
        return diff;
    return min;
}

int main(int argc, char** argv)
{
    vector<long> v;
    v = { 20, 15, 8, 2, 12 }; cout << minimumLoss(v) << endl;
    v = { 5, 10, 3 };         cout << minimumLoss(v) << endl;
    v = { 20, 7, 8, 2, 5 };   cout << minimumLoss(v) << endl;
    return 0;
}