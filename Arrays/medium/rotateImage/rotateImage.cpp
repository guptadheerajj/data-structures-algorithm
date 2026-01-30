#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	vector<vector<int>> ans(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[j][n - i - 1] = matrix[i][j];
		}
	}

	matrix = ans;
}

/*
n = 3
ij -> j(n-i-1)
00 -> 02
01 -> 12
02 -> 22

10 -> 01
11 -> 11
12 -> 21

20 -> 00
21 -> 10
22 -> 20
*/

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

bool matricesEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	if (a.size() != b.size())
		return false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i].size() != b[i].size())
			return false;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] != b[i][j])
				return false;
		}
	}
	return true;
}

void runTestCase(int testNum, vector<vector<int>> matrix,
				 vector<vector<int>> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printMatrix(matrix, "Original");
	printMatrix(expected, "Expected");

	rotate(matrix);
	printMatrix(matrix, "Result");

	bool passed = matricesEqual(matrix, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem - 3x3 matrix
	runTestCase(1, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
				{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}});

	// Test Case 2: Example 2 from problem - 4x4 matrix
	runTestCase(
		2, {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
		{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}});

	// Test Case 3: 1x1 matrix
	runTestCase(3, {{1}}, {{1}});

	// Test Case 4: 2x2 matrix
	runTestCase(4, {{1, 2}, {3, 4}}, {{3, 1}, {4, 2}});

	// Test Case 5: 2x2 with same numbers
	runTestCase(5, {{1, 1}, {1, 1}}, {{1, 1}, {1, 1}});

	// Test Case 6: 3x3 with zeros
	runTestCase(6, {{0, 1, 2}, {3, 0, 4}, {5, 6, 0}},
				{{5, 3, 0}, {6, 0, 1}, {0, 4, 2}});

	// Test Case 7: 3x3 all zeros
	runTestCase(7, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
				{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});

	// Test Case 8: 3x3 with negative numbers
	runTestCase(8, {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}},
				{{-7, -4, -1}, {-8, -5, -2}, {-9, -6, -3}});

	// Test Case 9: 3x3 mixed positive and negative
	runTestCase(9, {{1, -2, 3}, {-4, 5, -6}, {7, -8, 9}},
				{{7, -4, 1}, {-8, 5, -2}, {9, -6, 3}});

	// Test Case 10: 5x5 matrix
	runTestCase(10,
				{{1, 2, 3, 4, 5},
				 {6, 7, 8, 9, 10},
				 {11, 12, 13, 14, 15},
				 {16, 17, 18, 19, 20},
				 {21, 22, 23, 24, 25}},
				{{21, 16, 11, 6, 1},
				 {22, 17, 12, 7, 2},
				 {23, 18, 13, 8, 3},
				 {24, 19, 14, 9, 4},
				 {25, 20, 15, 10, 5}});

	// Test Case 11: Identity matrix 3x3
	runTestCase(11, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}},
				{{0, 0, 1}, {0, 1, 0}, {1, 0, 0}});

	// Test Case 12: Sequential numbers 2x2
	runTestCase(12, {{1, 2}, {3, 4}}, {{3, 1}, {4, 2}});

	// Test Case 13: Large numbers
	runTestCase(13, {{1000, 999, 998}, {500, 501, 502}, {-1000, -999, -998}},
				{{-1000, 500, 1000}, {-999, 501, 999}, {-998, 502, 998}});

	// Test Case 14: 4x4 symmetric
	runTestCase(14, {{1, 2, 3, 4}, {2, 5, 6, 3}, {3, 6, 5, 2}, {4, 3, 2, 1}},
				{{4, 3, 2, 1}, {3, 6, 5, 2}, {2, 6, 5, 3}, {1, 2, 3, 4}});

	// Test Case 15: Boundary values
	runTestCase(15, {{-1000, 1000}, {1000, -1000}},
				{{1000, -1000}, {-1000, 1000}});

	return 0;
}