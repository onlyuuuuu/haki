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
static vector<stack<int>> plans;
static auto compare_min_movie_end_times = [] (int i1, int i2)
{
    return (movies[i1][1] != movies[i2][1])
        ? movies[i1][1] > movies[i2][1]
        : movies[i1][0] > movies[i2][0];
};
static auto compare_max_movie_sizes = [] (int i1, int i2)
{
    return plans[i1].size() < plans[i2].size();
};
static auto compare_desc_plan_end_times = [] (int i1, int i2)
{
    return (plans[i1].top() != plans[i2].top())
        ? plans[i1].top() > plans[i2].top()
        : plans[i1].size() > plans[i2].size();
};
static priority_queue<int, vector<int>, decltype(compare_min_movie_end_times)> least_et_movs_heap(compare_min_movie_end_times);
static priority_queue<int, vector<int>, decltype(compare_max_movie_sizes)>     most_movs_size_heap(compare_max_movie_sizes);
static multiset<int, decltype(compare_desc_plan_end_times)>                    plans_et_desc_tree(compare_desc_plan_end_times);
static multiset<int, decltype(compare_desc_plan_end_times)>::iterator          plans_et_desc_tree_it;
int main(int argc, char** argv)
{
    cin >> n;
    cin >> k;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;
        vector<int> v = { a, b };
        movies.push_back(v);
        least_et_movs_heap.push(i);
    }
    stack<int> st;
    st.push(0);
    plans.push_back(st);
    total = 0;
    cout << total << endl;
    return 0;
}
