#include <bits/stdc++.h>
using namespace std;

// Comparator: sort by first, and then by second if first is equal
struct compare_by_first
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.first == b.first || a.first == INT_MAX || b.first == INT_MAX)
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

    for (const auto& p : tree)
        cout << "(" << p.first << ", " << p.second << ")\n";

    auto b = tree.lower_bound(make_pair(INT_MAX, 150));
    // auto b = tree.lower_bound(make_pair(2, 150));
    if (b == tree.cend())
    {
        cout << "END/NIL" << endl;
        return 0;
    }

    cout << "(" << b->first << ", " << b->second << ")\n";
    
    return 0;
}