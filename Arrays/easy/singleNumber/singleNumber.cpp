#include <bits/stdc++.h>
using namespace std;

// int singleNumber(vector<int>& nums) {
// 	int size = nums.size();
// 	unordered_map<int, int> mp;
// 	int res;

// 	for (int i = 0; i < size; i++) {
// 		mp[nums[i]]++;
// 	}

// 	for (auto it : mp) {
// 		if (it.second == 1) {
// 			res = it.first;
// 		}
// 	}

// 	return res;
// }

// 0 ms Time Complexity: nlogn + n, space complexity: for sort function is logn
// int singleNumber(vector<int>& nums) {
// 	int size = nums.size();
// 	int count = 0;

// 	sort(nums.begin(), nums.end());
// 	int res = nums[0];
// 	int i = 0;
// 	while (i < size) {
// 		if (count == 1 && nums[i] != nums[i - 1]) {
// 			res = nums[i - 1];
// 			break;
// 		}
// 		if (count == 1 && nums[i] == nums[i - 1]) {
// 			count = 0;
// 			i++;
// 			continue;
// 		}
// 		count++;
// 		i++;
// 	}

// 	if (i == size) {
// 		res = nums[size - 1];
// 	}

// 	return res;
// }

// using xor
int singleNumber(vector<int>& nums) {
	int size = nums.size();
	int res = nums[0];

	for (int i = 1; i < size; i++) {
		res = res ^ nums[i];
	}

	return res;
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

	int result = singleNumber(nums);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {2, 2, 1}, 1);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {4, 1, 2, 1, 2}, 4);

	// Test Case 3: Example 3 from problem - single element
	runTestCase(3, {1}, 1);

	// Test Case 4: Single element appears at beginning
	runTestCase(4, {5, 2, 2, 3, 3}, 5);

	// Test Case 5: Single element appears at end
	runTestCase(5, {1, 1, 2, 2, 3}, 3);

	// Test Case 6: Single element appears in middle
	runTestCase(6, {1, 1, 2, 3, 3}, 2);

	// Test Case 7: Larger array
	runTestCase(7, {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6}, 6);

	// Test Case 8: Negative numbers
	runTestCase(8, {-1, -1, -2, -2, -3}, -3);

	// Test Case 9: Mix of positive and negative
	runTestCase(9, {-1, -1, 0, 1, 1}, 0);

	// Test Case 10: Large numbers
	runTestCase(10, {30000, 30000, -30000, -30000, 12345}, 12345);

	// Test Case 11: Unordered array
	runTestCase(11, {7, 3, 5, 3, 7}, 5);

	// Test Case 12: Three pairs plus one single
	runTestCase(12, {9, 8, 7, 9, 8, 7, 6}, 6);

	return 0;
}