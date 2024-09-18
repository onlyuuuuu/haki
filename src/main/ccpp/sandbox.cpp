#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <regex>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#include <functional>
#include <cstdio>
#include <climits>
#include <limits>

using namespace std;

int main()
{
	//int arr[10] = { 0 };
	int arr[10] = { };
	cout << arr[0] << endl;
	cout << arr[1] << endl;

	// Vector in C++ are very much like ArrayList in Java
	vector<int> vec;
	vec.push_back(1);
	cout << vec[0] << endl;
	vec.push_back(2);
	cout << vec[1] << endl;
	
	// Stack
	stack<int> stk;
	stk.push(1);
	cout << stk.top() << endl;
	stk.pop();
	if (stk.empty())
		cout << "Stack is empty!" << endl;

	// Queue
	queue<int> q;
	q.push(1);
	cout << q.front() << endl;
	q.pop();
	if (q.empty())
		cout << "Queue is empty!" << endl;
	
	// Deque
	deque<int> dq;
	dq.push_back(1);
	dq.push_front(2);
	cout << dq.front() << endl;
	cout << dq.back() << endl;
	dq.pop_front();
	dq.pop_back();
	if (dq.empty())
		cout << "Deque is empty!" << endl;

	// Max Heap
	priority_queue<int> maxHeap;
	maxHeap.push(1);
	maxHeap.push(5);
	cout << maxHeap.top() << endl;
	maxHeap.pop();
	cout << maxHeap.top() << endl;

	// Min Heap
	priority_queue<int, vector<int>, greater<int>> minHeap;
	minHeap.push(1);
	minHeap.push(-1);
	cout << minHeap.top() << endl;
	minHeap.pop();
	cout << minHeap.top() << endl;

	// Binary Tree (multiset)
	multiset<int> mts;
	mts.insert(5);
	mts.insert(11);
	mts.insert(23);
}