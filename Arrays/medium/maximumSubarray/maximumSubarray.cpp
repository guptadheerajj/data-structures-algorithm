#include <bits/stdc++.h>
using namespace std;

// Brute Force - TC: O(n²), SC: O(1)
// int maxSubArray(vector<int>& nums) {
// 	int size = nums.size();
// 	int maxSum = nums[0];

// 	for (int i = 0; i < size; i++) {
// 		int sum = 0;
// 		for (int j = i; j < size; j++) {
// 			sum += nums[j];
// 			if (maxSum < sum) {
// 				maxSum = sum;
// 			}
// 		}
// 	}

// 	return maxSum;
// }

// kedans algorithm TC: O(n) SC: O(1)
int maxSubArray(vector<int>& nums) {
	int size = nums.size();

	int maxSum = INT_MIN;
	int sum = 0;

	for (int i = 0; i < size; i++) {
		sum += nums[i];

		if (sum > maxSum) {
			maxSum = sum;
		}

		if (sum < 0) {
			sum = 0;
		}
	}

	return maxSum;
}

// find the index of the maximum sub array
// NOTE: Run after print function
// int maxSubArray(vector<int>& nums) {
// 	int size = nums.size();
// 	int currentLeft = 0;
// 	int finalLeft = 0;
// 	int right = 0;

// 	int maxSum = INT_MIN;
// 	int sum = 0;

// 	for (int i = 0; i < size; i++) {
// 		// or instead of i + 1;
// 		// if (sum == 0) {
// 		// 	currentLeft = i;
// 		// }
// 		sum += nums[i];

// 		if (sum > maxSum) {
// 			maxSum = sum;
// 			right = i;
// 			finalLeft = currentLeft;
// 		}

// 		if (sum < 0) {
// 			sum = 0;
// 			currentLeft = i + 1;
// 		}
// 	}

// 	vector<int> result(nums.begin() + finalLeft, nums.begin() + right + 1);

// 	printArray(result, "Subarray");

// 	return maxSum;
// }

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

	int result = maxSubArray(nums);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {1}, 1);

	// Test Case 3: Example 3 from problem
	runTestCase(3, {5, 4, -1, 7, 8}, 23);

	// Test Case 4: All positive numbers
	runTestCase(4, {1, 2, 3, 4, 5}, 15);

	// Test Case 5: All negative numbers
	runTestCase(5, {-5, -2, -8, -1, -4}, -1);

	// Test Case 6: Mix with zero
	runTestCase(6, {-2, 0, -1}, 0);

	// Test Case 7: Single negative number
	runTestCase(7, {-3}, -3);

	// Test Case 8: Two elements - both positive
	runTestCase(8, {3, 5}, 8);

	// Test Case 9: Two elements - both negative
	runTestCase(9, {-3, -5}, -3);

	// Test Case 10: Two elements - mixed
	runTestCase(10, {-3, 5}, 5);

	// Test Case 11: Alternating positive and negative
	runTestCase(11, {5, -3, 5}, 7);

	// Test Case 12: Large positive at end
	runTestCase(12, {-2, -3, -1, 10}, 10);

	// Test Case 13: Large positive at beginning
	runTestCase(13, {10, -3, -2, -1}, 10);

	// Test Case 14: Multiple subarrays with same max
	runTestCase(14, {1, -1, 1}, 1);

	// Test Case 15: Zeros in array
	runTestCase(15, {0, -3, 1, 1}, 2);

	// Test Case 16: Maximum subarray is entire array
	runTestCase(16, {2, 3, -2, 4}, 7);

	// Test Case 17: Maximum subarray in middle
	runTestCase(17, {-1, 5, -3, 2, 3, -1}, 7);

	// Test Case 18: Large negative gap
	runTestCase(18, {8, -19, 5, -4, 20}, 21);

	// Test Case 19: All zeros
	runTestCase(19, {0, 0, 0}, 0);

	// Test Case 20: Single large positive with negatives
	runTestCase(20, {-2, -3, 100, -4, -5}, 100);

	return 0;
}