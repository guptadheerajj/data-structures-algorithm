#include <bits/stdc++.h>
using namespace std;

// Using HashMap - TC: O(n), SC: O(n)
// int majorityElement(vector<int>& nums) {
// 	int size = nums.size();
// 	int res;
// 	unordered_map<int, int> mp;

// 	for (int i = 0; i < size; i++) {
// 		mp[nums[i]]++;
// 	}

// 	for (auto it : mp) {
// 		if (it.second > (size / 2)) {
// 			res = it.first;
// 		}
// 	}
// 	return res;
// }

// using sort TC: O(nlogn + n) SC: O(logn)
// int majorityElement(vector<int>& nums) {
// 	int size = nums.size();
// 	// int res;
// 	int count = 1;
// 	sort(nums.begin(), nums.end());

// 	for (int i = 1; i < size; i++) {
// 		if (nums[i] != nums[i - 1]) {
// 			if (count > (size / 2)) {
// 				return nums[i - 1];
// 			}
// 			count = 1;
// 			continue;
// 		}
// 		count++;
// 	}

// 	// if (count > (size / 2)) {
// 	// 	res = nums[size - 1];
// 	// }
// 	// return res;
// 	return nums[size - 1];
// }

// using Moore's Voting Algorithm
int majorityElement(vector<int>& nums) {
	int size = nums.size();
	int el = nums[0];
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (count == 0) {
			el = nums[i];
			count = 1;
		} else if (el == nums[i]) {
			count++;
		} else {
			count--;
		}
	}

	return el;
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

void runTestCase(int testNum, vector<int> nums, int expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(nums, "nums    ");
	cout << "Expected: " << expected << endl;

	int result = majorityElement(nums);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {3, 2, 3}, 3);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {2, 2, 1, 1, 1, 2, 2}, 2);

	// Test Case 3: Single element
	runTestCase(3, {1}, 1);

	// Test Case 4: All same elements
	runTestCase(4, {5, 5, 5, 5, 5}, 5);

	// Test Case 5: Majority at beginning
	runTestCase(5, {1, 1, 1, 2, 3}, 1);

	// Test Case 6: Majority at end
	runTestCase(6, {1, 2, 3, 3, 3}, 3);

	// Test Case 7: Majority in middle
	runTestCase(7, {1, 2, 2, 2, 3}, 2);

	// Test Case 8: Two elements - both same
	runTestCase(8, {7, 7}, 7);

	// Test Case 9: Two elements - different (first is majority)
	runTestCase(9, {4, 4, 3}, 4);

	// Test Case 10: Negative numbers
	runTestCase(10, {-1, -1, -1, 2, 2}, -1);

	// Test Case 11: Mix of positive and negative
	runTestCase(11, {-5, -5, 10, -5, 10, -5}, -5);

	// Test Case 12: Large numbers
	runTestCase(12, {1000000000, 1000000000, 1, 1000000000}, 1000000000);

	// Test Case 13: Zero as majority
	runTestCase(13, {0, 0, 1, 0, 2}, 0);

	// Test Case 14: Appears exactly n/2 + 1 times
	runTestCase(14, {1, 1, 1, 2, 2, 2, 1}, 1);

	// Test Case 15: Large array with clear majority
	runTestCase(15, {4, 4, 2, 4, 3, 4, 4, 3, 2, 4}, 4);

	// Test Case 16: Majority appears consecutively
	runTestCase(16, {8, 8, 8, 8, 1, 2, 3}, 8);

	// Test Case 17: Majority scattered throughout
	runTestCase(17, {9, 1, 9, 2, 9, 3, 9}, 9);

	// Test Case 18: Only two distinct elements
	runTestCase(18, {6, 6, 6, 7, 7}, 6);

	return 0;
}