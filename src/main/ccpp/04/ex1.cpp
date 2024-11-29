#include <bits/stdc++.h>
using namespace std;
static const int    MAX_SIZE = 10000;
static const string NEW_LINE = "\n";
static string       output = "";
static int temp, most, least, total, sum, avg, ans, result, chosen, last, first;
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
//static priority_queue<int, vector<int>, greater<int>>                      min_heap;
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
static auto ascn_mov_end_times = [] (int i1, int i2)
{
    if (movies[i1][1] != movies[i2][1])
        return movies[i1][1] < movies[i2][1];
    return i1 < i2;
};
static auto desc_mov_end_times = [] (int i1, int i2)
{
    if (movies[i1][1] != movies[i2][1])
        return movies[i1][1] > movies[i2][1];
    return i1 > i2;
};
static set<int, decltype(ascn_mov_end_times)>           tree1(ascn_mov_end_times);
static set<int, decltype(desc_mov_end_times)>           tree2(desc_mov_end_times);
static set<int, decltype(ascn_mov_end_times)>::iterator it1;
static set<int, decltype(desc_mov_end_times)>::iterator it2;
int main(int argc, char** argv)
{
    cin >> n;
    cin >> k;
    if (k >= n)
    {
        for (i = 0; i < n; i++)
        {
            cin >> a;
            cin >> b;
        }
        cout << n << endl;
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        vector<int> v = { a, b };
        movies.push_back(v);
        tree1.insert(i);
    }
    vector<int> init = { INT_MAX, 0 };
    movies.push_back(init);
    tree2.insert(*tree1.cbegin());
    tree1.erase(tree1.cbegin());
    total = 1;
    while ((int)tree2.size() < k && !tree1.empty())
    {
        i = *tree1.cbegin();
        tree1.erase(tree1.cbegin());
        movies[n][1] = movies[i][0];
        it2 = tree2.lower_bound(n);
        if (it2 == tree2.cend())
        {
            tree2.insert(i);
            ++total;
            continue;
        }
        tree2.erase(it2);
        tree2.insert(i);
        ++total;
    }
    while (!tree1.empty())
    {
        i = *tree1.cbegin();
        tree1.erase(tree1.cbegin());
        movies[n][1] = movies[i][0];
        it2 = tree2.lower_bound(n);
        if (it2 == tree2.cend())
            continue;
        tree2.erase(it2);
        tree2.insert(i);
        ++total;
    }
    cout << total << endl;
    return 0;
}
