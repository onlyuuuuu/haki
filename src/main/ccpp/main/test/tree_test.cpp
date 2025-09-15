#include <bits/stdc++.h>
using namespace std;

// Comparator: sort by first, and then by second if first is equal
struct compare_by_first
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main()
{
    set<pair<int,int>, compare_by_first> tree;

    tree.insert({3, 100});
    tree.insert({1, 200});
    tree.insert({2, 150});
    tree.insert({3, 50});

    // tree.cbegin()->first = -1;
    // tree.cbegin()->second = 201;

    for (const auto& p : tree)
        cout << "(" << p.first << ", " << p.second << ")\n";

    // auto b = tree.lower_bound(make_pair(2, 150));
    // if (b == tree.cend())
    // {
    //     cout << "Searched: END/NIL" << endl;
    //     return 0;
    // }
    // cout << "Searched: (" << b->first << ", " << b->second << ")\n";
    
    return 0;
}
