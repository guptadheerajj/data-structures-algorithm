#include <bits/stdc++.h>
using namespace std;

// Two Pass i.e. counting algorithm
// void sortColors(vector<int>& nums) {
// 	int countArr[3] = {0};
// 	int size = nums.size();
// 	for (int i = 0; i < size; i++) {
// 		countArr[nums[i]]++;
// 	}

// 	for (int i = 0; i < countArr[0]; i++) {
// 		nums[i] = 0;
// 	}
// 	for (int i = countArr[0]; i < (countArr[0] + countArr[1]); i++) {
// 		nums[i] = 1;
// 	}
// 	for (int i = countArr[0] + countArr[1];
// 		 i < (countArr[0] + countArr[1] + countArr[2]); i++) {
// 		nums[i] = 2;
// 	}
// }

// One pass DNF algorithm
void sortColors(vector<int>& nums) {
	int size = nums.size();

	int low = 0;
	int mid = 0;
	int high = size - 1;

	while (mid <= high) {
		if (nums[mid] == 0) {
			nums[mid] = nums[low];
			nums[low] = 0;
			mid++;
			low++;
		} else if (nums[mid] == 1) {
			mid++;
		} else if (nums[mid] == 2) {
			nums[mid] = nums[high];
			nums[high] = 2;
			high--;
		}
	}
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

	sortColors(nums);
	printArray(nums, "Result  ");

	bool passed = arraysEqual(nums, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {2, 0, 2, 1, 1, 0}, {0, 0, 1, 1, 2, 2});

	// Test Case 2: Example 2 from problem
	runTestCase(2, {2, 0, 1}, {0, 1, 2});

	// Test Case 3: Already sorted
	runTestCase(3, {0, 1, 2}, {0, 1, 2});

	// Test Case 4: Reverse sorted
	runTestCase(4, {2, 2, 1, 1, 0, 0}, {0, 0, 1, 1, 2, 2});

	// Test Case 5: All same color - all 0s
	runTestCase(5, {0, 0, 0, 0}, {0, 0, 0, 0});

	// Test Case 6: All same color - all 1s
	runTestCase(6, {1, 1, 1, 1}, {1, 1, 1, 1});

	// Test Case 7: All same color - all 2s
	runTestCase(7, {2, 2, 2, 2}, {2, 2, 2, 2});

	// Test Case 8: Single element - 0
	runTestCase(8, {0}, {0});

	// Test Case 9: Single element - 1
	runTestCase(9, {1}, {1});

	// Test Case 10: Single element - 2
	runTestCase(10, {2}, {2});

	// Test Case 11: Two elements
	runTestCase(11, {2, 0}, {0, 2});

	// Test Case 12: Only 0s and 2s
	runTestCase(12, {2, 0, 2, 0, 2, 0}, {0, 0, 0, 2, 2, 2});

	// Test Case 13: Only 0s and 1s
	runTestCase(13, {1, 0, 1, 0, 1}, {0, 0, 1, 1, 1});

	// Test Case 14: Only 1s and 2s
	runTestCase(14, {2, 1, 2, 1, 2}, {1, 1, 2, 2, 2});

	// Test Case 15: Large array
	runTestCase(15, {2, 0, 1, 2, 1, 0, 2, 1, 0}, {0, 0, 0, 1, 1, 1, 2, 2, 2});

	// Test Case 16: Mostly 0s
	runTestCase(16, {0, 0, 0, 1, 0, 0, 2}, {0, 0, 0, 0, 0, 1, 2});

	// Test Case 17: Mostly 2s
	runTestCase(17, {2, 2, 0, 2, 2, 1, 2}, {0, 1, 2, 2, 2, 2, 2});

	// Test Case 18: Random order
	runTestCase(18, {1, 2, 0, 1, 2, 0, 1}, {0, 0, 1, 1, 1, 2, 2});

	return 0;
}