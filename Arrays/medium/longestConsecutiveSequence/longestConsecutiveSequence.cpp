#include <bits/stdc++.h>
using namespace std;

// Using sort TC: O(nlogn + n) SC: O(1)
// int longestConsecutive(vector<int>& nums) {
// 	int size = nums.size();
// 	int res = 0;
// 	int count = 0;

// 	sort(nums.begin(), nums.end());

// 	for (int i = 0; i < size; i++) {
// 		if (i == 0) {
// 			count++;
// 			continue;
// 		}
// 		if (nums[i] == nums[i - 1]) {
// 			continue;
// 		}
// 		if (nums[i] - nums[i - 1] > 1) {
// 			if (count > res) {
// 				res = count;
// 			}
// 			count = 0;
// 		}
// 		count++;
// 	}

// 	if (count > res) {
// 		res = count;
// 	}

// 	return res;
// }

// TC: O(n) + O(2n) SC: O(n)
int longestConsecutive(vector<int>& nums) {
	int size = nums.size();
	int res = 0;
	int count = 1;

	unordered_set<int> st;

	for (int i = 0; i < size; i++) {
		st.insert(nums[i]);
	}

	for (auto it : st) {
		int start = it;
		if (st.find(start - 1) == st.end()) {
			while (st.find(start + 1) != st.end()) {
				count++;
				start++;
			}
			res = max(res, count);
		}
		count = 1;
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

	printArray(nums, "nums    ");
	cout << "Expected: " << expected << endl;

	int result = longestConsecutive(nums);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {100, 4, 200, 1, 3, 2}, 4);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9);

	// Test Case 3: Example 3 from problem - with duplicates
	runTestCase(3, {1, 0, 1, 2}, 3);

	// Test Case 4: Empty array
	runTestCase(4, {}, 0);

	// Test Case 5: Single element
	runTestCase(5, {1}, 1);

	// Test Case 6: Two elements - consecutive
	runTestCase(6, {1, 2}, 2);

	// Test Case 7: Two elements - not consecutive
	runTestCase(7, {1, 3}, 1);

	// Test Case 8: All same elements
	runTestCase(8, {5, 5, 5, 5}, 1);

	// Test Case 9: Already sorted consecutive
	runTestCase(9, {1, 2, 3, 4, 5}, 5);

	// Test Case 10: Reverse sorted consecutive
	runTestCase(10, {5, 4, 3, 2, 1}, 5);

	// Test Case 11: Multiple sequences
	runTestCase(11, {1, 2, 3, 10, 11, 12, 13}, 4);

	// Test Case 12: No consecutive elements
	runTestCase(12, {1, 3, 5, 7, 9}, 1);

	// Test Case 13: Negative numbers
	runTestCase(13, {-3, -2, -1, 0, 1}, 5);

	// Test Case 14: Mix of positive and negative
	runTestCase(14, {-1, 0, 1, 2}, 4);

	// Test Case 15: Large gap in middle
	runTestCase(15, {1, 2, 3, 100, 101, 102, 103, 104}, 5);

	// Test Case 16: Duplicates scattered
	runTestCase(16, {1, 2, 0, 1, 2, 3}, 4);

	// Test Case 17: Large negative numbers
	runTestCase(17, {-1000000000, -999999999, -999999998}, 3);

	// Test Case 18: Zero-based sequence
	runTestCase(18, {0, 1, 2, 3}, 4);

	// Test Case 19: Sequence at end
	runTestCase(19, {50, 1, 2, 3, 4, 100}, 4);

	// Test Case 20: Random unsorted
	runTestCase(20, {9, 1, 4, 7, 3, 2, 8, 5, 6}, 9);

	// Test Case 21: Multiple duplicates
	runTestCase(21, {1, 1, 1, 2, 2, 2, 3, 3, 3}, 3);

	// Test Case 22: Large numbers
	runTestCase(22, {1000000000, 999999999, 999999998, 1}, 3);

	return 0;
}