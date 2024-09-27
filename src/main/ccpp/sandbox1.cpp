#include <bits/stdc++.h>
using namespace std;
#define NEW_LINE "\n"
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
static auto _ = []() { ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return NULL; }();

int main()
{


    cout << output;
    return 0;
}
