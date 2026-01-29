#include <bits/stdc++.h>
using namespace std;

// // brute force TC: O(k * (m+n)), SC: O(mn)
// void makeZero(vector<vector<int>>& matrix, int i, int j) {
// 	int rows = matrix.size();
// 	int columns = matrix[0].size();
// 	for (int index = 0; index < rows; index++) {
// 		matrix[index][j] = 0;
// 	}
// 	for (int index = 0; index < columns; index++) {
// 		matrix[i][index] = 0;
// 	}
// }

// void setZeroes(vector<vector<int>>& matrix) {
// 	int rows = matrix.size();
// 	int columns = matrix[0].size();
// 	// SC: O(k), worst case k = mn
// 	vector<pair<int, int>> zeroPosition;

// 	// TC: O(mn)
// 	for (int i = 0; i < rows; i++) {
// 		for (int j = 0; j < columns; j++) {
// 			if (matrix[i][j] == 0) {
// 				zeroPosition.push_back({i, j});
// 			}
// 		}
// 	}

// 	// TC: O(k * (m+n))
// 	for (int i = 0; i < zeroPosition.size(); i++) {
// 		pair<int, int> pairValue = zeroPosition[i];
// 		// TC: O(m+n)
// 		makeZero(matrix, pairValue.first, pairValue.second);
// 	}
// }

// Better
void setZeroes(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int columns = matrix[0].size();

	bool isFirstRowZero = false;
	bool isFirstColumnZero = false;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == 0) {
				if (i == 0) {
					isFirstRowZero = true;
				}
				if (j == 0) {
					isFirstColumnZero = true;
				}
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (int i = 1; i < rows; i++) {
		if (matrix[i][0] == 0) {
			for (int j = 1; j < columns; j++) {
				matrix[i][j] = 0;
			}
		}
	}

	for (int j = 1; j < columns; j++) {
		if (matrix[0][j] == 0) {
			for (int i = 1; i < rows; i++) {
				matrix[i][j] = 0;
			}
		}
	}

	if (isFirstRowZero) {
		for (int j = 0; j < columns; j++) {
			matrix[0][j] = 0;
		}
	}

	if (isFirstColumnZero) {
		for (int i = 0; i < rows; i++) {
			matrix[i][0] = 0;
		}
	}
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

	setZeroes(matrix);
	printMatrix(matrix, "Result");

	bool passed = matricesEqual(matrix, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem - center zero
	runTestCase(1, {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
				{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});

	// Test Case 2: Example 2 from problem - multiple zeros
	runTestCase(2, {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
				{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}});

	// Test Case 3: Single element - zero
	runTestCase(3, {{0}}, {{0}});

	// Test Case 4: Single element - non-zero
	runTestCase(4, {{1}}, {{1}});

	// Test Case 5: Single row with zero
	runTestCase(5, {{1, 0, 3}}, {{0, 0, 0}});

	// Test Case 6: Single row no zero
	runTestCase(6, {{1, 2, 3}}, {{1, 2, 3}});

	// Test Case 7: Single column with zero
	runTestCase(7, {{1}, {0}, {3}}, {{0}, {0}, {0}});

	// Test Case 8: Single column no zero
	runTestCase(8, {{1}, {2}, {3}}, {{1}, {2}, {3}});

	// Test Case 9: All zeros
	runTestCase(9, {{0, 0}, {0, 0}}, {{0, 0}, {0, 0}});

	// Test Case 10: No zeros
	runTestCase(10, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
				{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

	// Test Case 11: Zero in first row
	runTestCase(11, {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}},
				{{0, 0, 0}, {0, 4, 5}, {0, 7, 8}});

	// Test Case 12: Zero in first column
	runTestCase(12, {{1, 2, 3}, {0, 4, 5}, {6, 7, 8}},
				{{0, 2, 3}, {0, 0, 0}, {0, 7, 8}});

	// Test Case 13: Zero in corner (top-left)
	runTestCase(13, {{0, 1, 2}, {3, 4, 5}}, {{0, 0, 0}, {0, 4, 5}});

	// Test Case 14: Zero in corner (bottom-right)
	runTestCase(14, {{1, 2, 3}, {4, 5, 0}}, {{1, 2, 0}, {0, 0, 0}});

	// Test Case 15: Multiple zeros in same row
	runTestCase(15, {{1, 0, 3, 0}, {5, 6, 7, 8}}, {{0, 0, 0, 0}, {5, 0, 7, 0}});

	// Test Case 16: Multiple zeros in same column
	runTestCase(16, {{1, 2}, {0, 4}, {0, 6}}, {{0, 2}, {0, 0}, {0, 0}});

	// Test Case 17: Diagonal zeros
	runTestCase(17, {{0, 2, 3}, {4, 0, 6}, {7, 8, 0}},
				{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}});

	// Test Case 18: Large matrix with one zero
	runTestCase(18,
				{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 0, 12}, {13, 14, 15, 16}},
				{{1, 2, 0, 4}, {5, 6, 0, 8}, {0, 0, 0, 0}, {13, 14, 0, 16}});

	// Test Case 19: Negative numbers
	runTestCase(19, {{-1, -2, 0}, {-4, -5, -6}}, {{0, 0, 0}, {-4, -5, 0}});

	// Test Case 20: Mix of positive and negative with zero
	runTestCase(20, {{1, -1, 1}, {-1, 0, -1}, {1, -1, 1}},
				{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});

	return 0;
}