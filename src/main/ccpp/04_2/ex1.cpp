#include <bits/stdc++.h>
using namespace std;
class Movie
{
public:
    int start;
    int end;
    Movie()
    {
        this->start = 0;
        this->end = 0;
    }
    Movie(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};
int main()
{
    int mov, mem;
    cin >> mov;
    cin >> mem;
    if (mov <= mem)
    {
        cout << mov << endl;
        return 0;
    }
    Movie movies[mov + 1];
    auto compare = [&movies](int i, int j)
    {
        if (movies[i].end == movies[j].end)
        {
            if (movies[i].start == movies[j].start)
                return i < j;
            return movies[i].start < movies[j].start;
        }
        return movies[i].end < movies[j].end;
    };
    set<int, decltype(compare)> tree1(compare);
    set<int, decltype(compare)>::iterator tree1it;
    set<int> tree2;
    set<int>::iterator tree2it;
    Movie m1, m2;
    int start = 0, end = 0, total = 0;
    movies[0] = Movie();
    for (int i = 1; i <= mov; i++)
    {
        cin >> start;
        cin >> end;
        movies[i] = Movie(start, end);
        tree1.insert(i);
    }

    tree1it = tree1.cbegin();
    m1 = movies[*tree1it];
    tree2.insert(m1.end);
    tree1.erase(tree1it);
    while (!tree1.empty() && tree2.size() > mem)
    {
        movies[0].start = *tree2.cbegin();
        movies[0].end = movies[0].start + 1;
        tree1it = tree1.lower_bound(0);
        if (tree1it == tree1.cend())
        {
            tree1it = tree1.cbegin();
            m1 = movies[*tree1it];
            tree2.insert(m1.end);
            tree1.erase(tree1it);
        }
    }

    cout << total << endl;
    return 0;
}
