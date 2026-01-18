#include <bits/stdc++.h>
using namespace std;

// by using extra space
// void moveZeroes(vector<int>& nums) {
// 	vector<int> temp;
// 	int size = nums.size();

// 	for (int i = 0; i < size; i++) {
// 		if (nums[i] != 0) {
// 			temp.push_back(nums[i]);
// 		}
// 	}

// 	for (int i = 0; i < temp.size(); i++) {
// 		nums[i] = temp[i];
// 	}

// 	for (int i = temp.size(); i < size; i++) {
// 		nums[i] = 0;
// 	}
// }

// in place
// void moveZeroes(vector<int>& nums) {
// 	int size = nums.size();

// 	int zeroIndex = 0;
// 	int nonZeroIndex = 0;

// 	while (nonZeroIndex < size) {
// 		int temp = nums[zeroIndex];
// 		nums[zeroIndex] = nums[nonZeroIndex];
// 		nums[nonZeroIndex] = temp;

// 		while (zeroIndex < size) {
// 			if (nums[zeroIndex] == 0) {
// 				break;
// 			}
// 			zeroIndex++;
// 		}

// 		nonZeroIndex = zeroIndex + 1;
// 		while (nonZeroIndex < size) {
// 			if (nums[nonZeroIndex] != 0) {
// 				break;
// 			}
// 			nonZeroIndex++;
// 		}
// 	}
// }

// in place but better ig
void moveZeroes(vector<int>& nums) {
	int size = nums.size();

	int nonZeroIndex = -1;

	for (int i = 0; i < size; i++) {
		if (nums[i] == 0) {
			nonZeroIndex = i;
			break;
		}
	}

	if (nonZeroIndex == -1) {
		return;
	}

	for (int i = nonZeroIndex + 1; i < size; i++) {
		if (nums[i] != 0) {
			nums[nonZeroIndex] = nums[i];
			nums[i] = 0;
			nonZeroIndex++;
		}
	}
}

////////////////
// Test cases //
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

void runTestCase(int testNum, vector<int> nums, vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;
	vector<int> original = nums;

	printArray(original, "Original");
	printArray(expected, "Expected");

	moveZeroes(nums);
	printArray(nums, "Result  ");

	bool passed = (nums == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Mixed zeros and non-zeros
	runTestCase(1, {0, 1, 0, 3, 12}, {1, 3, 12, 0, 0});

	// Test Case 2: Single zero
	runTestCase(2, {0}, {0});

	// Test Case 3: No zeros
	runTestCase(3, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});

	// Test Case 4: All zeros
	runTestCase(4, {0, 0, 0, 0}, {0, 0, 0, 0});

	// Test Case 5: Zeros at the beginning
	runTestCase(5, {0, 0, 1, 2, 3}, {1, 2, 3, 0, 0});

	// Test Case 6: Zeros at the end (already in correct position)
	runTestCase(6, {1, 2, 3, 0, 0}, {1, 2, 3, 0, 0});

	// Test Case 7: Alternating zeros and non-zeros
	runTestCase(7, {1, 0, 2, 0, 3, 0, 4}, {1, 2, 3, 4, 0, 0, 0});

	// Test Case 8: Single non-zero element
	runTestCase(8, {5}, {5});

	// Test Case 9: Alternating zeros and non-zeros
	runTestCase(7, {1, 0, 2, 5, 3, 0, 4}, {1, 2, 5, 3, 4, 0, 0});

	return 0;
}