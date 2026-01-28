#include <bits/stdc++.h>
using namespace std;

// Brute Force - TC: O(n²), SC: O(n)
// vector<int> leaders(vector<int>& arr) {
// 	vector<int> ans;
// 	int size = arr.size();

// 	for (int i = 0; i < size; i++) {
// 		bool isLeader = true;
// 		for (int j = i; j < size; j++) {
// 			if (arr[i] < arr[j]) {
// 				isLeader = false;
// 				break;
// 			}
// 		}
// 		if (isLeader) {
// 			ans.push_back(arr[i]);
// 		}
// 	}

// 	return ans;
// }

// One pass - TC: O(2n) SC: O(n)
vector<int> leaders(vector<int>& arr) {
	vector<int> ans;
	int size = arr.size();

	ans.push_back(arr[size - 1]);

	for (int i = size - 2; i >= 0; i--) {
		if (arr[i] >= ans.back()) {
			ans.push_back(arr[i]);
		}
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

////////////////
// Test Cases //
////////////////

void printArray(const vector<int>& arr, const string& label) {
	cout << label << ": [";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i < arr.size() - 1)
			cout << ", ";
	}
	cout << "]" << endl;
}

bool arraysEqual(const vector<int>& a, const vector<int>& b) {
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void runTestCase(int testNum, vector<int> arr, vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(arr, "arr     ");
	printArray(expected, "Expected");

	vector<int> result = leaders(arr);
	printArray(result, "Result  ");

	bool passed = arraysEqual(result, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {16, 17, 4, 3, 5, 2}, {17, 5, 2});

	// Test Case 2: Example 2 from problem - with equal elements
	runTestCase(2, {10, 4, 2, 4, 1}, {10, 4, 4, 1});

	// Test Case 3: Example 3 from problem - increasing array
	runTestCase(3, {5, 10, 20, 40}, {40});

	// Test Case 4: Example 4 from problem - non-increasing array
	runTestCase(4, {30, 10, 10, 5}, {30, 10, 10, 5});

	// Test Case 5: Single element
	runTestCase(5, {5}, {5});

	// Test Case 6: Two elements - increasing
	runTestCase(6, {3, 7}, {7});

	// Test Case 7: Two elements - decreasing
	runTestCase(7, {7, 3}, {7, 3});

	// Test Case 8: Two equal elements
	runTestCase(8, {5, 5}, {5, 5});

	// Test Case 9: All same elements
	runTestCase(9, {3, 3, 3, 3}, {3, 3, 3, 3});

	// Test Case 10: Strictly increasing
	runTestCase(10, {1, 2, 3, 4, 5}, {5});

	// Test Case 11: Strictly decreasing
	runTestCase(11, {5, 4, 3, 2, 1}, {5, 4, 3, 2, 1});

	// Test Case 12: Leader at beginning only
	runTestCase(12, {100, 1, 2, 3, 4}, {100, 4});

	// Test Case 13: Multiple leaders in middle
	runTestCase(13, {7, 10, 4, 10, 6, 5, 2}, {10, 10, 6, 5, 2});

	// Test Case 14: Alternating high and low
	runTestCase(14, {5, 3, 6, 2, 7}, {7});

	// Test Case 15: With zeros
	runTestCase(15, {0, 0, 5, 0, 0}, {5, 0, 0});

	// Test Case 16: Large array pattern
	runTestCase(16, {1, 2, 3, 2, 1}, {3, 2, 1});

	// Test Case 17: Peak in middle
	runTestCase(17, {1, 5, 2}, {5, 2});

	// Test Case 18: Multiple equal leaders
	runTestCase(18, {8, 7, 7, 3}, {8, 7, 7, 3});

	// Test Case 19: Leader with equal element on right
	runTestCase(19, {6, 5, 4, 4, 3}, {6, 5, 4, 4, 3});

	// Test Case 20: Complex pattern
	runTestCase(20, {15, 16, 14, 13, 12, 11, 10}, {16, 14, 13, 12, 11, 10});

	return 0;
}