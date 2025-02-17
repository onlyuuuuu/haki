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
static vector<vector<int>> plans;
static auto compare_min_movie_end_times = [] (int i1, int i2)
{
    if (movies[i1][1] != movies[i2][1])
        return movies[i1][1] > movies[i2][1];
    return movies[i1][0] > movies[i2][0];
};
static auto compare_max_movie_sizes = [] (int i1, int i2)
{
    if (plans[i1].size() != plans[i2].size())
        return plans[i1].size() > plans[i2].size();
    return i1 > i2;
};
// Prioritise fitting before plan size (problems with below case)
/* 
5 1
1 2
2 3
3 4
1 5
5 6
*/
// Need to deal with temp location, which is at index 0
static auto compare_desc_plan_end_times = [] (int i1, int i2)
{
    // fitting
    if (movies[plans[i1].back()][1] != movies[plans[i2].back()][1])
        return movies[plans[i1].back()][1] > movies[plans[i2].back()][1];
    // size
    if (plans[i1].size() != plans[i2].size())
    {
        if (i1 == 0)
            return true;
        if (i2 == 0)
            return false;
        return plans[i1].size() > plans[i2].size();
    }
    // index
    if (i1 == 0)
        return true;
    if (i2 == 0)
        return false;
    return i1 > i2;
};
static priority_queue<int, vector<int>, decltype(compare_min_movie_end_times)> least_et_movs_heap(compare_min_movie_end_times);
static set<int, decltype(compare_max_movie_sizes)>                             plans_most_movs_size_tree(compare_max_movie_sizes);
static set<int, decltype(compare_max_movie_sizes)>::iterator                   plans_most_movs_size_tree_it;
static set<int, decltype(compare_desc_plan_end_times)>                         plans_et_desc_tree(compare_desc_plan_end_times);
static set<int, decltype(compare_desc_plan_end_times)>::iterator               plans_et_desc_tree_it;
int main(int argc, char** argv)
{
    cin >> n;
    cin >> k;
    total = 0;
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
        least_et_movs_heap.push(i);
    }
    vector<int> temp_v = { 0, 0 };
    movies.push_back(temp_v);
    vector<int> init_v_0 = { n };
    plans.push_back(init_v_0);
    vector<int> init_v_1; init_v_1.push_back(least_et_movs_heap.top()); least_et_movs_heap.pop();
    plans.push_back(init_v_1);
    plans_et_desc_tree.insert(1);
    plans_most_movs_size_tree.insert(1);
    while (!least_et_movs_heap.empty())
    {
        i = least_et_movs_heap.top(); least_et_movs_heap.pop();
        movies[n][1] = movies[i][0];
        plans_et_desc_tree_it = plans_et_desc_tree.lower_bound(0);
        if (plans_et_desc_tree_it == plans_et_desc_tree.cend())
        {
            vector<int> temp_v; temp_v.push_back(i);
            plans.push_back(temp_v);
            last = (int)plans.size() - 1;
            plans_et_desc_tree.insert(last);
            plans_most_movs_size_tree.insert(last);
            continue;
        }
        x = *plans_et_desc_tree_it;
        plans_et_desc_tree.erase(plans_et_desc_tree_it); // armortized constant O(1) compared to .erase(x) O(logN)
        // from this point onwards, *plans_et_desc_tree_it cannot be referenced anymore, so just use x
        plans_most_movs_size_tree.erase(x);
        plans[x].push_back(i);
        plans_et_desc_tree.insert(x);
        plans_most_movs_size_tree.insert(x);
    }
    if (k >= (int)plans_most_movs_size_tree.size())
    {
        cout << n << endl;
        return 0;
    }
    plans_most_movs_size_tree_it = plans_most_movs_size_tree.cbegin();
    for (i = 1; i <= k; i++)
    {
        total += plans[*plans_most_movs_size_tree_it].size();
        plans_most_movs_size_tree_it++;
    }
    cout << total << endl;
    return 0;
}
