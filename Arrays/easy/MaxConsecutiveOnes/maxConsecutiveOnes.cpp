#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int size = nums.size();
	int maxCount = 0;
	int currentCount = 0;

	for (int i = 0; i < size; i++) {
		if (nums[i] == 1) {
			currentCount++;
			continue;
		}
		if (currentCount > maxCount) {
			maxCount = currentCount;
		}
		currentCount = 0;
	}

	if (maxCount < currentCount) {
		maxCount = currentCount;
	}

	return maxCount;
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

	int result = findMaxConsecutiveOnes(nums);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {1, 1, 0, 1, 1, 1}, 3);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {1, 0, 1, 1, 0, 1}, 2);

	// Test Case 3: All ones
	runTestCase(3, {1, 1, 1, 1, 1}, 5);

	// Test Case 4: All zeros
	runTestCase(4, {0, 0, 0, 0}, 0);

	// Test Case 5: Single one
	runTestCase(5, {1}, 1);

	// Test Case 6: Single zero
	runTestCase(6, {0}, 0);

	// Test Case 7: Ones at the beginning
	runTestCase(7, {1, 1, 1, 0, 0, 0}, 3);

	// Test Case 8: Ones at the end
	runTestCase(8, {0, 0, 0, 1, 1, 1, 1}, 4);

	// Test Case 9: Multiple sequences, max in middle
	runTestCase(9, {1, 0, 1, 1, 1, 1, 0, 1, 1}, 4);

	// Test Case 10: Alternating pattern
	runTestCase(10, {1, 0, 1, 0, 1, 0, 1}, 1);

	// Test Case 11: Large consecutive sequence
	runTestCase(11, {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}, 8);

	// Test Case 12: Two equal max sequences
	runTestCase(12, {1, 1, 1, 0, 1, 1, 1}, 3);

	return 0;
}