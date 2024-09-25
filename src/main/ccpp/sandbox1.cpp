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

	// Stack - No iterator
	stack<int> stk;
	stk.push(1);
	cout << stk.top() << endl;
	stk.pop();
	if (stk.empty())
		cout << "Stack is empty!" << endl;

	// Queue - No iterator
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
	cout << dq[0] << endl;
	cout << dq[1] << endl;
	for (deque<int>::iterator itr = dq.begin(); itr != dq.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	dq.pop_front();
	dq.pop_back();
	if (dq.empty())
		cout << "Deque is empty!" << endl;

	// Max Heap
	priority_queue<int> maxHeap;
	maxHeap.push(1);
	maxHeap.push(5);
	// No iterator for heap
	/*for (priority_queue<int>::iter itr = maxHeap.begin(); itr != maxHeap.end(); ++itr)
		cout << *itr << " ";
	cout << endl;*/
	cout << maxHeap.top() << endl;
	maxHeap.pop();
	cout << maxHeap.top() << endl;

	// Min Heap
	priority_queue<int, vector<int>, greater<int>> minHeap;
	minHeap.push(1);
	minHeap.push(-1);
	// No iterator for heap
	/*for (priority_queue<int>::iterator itr = minHeap.begin(); itr != minHeap.end(); ++itr)
		cout << *itr << " ";
	cout << endl;*/
	cout << minHeap.top() << endl;
	minHeap.pop();
	cout << minHeap.top() << endl;

	// Binary Tree (Multiset), Multiset in C++ is very much like TreeSet in Java
	multiset<int> mts;
	mts.insert(5);
	mts.insert(11);
	mts.insert(23);
	//mts.emplace_hint(mts.begin(), 6);
	mts.emplace(1);
	mts.emplace(8);
	for (multiset<int>::iterator itr = mts.begin(); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << endl;
	for (multiset<int>::iterator itr = mts.lower_bound(5); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << "lower bound of 5" << endl;
	for (multiset<int>::iterator itr = mts.lower_bound(6); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << "lower bound of 6" << endl;
	for (multiset<int>::iterator itr = mts.upper_bound(5); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << "upper bound of 5" << endl;
	for (multiset<int>::iterator itr = mts.upper_bound(6); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << "upper bound of 6" << endl;
	for (multiset<int>::iterator itr = mts.lower_bound(8); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << "lower bound of 8" << endl;
	for (multiset<int>::iterator itr = mts.upper_bound(8); itr != mts.end(); itr++)
		cout << *itr << " ";
	cout << "upper bound of 8" << endl;

	// Multiset 2
	multiset<int, greater<int>> mts2;
	mts2.emplace(5);
	mts2.emplace(11);
	mts2.emplace(23);
	mts2.emplace(1);
	mts2.emplace(8);

	// This is tricky, remember that things are in backwards, 5 > 6, 5 > 8 and 5 < 1
	// Due to the greater<int> provided, really confusing!

	for (multiset<int>::iterator itr = mts2.begin(); itr != mts2.end(); itr++)
		cout << *itr << " ";
	cout << endl;
	for (multiset<int>::iterator itr = mts2.lower_bound(5); itr != mts2.end(); itr++)
		cout << *itr << " ";
	cout << "lower bound of 5 (going foward to the end)" << endl;

	multiset<int>::iterator itr;
	for (itr = mts2.lower_bound(5); itr != mts2.begin(); itr--)
		cout << *itr << " ";
	cout << *itr << " ";
	cout << "lower bound of 5 (going backward to the start)" << endl;

	for (multiset<int>::iterator itr = mts2.lower_bound(6); itr != mts2.end(); itr++)
		cout << *itr << " ";
	cout << "lower bound of 6 (going foward to the end)" << endl;

	multiset<int>::iterator itr2;
	for (itr2 = mts2.lower_bound(6); itr2 != mts2.begin(); itr2--)
		cout << *itr2 << " ";
	cout << *itr2 << " ";
	cout << "lower bound of 6 (going backward to the start)" << endl;

}