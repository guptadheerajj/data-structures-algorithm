#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
	int pivot = 0;
	bool pivotFound = false;
	int size = nums.size();

	for (int i = size - 1; i > 0; i--) {
		if (nums[i] > nums[i - 1]) {
			pivot = i;
			pivotFound = true;
			break;
		}
	}

	if (pivotFound) {
		int smallestIndex = pivot;
		for (int i = pivot; i < size; i++) {
			if (nums[i] < nums[smallestIndex] && nums[i] > nums[pivot - 1]) {
				smallestIndex = i;
			}
		}
		int temp = nums[pivot - 1];
		nums[pivot - 1] = nums[smallestIndex];
		nums[smallestIndex] = temp;
	}

	sort(nums.begin() + pivot, nums.end());
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

void runTestCase(int testNum, vector<int> nums, vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(nums, "Original");
	printArray(expected, "Expected");

	nextPermutation(nums);
	printArray(nums, "Result  ");

	bool passed = arraysEqual(nums, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {1, 2, 3}, {1, 3, 2});

	// Test Case 2: Example 2 from problem - descending (largest permutation)
	runTestCase(2, {3, 2, 1}, {1, 2, 3});

	// Test Case 3: Example 3 from problem - with duplicates
	runTestCase(3, {1, 1, 5}, {1, 5, 1});

	// Test Case 4: Single element
	runTestCase(4, {1}, {1});

	// Test Case 5: Two elements - ascending
	runTestCase(5, {1, 2}, {2, 1});

	// Test Case 6: Two elements - descending
	runTestCase(6, {2, 1}, {1, 2});

	// Test Case 7: Two same elements
	runTestCase(7, {1, 1}, {1, 1});

	// Test Case 8: Already sorted ascending
	runTestCase(8, {1, 2, 3, 4}, {1, 2, 4, 3});

	// Test Case 9: Already sorted descending
	runTestCase(9, {4, 3, 2, 1}, {1, 2, 3, 4});

	// Test Case 10: Change at beginning
	runTestCase(10, {1, 3, 2}, {2, 1, 3});

	// Test Case 11: Change in middle
	runTestCase(11, {1, 5, 8, 4, 7, 6, 5, 3, 1}, {1, 5, 8, 5, 1, 3, 4, 6, 7});

	// Test Case 12: All same elements
	runTestCase(12, {2, 2, 2, 2}, {2, 2, 2, 2});

	// Test Case 13: Zeros in array
	runTestCase(13, {0, 1, 2}, {0, 2, 1});

	// Test Case 14: With zero at end
	runTestCase(14, {1, 0}, {0, 1});

	// Test Case 15: Multiple duplicates
	runTestCase(15, {1, 3, 3, 2}, {2, 1, 3, 3});

	// Test Case 16: Large numbers
	runTestCase(16, {98, 99, 100}, {99, 100, 98});

	// Test Case 17: Second to last is pivot
	runTestCase(17, {2, 3, 1}, {3, 1, 2});

	// Test Case 18: Complex pattern
	runTestCase(18, {1, 5, 1}, {5, 1, 1});

	// Test Case 19: Near end change
	runTestCase(19, {4, 2, 0, 2, 3, 2, 0}, {4, 2, 0, 3, 0, 2, 2});

	// Test Case 20: Boundary values
	runTestCase(20, {0, 1, 0}, {1, 0, 0});

	return 0;
}