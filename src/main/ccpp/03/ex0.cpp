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
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            minHeap.push(temp);
        }
        total = 0;
        while (minHeap.size() > 1)
        {
            i = minHeap.top();
            minHeap.pop();
            j = minHeap.top();
            minHeap.pop();
            temp = i + j;
            total += temp;
            minHeap.push(temp);
        }
        minHeap.pop();
        output.append(to_string(total));
        output.append(NEW_LINE);
    }
    cout << output;
	return 0;
}
