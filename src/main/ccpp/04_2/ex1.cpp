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
        return mov;
    Movie movies[mov + 1];
    int start, end;
    movies[0] = Movie();
    for (int i = 1; i <= mov; i++)
    {
        cin >> start;
        cin >> end;
        movies[i] = Movie(start, end);
    }
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
    set<int, decltype(compare)> t1(compare);
    set<int> t2;
    int total = 0;
    for (int i = 1; i <= mem && !t1.empty(); i++)
    {
        Movie first = movies[*t1.cbegin()];
        t1.erase(t1.cbegin());
        t2.insert(first.end);
        ++total;

    }
}
