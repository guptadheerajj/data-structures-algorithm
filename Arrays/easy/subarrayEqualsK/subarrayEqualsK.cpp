#include <bits/stdc++.h>
using namespace std;

// brute force, TC: n2
// int subarraySum(vector<int>& nums, int k) {
// 	int size = nums.size();
// 	int count = 0;

// 	for (int i = 0; i < size; i++) {
// 		int sum = 0;
// 		for (int j = i; j < size; j++) {
// 			sum += nums[j];
// 			if (sum == k) {
// 				count++;
// 			}
// 		}
// 	}

// 	return count;
// }

// better -> using  map; sc: O(n), tc O(n)
int subarraySum(vector<int>& nums, int k) {
	int size = nums.size();
	int count = 0;
	int sum = 0;
	unordered_map<int, int> mp;

	for (int i = 0; i < size; i++) {
		sum += nums[i];
		if (sum == k) {
			count++;
		}
		if (mp.find(sum - k) != mp.end()) {
			count += mp[sum - k];
		}
		mp[sum]++;
	}

	return count;
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

void runTestCase(int testNum, vector<int> nums, int k, int expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(nums, "Original");
	cout << "k       : " << k << endl;
	cout << "Expected: " << expected << endl;

	int result = subarraySum(nums, k);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {1, 1, 1}, 2, 2);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {1, 2, 3}, 3, 2);

	// Test Case 3: Single element equals k
	runTestCase(3, {5}, 5, 1);

	// Test Case 4: Single element not equals k
	runTestCase(4, {5}, 3, 0);

	// Test Case 5: Multiple subarrays with same sum
	runTestCase(5, {1, 2, 1, 2, 1}, 3, 4);

	// Test Case 6: k = 0 with zeros in array
	runTestCase(6, {0, 0, 0}, 0, 6);

	// Test Case 7: Negative numbers
	runTestCase(7, {-1, -1, 1}, 0, 1);

	// Test Case 8: Mix of positive and negative
	runTestCase(8, {1, -1, 1, -1, 1}, 0, 6);

	// Test Case 9: Entire array sums to k
	runTestCase(9, {1, 2, 3, 4, 5}, 15, 1);

	// Test Case 10: No subarray equals k
	runTestCase(10, {1, 2, 3}, 10, 0);

	// Test Case 11: Large k value
	runTestCase(11, {1, 1, 1}, 5, 0);

	// Test Case 12: Multiple overlapping subarrays
	runTestCase(12, {3, 4, 7, 2, -3, 1, 4, 2}, 7, 4);

	// Test Case 13: Negative k
	runTestCase(13, {1, -1, -1, -1}, -2, 3);

	// Test Case 14: All same elements
	runTestCase(14, {2, 2, 2, 2}, 4, 3);

	return 0;
}