#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// using additional n space to store positive and negative numbers
// vector<int> rearrangeArray(vector<int>& nums) {
// 	int size = nums.size();

// 	vector<int> positives;
// 	vector<int> negatives;
// 	vector<int> answer;

// 	for (int i = 0; i < size; i++) {
// 		if (nums[i] > 0) {
// 			positives.push_back(nums[i]);
// 		} else {
// 			negatives.push_back(nums[i]);
// 		}
// 	}

// 	for (int i = 0; i < size / 2; i++) {
// 		answer.push_back(positives[i]);
// 		answer.push_back(negatives[i]);
// 	}

// 	return answer;
// }

// same as above but modifying the num
// vector<int> rearrangeArray(vector<int>& nums) {
// 	int size = nums.size();

// 	vector<int> positives;
// 	vector<int> negatives;

// 	for (int i = 0; i < size; i++) {
// 		if (nums[i] > 0) {
// 			positives.push_back(nums[i]);
// 		} else {
// 			negatives.push_back(nums[i]);
// 		}
// 	}

// 	int index = 0;
// 	for (int i = 0; i < size / 2; i++) {
// 		nums[index++] = positives[i];
// 		nums[index++] = negatives[i];
// 	}

// 	return nums;
// }

// using two pointers
vector<int> rearrangeArray(vector<int>& nums) {
	int size = nums.size();

	vector<int> answer(size);
	int positive = 0;
	int negative = 1;

	for (int i = 0; i < size; i++) {
		if (nums[i] > 0) {
			answer[positive] = nums[i];
			positive += 2;
		} else {
			answer[negative] = nums[i];
			negative += 2;
		}
	}

	return answer;
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

bool isValidRearrangement(const vector<int>& result) {
	// Check if starts with positive
	if (result[0] <= 0)
		return false;

	// Check alternating signs
	for (int i = 0; i < result.size() - 1; i++) {
		if ((result[i] > 0 && result[i + 1] > 0) ||
			(result[i] < 0 && result[i + 1] < 0)) {
			return false;
		}
	}

	return true;
}

void runTestCase(int testNum, vector<int> nums, vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(nums, "nums    ");
	printArray(expected, "Expected");

	vector<int> result = rearrangeArray(nums);
	printArray(result, "Result  ");

	bool passed = (result == expected) && isValidRearrangement(result);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {3, 1, -2, -5, 2, -4}, {3, -2, 1, -5, 2, -4});

	// Test Case 2: Example 2 from problem
	runTestCase(2, {-1, 1}, {1, -1});

	// Test Case 3: Small array - alternating order
	runTestCase(3, {1, -1, 2, -2}, {1, -1, 2, -2});

	// Test Case 4: Small array - mixed order
	runTestCase(4, {-1, -2, 1, 2}, {1, -1, 2, -2});

	// Test Case 5: All positives first, then negatives
	runTestCase(5, {1, 2, 3, -1, -2, -3}, {1, -1, 2, -2, 3, -3});

	// Test Case 6: All negatives first, then positives
	runTestCase(6, {-1, -2, -3, 1, 2, 3}, {1, -1, 2, -2, 3, -3});

	// Test Case 7: Alternating already but starts negative
	runTestCase(7, {-5, 5, -10, 10}, {5, -5, 10, -10});

	// Test Case 8: Large numbers
	runTestCase(8, {100000, -100000, 50000, -50000},
				{100000, -100000, 50000, -50000});

	// Test Case 9: Same absolute values
	runTestCase(9, {5, -5, 5, -5}, {5, -5, 5, -5});

	// Test Case 10: Sequential positive and negative
	runTestCase(10, {1, 2, -1, -2, 3, -3}, {1, -1, 2, -2, 3, -3});

	// Test Case 11: Random order
	runTestCase(11, {-4, 2, -1, 5, -3, 6}, {2, -4, 5, -1, 6, -3});

	// Test Case 12: Larger array
	runTestCase(12, {10, -20, 30, -40, 50, -60, 70, -80},
				{10, -20, 30, -40, 50, -60, 70, -80});

	// Test Case 13: Mixed small and large numbers
	runTestCase(13, {1, -1000, 1000, -1, 5, -5}, {1, -1000, 1000, -1, 5, -5});

	// Test Case 14: Descending positives, ascending negatives
	runTestCase(14, {5, 4, 3, -1, -2, -3}, {5, -1, 4, -2, 3, -3});

	// Test Case 15: All elements at boundaries
	runTestCase(15, {100000, 100000, -100000, -100000},
				{100000, -100000, 100000, -100000});

	// Test Case 16: Multiple groups
	runTestCase(16, {1, 2, 3, 4, -1, -2, -3, -4}, {1, -1, 2, -2, 3, -3, 4, -4});

	// Test Case 17: Reversed pairs
	runTestCase(17, {-10, 10, -20, 20}, {10, -10, 20, -20});

	// Test Case 18: Complex pattern
	runTestCase(18, {7, -3, 2, -8, 9, -1}, {7, -3, 2, -8, 9, -1});

	return 0;
}