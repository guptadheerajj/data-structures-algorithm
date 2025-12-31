#include <bits/stdc++.h>

using namespace std;

void printName() {
	cout << "megh";
}

int sum(int a, int b) {
	return a + b;
}

// * Containers and Iterators

void explainPair() {
	pair<int, int> p = {1, 8};
	cout << p.first << " " << p.second << endl;

	pair<int, pair<int, int>> p1 = {1, {2, 3}};
	cout << p1.first << " " << p1.second.second << " " << p1.second.first
		 << endl;

	pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
	cout << arr[1].first << " " << arr[1].second;
}

void explainVector() {
	// * Different ways to initialize a vector
	vector<int> v;

	// Adding elements to vector
	// push_back copies the element, emplace_back constructs in place (more
	// efficient)
	v.push_back(1);		// {1}
	v.emplace_back(2);	// {1, 2}

	// Vector of pairs
	vector<pair<int, int>> vec;

	vec.push_back({1, 8});	 // needs braces for pair
	vec.emplace_back(1, 2);	 // no braces needed, directly constructs pair

	// Initialize vector with 5 elements, all set to 100
	vector<int> vecc(5, 100);  // {100, 100, 100, 100, 100}

	// Initialize vector with 5 elements, default value 0
	vector<int> vdef(5);  // {0, 0, 0, 0, 0}

	// Initialize vector with 5 elements, all set to 20
	vector<int> v1(5, 20);	// {20, 20, 20, 20, 20}

	// Copy constructor - creates a copy of v1
	// vector<int> v2(v1);

	// * Accessing elements in vector

	// Method 1: Using [] operator or at() method
	cout << vecc[0] << " ";		 // Access first element (no bounds checking)
	cout << vecc.at(0) << " ";	 // Access first element (with bounds checking)
	cout << vecc.back() << " ";	 // Access last element

	// Method 2: Using iterators
	// begin() points to first element, end() points to position after last
	// element
	vector<int>::iterator it1 = v.begin();
	it1++;
	cout << *(it1) << " ";	// Dereference iterator to get value

	it1 += 2;
	cout << *(it1) << " ";

	// end() iterator (points past the last element)
	vector<int>::iterator it_end = v.end();

	// * Different ways to print/iterate through vector

	// Method 1: Using iterator (full syntax)
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
		cout << *(iter) << " ";
	}

	// Method 2: Using auto keyword (shorter, preferred)
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *(iter) << " ";
	}

	// Method 3: Range-based for loop (simplest, most readable)
	for (auto element : v) {
		cout << element << " ";
	}

	// * Deletion from vector
	// Example: v = {10, 20, 30, 40}
	v.erase(v.begin() + 1);	 // Removes element at index 1 -> {10, 30, 40}

	// Example: v = {10, 20, 12, 23, 35}
	// Erase range [start, end) - start is inclusive, end is exclusive
	v.erase(v.begin() + 2,
			v.begin() + 4);	 // Removes index 2 and 3 -> {10, 20, 35}

	// * Insertion into vector
	vector<int> vins(2, 100);  // {100, 100}

	// Insert single element at position
	vins.insert(vins.begin(), 300);	 // {300, 100, 100}

	// Insert multiple copies of same value
	vins.insert(vins.begin() + 1, 2,
				10);  // Insert 2 copies of 10 -> {300, 10, 10, 100, 100}

	// Insert another vector/range
	vector<int> copy(2, 50);  // {50, 50}
	vins.insert(vins.begin(), copy.begin(),
				copy.end());  // {50, 50, 300, 10, 10, 100, 100}

	// * Other useful vector functions

	// Get size of vector
	// Example: v = {10, 20}
	cout << v.size();  // Prints: 2

	// Remove last element
	// Example: v = {10, 20, 30}
	v.pop_back();  // v becomes {10, 20}

	// Swap contents of two vectors (very efficient, just swaps pointers)
	// v1 = {10, 20}
	// v2 = {30, 40}
	vector<int> v2;
	v2.push_back(30);
	v2.push_back(40);
	v1.swap(v2);
	// After swap: v1 = {30, 40}, v2 = {10, 20}

	// Clear all elements from vector
	v.clear();	// Removes all elements, size becomes 0

	// Check if vector is empty
	cout << v.empty();	// Returns 1 (true) if empty, 0 (false) if has elements
}

void explainList() {
	// * List (Doubly Linked List)
	// - Allows insertion/deletion from both front and back in O(1)
	// - No random access (can't use [] operator)
	// - Use when you need frequent insertions/deletions in middle

	list<int> ls;

	ls.push_back(2);	 // Insert at back: {2}
	ls.emplace_back(4);	 // Insert at back: {2, 4}

	ls.push_front(5);	  // Insert at front: {5, 2, 4}
	ls.emplace_front(1);  // Insert at front: {1, 5, 2, 4}

	ls.pop_front();	 // Remove from front: {5, 2, 4}
	ls.pop_back();	 // Remove from back: {5, 2}

	// Other functions: begin, end, rbegin, rend, clear, insert, size, swap
	// Same as vector except no [] operator or at() for random access
}

void explainDequeue() {
	// * Deque (Double-Ended Queue)
	// - Supports insertion/deletion from both ends in O(1)
	// - Supports random access using [] operator (like vector)
	// - More flexible than vector for front operations

	deque<int> dq;

	dq.push_back(1);	  // Insert at back: {1}
	dq.emplace_back(2);	  // Insert at back: {1, 2}
	dq.push_front(9);	  // Insert at front: {9, 1, 2}
	dq.emplace_front(8);  // Insert at front: {8, 9, 1, 2}

	dq.pop_back();	 // Remove from back: {8, 9, 1}
	dq.pop_front();	 // Remove from front: {9, 1}

	dq.back();	 // Access last element
	dq.front();	 // Access first element

	// Also supports: begin, end, rbegin, rend, clear, insert, size, swap
	// Can use dq[index] for random access
}

void explainStack() {
	// * Stack - LIFO (Last In, First Out)
	// - Only top element is accessible
	// - All operations O(1) time complexity
	// - Use for: DFS, expression evaluation, backtracking

	stack<int> st;
	st.push(1);		// Stack: [1] (bottom to top)
	st.push(2);		// Stack: [1, 2]
	st.push(3);		// Stack: [1, 2, 3]
	st.push(4);		// Stack: [1, 2, 3, 4]
	st.emplace(5);	// Stack: [1, 2, 3, 4, 5]

	cout << st.top();  // Access top element: prints 5

	st.pop();  // Remove top element -> Stack: [1, 2, 3, 4]

	cout << st.top();	 // prints 4
	cout << st.size();	 // prints 4
	cout << st.empty();	 // prints 0 (false)

	// Swap contents of two stacks
	stack<int> st1, st2;
	st1.swap(st2);
}

void explainQueue() {
	// * Queue - FIFO (First In, First Out)
	// - Insert at back, remove from front
	// - All operations O(1) time complexity
	// - Use for: BFS, level order traversal, scheduling

	queue<int> q;
	q.push(1);	   // Queue: [1] (front to back)
	q.push(2);	   // Queue: [1, 2]
	q.emplace(4);  // Queue: [1, 2, 4]

	// Modify last element
	q.back() += 5;	// Last element 4 becomes 9

	cout << q.back();  // Access last element: prints 9

	// Queue is now: [1, 2, 9]
	cout << q.front();	// Access first element: prints 1

	q.pop();  // Remove from front -> Queue: [2, 9]

	cout << q.front();	// prints 2

	// Also available: size(), swap(), empty()
}

void explainPQ() {
	// Priority Queue

	priority_queue<int> pq;
	pq.push(5);	  // 5
	pq.push(2);	  // 5,2
	pq.push(8);	  // 8,5,2
	pq.push(10);  // 10,8,5,2

	cout << pq.top();  // 10
	pq.pop();		   // {8,5,2}

	cout << pq.top();  // 8
	// size swap empty same as stack

	// minimum Heap
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5);		 // 5
	pq.push(2);		 // 2,5
	pq.push(8);		 // 2,5,8
	pq.emplace(10);	 // 2,5,8,10

	cout << pq.top();  // 2
}

void explainSet() {
	// * Set - Stores unique elements in sorted order
	// - All operations O(log n) time
	// - No duplicates allowed
	// - Implemented as balanced BST (Red-Black Tree)
	// - Use for: maintaining sorted unique elements

	set<int> st;
	st.insert(1);	// {1}
	st.emplace(2);	// {1, 2}
	st.insert(2);	// {1, 2} - duplicate not added
	st.insert(4);	// {1, 2, 4}
	st.insert(3);	// {1, 2, 3, 4} - automatically sorted

	// emplace is slightly more efficient than insert
	// Available: begin, end, rbegin, rend, size, empty, swap

	// * Finding elements
	// Set: {1, 2, 3, 4, 5}
	auto it_find1 = st.find(3);	 // Returns iterator to 3

	// If element not found, returns st.end()
	auto it_find2 = st.find(6);	 // Returns st.end()

	// * Erasing elements
	// Method 1: Erase by value - O(log n)
	st.erase(5);  // Removes 5 if present

	// count() returns 1 if element exists, 0 otherwise
	int cnt = st.count(1);

	// Method 2: Erase by iterator - O(1)
	auto it_erase = st.find(3);
	if (it_erase != st.end()) {
		st.erase(it_erase);
	}

	// Method 3: Erase range [first, last) - O(n)
	// Example: {1, 2, 3, 4, 5}
	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2);	 // Erases 2 and 3 -> {1, 4, 5}

	// * Lower and Upper Bound
	// lower_bound(x): first element >= x
	// upper_bound(x): first element > x
	auto lb = st.lower_bound(2);  // Points to 2
	auto ub = st.upper_bound(3);  // Points to 4
}

void explainMultiSet() {
	// * Multiset - Same as set but allows duplicates
	// - Stores elements in sorted order
	// - Can have multiple copies of same element
	// - All operations O(log n)

	multiset<int> ms;
	ms.insert(1);  // {1}
	ms.insert(1);  // {1, 1}
	ms.insert(1);  // {1, 1, 1}

	// CAREFUL: erase(value) removes ALL occurrences
	ms.erase(1);  // All 1's removed -> {}

	// count() returns number of occurrences
	ms.insert(1);
	ms.insert(1);
	int cnt = ms.count(1);	// Returns 2

	// To erase only ONE occurrence, use find() + erase()
	ms.erase(ms.find(1));  // Removes only one 1

	// All other functions same as set
	// begin, end, size, empty, lower_bound, upper_bound
}

void explainUSet() {
	// * Unordered Set - Stores unique elements (no order)
	// - Implemented using Hash Table
	// - Average O(1) for insert, find, erase
	// - Worst case O(n) when hash collisions occur
	// - Use when you don't need sorted order

	unordered_set<int> ust;
	ust.insert(5);
	ust.insert(2);
	ust.insert(8);	// May store in any order: {8, 2, 5} or {5, 8, 2} etc.

	// All functions same as set EXCEPT:
	// - NO lower_bound() and upper_bound() (because no order)
	// - Much faster for insert/find/erase on average

	// Available: insert, erase, find, count, size, empty
}

void explainMap() {
	// * Map - Stores key-value pairs in sorted order by key
	// - Keys are unique and sorted
	// - All operations O(log n)
	// - Implemented as balanced BST

	// Different types of maps
	map<int, int> mpp1;				// key: int, value: int
	map<int, pair<int, int>> mpp2;	// key: int, value: pair
	map<pair<int, int>, int> mpp3;	// key: pair, value: int

	// * Inserting elements
	mpp1[1] = 2;		  // Method 1: Using [] operator
	mpp1.emplace(3, 1);	  // Method 2: Using emplace (efficient)
	mpp1.insert({2, 4});  // Method 3: Using insert
	mpp3[{2, 3}] = 10;	  // Pair as key

	// * Iterating through map
	// Iterator gives pair: it.first = key, it.second = value
	for (auto it : mpp1) {
		cout << it.first << " " << it.second << endl;
	}

	// * Accessing elements
	cout << mpp1[1];  // Prints 2 (value for key 1)
	// CAREFUL: If key doesn't exist, [] creates it with default value 0
	cout << mpp1[5];  // Creates key 5 with value 0, prints 0

	// * Finding elements
	auto it_map1 = mpp1.find(3);  // Returns iterator to key 3
	if (it_map1 != mpp1.end()) {
		cout << it_map1->second;  // Access value
	}

	auto it_map2 = mpp2.find(5);  // Returns mpp2.end() if not found

	// * Lower and Upper Bound (works on keys)
	auto lb_map = mpp1.lower_bound(2);	// First key >= 2
	auto ub_map = mpp1.upper_bound(3);	// First key > 3

	// Also available: erase, size, empty, clear, count
}

void explainMultiMap() {
	// * Multimap - Same as map but allows duplicate keys
	// - Keys can repeat, stored in sorted order
	// - All operations O(log n)

	multimap<int, int> mmp;	 // key: int, value: int

	// Can have same key with different values
	mmp.insert({1, 10});
	mmp.insert({1, 20});  // Same key 1 with different value
	mmp.insert({2, 30});
	// Map: {(1,10), (1,20), (2,30)}

	// Everything same as map EXCEPT:
	// - CANNOT use mmp[key] operator (because multiple values per key)
	// - Use insert() or emplace() only
	// - count(key) returns number of occurrences of key
}

void explainUnorderdMap() {
	// * Unordered Map - Key-value pairs with no order
	// - Implemented using Hash Table
	// - Average O(1) for insert, find, erase
	// - Worst case O(n) when hash collisions occur
	// - Keys are unique (like map)
	// - Use when you don't need sorted keys

	unordered_map<int, int> umpp;
	umpp[1] = 100;
	umpp[5] = 200;
	umpp[3] = 150;
	// No specific order guaranteed

	// All functions same as map EXCEPT:
	// - NO lower_bound() and upper_bound()
	// - Much faster on average

	// Available: insert, erase, find, [], count, size, empty
}

// * Algorithms

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second)
		return true;
	if (p1.second > p2.second)
		return false;  // swap
	//    if they are same

	if (p1.first > p2.first)
		return true;
	return false;
}

void explainExtra() {
	// * SORTING

	// Sort array in ascending order
	int a[] = {5, 2, 8, 1, 9};
	int n = 5;
	sort(a, a + n);	 // a becomes {1, 2, 5, 8, 9}

	// Sort vector in ascending order
	vector<int> v = {5, 2, 8, 1, 9};
	sort(v.begin(), v.end());  // v becomes {1, 2, 5, 8, 9}

	// Sort only part of array (first 4 elements)
	int arr[] = {5, 2, 8, 1, 9, 3};
	sort(arr, arr + 4);	 // First 4 elements sorted: {1, 2, 5, 8, 9, 3}

	// Sort in descending order using greater<int>()
	sort(a, a + n, greater<int>());	 // a becomes {9, 8, 5, 2, 1}

	// * CUSTOM COMPARATOR
	// Sort array of pairs with custom logic
	pair<int, int> pairs[] = {{1, 2}, {2, 1}, {4, 1}};
	int pairSize = 3;
	// Sort by: 2nd element ascending, if same then 1st element descending
	sort(pairs, pairs + pairSize, comp);
	// Result: {{4,1}, {2,1}, {1,2}}

	// * BUILTIN FUNCTIONS

	// Count number of set bits (1's) in binary representation
	int num = 7;						// Binary: 111
	int cnt = __builtin_popcount(num);	// Returns 3

	// For long long numbers
	long long bigNum = 1234566743373;
	int cntLL = __builtin_popcountll(bigNum);

	// * PERMUTATIONS
	// Generate all permutations of a string
	string s = "123";
	sort(s.begin(), s.end());  // Must sort first
	do {
		cout << s << endl;	// Prints: 123, 132, 213, 231, 312, 321
	} while (next_permutation(s.begin(), s.end()));

	// * MIN/MAX ELEMENT
	// Find maximum element in array
	int arrMax[] = {3, 7, 2, 9, 1};
	int maxElement = *max_element(arrMax, arrMax + 5);	// Returns 9
	int minElement = *min_element(arrMax, arrMax + 5);	// Returns 1
}

int main() {
	// printName();
	// int s;
	// s = sum(1, 2);
	// cout<<s;

	//* explainPair();

	return 0;
}