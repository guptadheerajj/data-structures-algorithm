#include <bits/stdc++.h>
using namespace std;

// TC: O(n²), SC: O(n²)
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
	int n = grid.size();
	vector<int> ans(2, 0);
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mp[grid[i][j]]++;
		}
	}

	for (int i = 1; i <= n * n; i++) {
		if (mp.find(i) == mp.end()) {
			ans[1] = i;
			continue;
		}
		if (mp[i] > 1) {
			ans[0] = i;
		}
	}

	return ans;
}

////////////////
// Test Cases //
////////////////

void printMatrix(const vector<vector<int>>& matrix, const string& label) {
	cout << label << ":" << endl;
	for (const auto& row : matrix) {
		cout << "  [";
		for (int i = 0; i < row.size(); i++) {
			cout << row[i];
			if (i < row.size() - 1)
				cout << ", ";
		}
		cout << "]" << endl;
	}
}

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

void runTestCase(int testNum, vector<vector<int>> grid, vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printMatrix(grid, "grid");
	printArray(expected, "Expected");

	vector<int> result = findMissingAndRepeatedValues(grid);
	printArray(result, "Result  ");

	bool passed = arraysEqual(result, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem - 2x2 grid
	runTestCase(1, {{1, 3}, {2, 2}}, {2, 4});

	// Test Case 2: Example 2 from problem - 3x3 grid
	runTestCase(2, {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}}, {9, 5});

	// Test Case 3: 2x2 - repeated is 1, missing is 2
	runTestCase(3, {{1, 1}, {3, 4}}, {1, 2});

	// Test Case 4: 2x2 - repeated is 4, missing is 1
	runTestCase(4, {{2, 3}, {4, 4}}, {4, 1});

	// Test Case 5: 3x3 - repeated at beginning
	runTestCase(5, {{1, 1, 3}, {4, 5, 6}, {7, 8, 9}}, {1, 2});

	// Test Case 6: 3x3 - repeated at end
	runTestCase(6, {{1, 2, 3}, {4, 5, 6}, {7, 8, 8}}, {8, 9});

	// Test Case 7: 3x3 - missing is 1
	runTestCase(7, {{2, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {2, 1});

	// Test Case 8: 4x4 grid
	runTestCase(8,
				{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 14, 16}},
				{14, 15});

	// Test Case 9: 4x4 - repeated is 1, missing is 16
	runTestCase(9,
				{{1, 1, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 2}},
				{1, 16});

	// Test Case 10: 4x4 - middle repeated
	runTestCase(10,
				{{1, 2, 3, 4}, {5, 8, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
				{8, 6});

	// Test Case 11: 5x5 grid
	runTestCase(11,
				{{1, 2, 3, 4, 5},
				 {6, 7, 8, 9, 10},
				 {11, 12, 13, 14, 15},
				 {16, 17, 18, 19, 20},
				 {21, 22, 23, 24, 24}},
				{24, 25});

	// Test Case 12: 5x5 - repeated early, missing late
	runTestCase(12,
				{{1, 2, 3, 4, 5},
				 {6, 7, 8, 9, 10},
				 {11, 3, 13, 14, 15},
				 {16, 17, 18, 19, 20},
				 {21, 22, 23, 24, 25}},
				{3, 12});

	// Test Case 13: 2x2 - all corners scenario
	runTestCase(13, {{3, 2}, {3, 4}}, {3, 1});

	// Test Case 14: 3x3 - middle value repeated
	runTestCase(14, {{1, 2, 3}, {4, 5, 5}, {7, 8, 9}}, {5, 6});

	// Test Case 15: 3x3 - adjacent duplicates
	runTestCase(15, {{1, 2, 2}, {4, 5, 6}, {7, 8, 9}}, {2, 3});

	// Test Case 16: 4x4 - diagonal pattern
	runTestCase(16,
				{{1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 12}},
				{12, 16});

	// Test Case 17: 6x6 grid
	runTestCase(17,
				{{1, 2, 3, 4, 5, 6},
				 {7, 8, 9, 10, 11, 12},
				 {13, 14, 15, 16, 17, 18},
				 {19, 20, 21, 22, 23, 24},
				 {25, 26, 27, 28, 29, 30},
				 {31, 32, 33, 34, 35, 35}},
				{35, 36});

	// Test Case 18: 3x3 - first and last swapped
	runTestCase(18, {{9, 2, 3}, {4, 5, 6}, {7, 8, 9}}, {9, 1});

	// Test Case 19: 2x2 - sequential with one repeat
	runTestCase(19, {{2, 1}, {3, 3}}, {3, 4});

	// Test Case 20: 4x4 - large repeated value
	runTestCase(20,
				{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 15}},
				{15, 16});

	return 0;
}