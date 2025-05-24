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
    set<int, decltype(compare)> tree(compare);
    set<int, decltype(compare)>::iterator next;
    int start = 0, end = 0, total = 0;
    movies[0] = Movie();
    for (int i = 1; i <= mov; i++)
    {
        cin >> start;
        cin >> end;
        movies[i] = Movie(start, end);
        tree.insert(i);
    }

    for (next = tree.cbegin(); next != tree.cend(); next++)
        cout << "Movie " << *next << ": " << movies[*next].start << " - " << movies[*next].end << endl;

    for (int i = 1; i <= mem && !tree.empty(); i++)
    {
        Movie movie = movies[*tree.cbegin()];
        tree.erase(tree.cbegin());
        ++total;
        movies[0].start = movie.end;
        movies[0].end = movies[0].start + 1;
        next = tree.lower_bound(0);
        while (next != tree.cend())
        {
            if (movies[*next].start < movie.start)
            {
                movies[0].start = movie.end;
                movies[0].end = movies[*next].end;
                next = tree.lower_bound(0);
                continue;
            }
            movie = movies[*next];
            tree.erase(next);
            ++total;
            movies[0].start = movie.end;
            movies[0].end = movies[0].start + 1;
            next = tree.lower_bound(0);
        }
    }
    cout << total << endl;
    return 0;
}
