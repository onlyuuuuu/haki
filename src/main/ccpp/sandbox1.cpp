#include <bits/stdc++.h>
using namespace std;
string output = "";
int temp, max, min, total, avg, ans, result;
int i, j, k, l, m, n;
const int MAX_SIZE = 10000;
static int arr[MAX_SIZE];
static auto compareForMax = [](int i1, int i2) { return arr[i1] < arr[i2]; };
static auto compareForMin = [](int i1, int i2) { return arr[i1] > arr[i2]; };
static priority_queue<int, vector<int>, decltype(compareForMax)> maxIndexHeap(compareForMax);
static priority_queue<int, vector<int>, decltype(compareForMin)> minIndexHeap(compareForMin);
static priority_queue<int> maxHeap;
static priority_queue<int, vector<int>, greater<int>> minHeap;
#define NEW_LINE "\n";
#define clearVector(v,size) v.clear(); v = vector<int>(size);
#define clearMaxHeap(mh) mh = priority_queue<int>();
#define clearMinHeap(mh) mh = priority_queue<int, vector<int>, greater<int>>();
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return NULL; }();

int main()
{
    vector<int> v(10);
    for (i = 0; i < 10; i++) v[i] = i + 1;
    for (i = 0; i < 10; i++) cout << v[i] << " ";
    clearVector(v, 10);
    cout << endl << v.size() << endl;
    cout << v[0] << endl;

    cout << output;
    return 0;
}
