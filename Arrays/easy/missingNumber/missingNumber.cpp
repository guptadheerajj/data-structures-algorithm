#include <bits/stdc++.h>
using namespace std;

// brute force -> spce complexity: O(n), time complexity: O(2n) , 22ms
// int missingNumber(vector<int>& nums) {
// 	int size = nums.size();
// 	int missing = size;
// 	unordered_set<int> ust;

// 	for (int i = 0; i < size; i++) {
// 		ust.insert(nums[i]);
// 	}

// 	for (int i = 0; i < size; i++) {
// 		if (!ust.count(i)) {
// 			missing = i;
// 			break;
// 		}
// 	}

// 	return missing;
// }

// using sort function, time complexity: O(n + nlogn)
int missingNumber(vector<int>& nums) {
	int size = nums.size();
	int missing = size;
	sort(nums.begin(), nums.end());

	for (int i = 0; i < size; i++) {
		if (i != nums[i]) {
			missing = i;
			break;
		}
	}

	return missing;
}

// best approach -> Time complexity: O(n), space complexity: O(1)
// in this approach the sum of all elements is used to find the missing number
int missingNumber(vector<int>& nums) {
	int n = nums.size();
	int sum = n * (n + 1) / 2;
	int actualSum = 0;

	for (int i = 0; i < n; i++) {
		actualSum += nums[i];
	}

	return sum - actualSum;
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

	printArray(nums, "Original");
	cout << "Expected: " << expected << endl;

	int result = missingNumber(nums);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Missing number in middle
	runTestCase(1, {3, 0, 1}, 2);

	// Test Case 2: Missing number is 2
	runTestCase(2, {0, 1}, 2);

	// Test Case 3: Missing number is 8
	runTestCase(3, {9, 6, 4, 2, 3, 5, 7, 0, 1}, 8);

	// Test Case 4: Missing number is 0
	runTestCase(4, {1, 2, 3, 4, 5}, 0);

	// Test Case 5: Missing number is last (n)
	runTestCase(5, {0, 1, 2, 3, 4}, 5);

	// Test Case 6: Single element array, missing 0
	runTestCase(6, {1}, 0);

	// Test Case 7: Single element array, missing 1
	runTestCase(7, {0}, 1);

	// Test Case 8: Larger array
	runTestCase(8, {0, 1, 2, 3, 4, 5, 6, 8, 9, 10}, 7);

	return 0;
}