#include <bits/stdc++.h>
using namespace std;

// brute force
// vector<int> twoSum(vector<int>& nums, int target) {
// 	vector<int> solution;
// 	for (int i = 0; i < nums.size(); i++) {
// 		for (int j = i + 1; j < nums.size(); j++) {
// 			if (target == (nums[i] + nums[j])) {
// 				solution.push_back(i);
// 				solution.push_back(j);
// 				break;
// 			}
// 		}
// 	}
// 	return solution;
// }

// using hash map but with 2 iterations
// vector<int> twoSum(vector<int>& nums, int target) {
// 	int size = nums.size();
// 	vector<int> res;
// 	unordered_map<int, int> mp;

// 	for (int i = 0; i < size; i++) {
// 		mp[nums[i]] = i;
// 	}

// 	for (int i = 0; i < size; i++) {
// 		if ((mp.find(target - nums[i]) != mp.end()) &&
// 			(mp[target - nums[i]] != i)) {
// 			res.push_back(i);
// 			res.push_back(mp[target - nums[i]]);
// 			break;
// 		}
// 	}
// 	return res;
// }

// best using hash map but only 1 iteration
vector<int> twoSum(vector<int>& nums, int target) {
	int size = nums.size();
	unordered_map<int, int> mp;

	for (int i = 0; i < size; i++) {
		if (mp.find(target - nums[i]) != mp.end()) {
			return {i, mp[target - nums[i]]};
		}
		mp[nums[i]] = i;
	}
	return {};
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

void runTestCase(int testNum, vector<int> nums, int target,
				 vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(nums, "nums    ");
	cout << "target  : " << target << endl;
	cout << "Expected: [" << expected[0] << ", " << expected[1] << "]" << endl;

	vector<int> result = twoSum(nums, target);
	cout << "Result  : [" << result[0] << ", " << result[1] << "]" << endl;

	// Check if result matches expected (can be in any order)
	bool passed = (result[0] == expected[0] && result[1] == expected[1]) ||
				  (result[0] == expected[1] && result[1] == expected[0]);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {2, 7, 11, 15}, 9, {0, 1});

	// Test Case 2: Example 2 from problem
	runTestCase(2, {3, 2, 4}, 6, {1, 2});

	// Test Case 3: Example 3 from problem
	runTestCase(3, {3, 3}, 6, {0, 1});

	// Test Case 4: Two elements, exact match
	runTestCase(4, {1, 2}, 3, {0, 1});

	// Test Case 5: Negative numbers
	runTestCase(5, {-1, -2, -3, -4, -5}, -8, {2, 4});

	// Test Case 6: Mix of positive and negative
	runTestCase(6, {-3, 4, 3, 90}, 0, {0, 2});

	// // Test Case 7: Large numbers
	// runTestCase(7, {1000000000, -1000000000, 5}, 5, {1, 2});

	// // Test Case 8: Zero in array
	// runTestCase(8, {0, 4, 3, 0}, 0, {0, 3});

	// Test Case 9: Target is negative
	runTestCase(9, {-10, -1, -18, -19}, -19, {1, 3});

	// Test Case 10: Multiple elements, solution at end
	runTestCase(10, {1, 2, 3, 4, 5, 6}, 11, {4, 5});

	// Test Case 11: Solution at beginning
	runTestCase(11, {5, 75, 25}, 100, {1, 2});

	// Test Case 12: Large array
	runTestCase(12, {2, 5, 5, 11, 14, 20, 8}, 10, {0, 6});

	// // Test Case 13: Consecutive duplicates
	// runTestCase(13, {1, 1, 1, 1, 5}, 6, {3, 4});

	// Test Case 14: Small target with large numbers
	runTestCase(14, {100, 200, 300, 1, 2}, 3, {3, 4});

	return 0;
}