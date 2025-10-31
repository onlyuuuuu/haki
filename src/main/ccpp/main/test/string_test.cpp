#include <bits/stdc++.h>
using namespace std;
struct object
{
    std::string_view txt;
    object()=default;
};
int main()
{
    string shared = "Hello world!";

    object a;
    a.txt = shared;

    object b;
    b.txt = shared;

    cout << a.txt << endl;
    cout << b.txt << endl;
    return 0;
}
