#include <bits/stdc++.h>
using namespace std;

// TC: O(n*n) SC: O(n * n)
vector<int> getRow(int rowIndex) {
	vector<vector<int>> triangle;

	for (int i = 0; i <= rowIndex; i++) {
		vector<int> currentRow;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				currentRow.push_back(1);
			} else {
				int ele = triangle[i - 1][j - 1] + triangle[i - 1][j];
				currentRow.push_back(ele);
			}
		}
		triangle.push_back(currentRow);
	}

	return triangle[rowIndex];
}

// TC: O(n * n)  SC: O(2n)
vector<int> getRow(int rowIndex) {
	vector<int> previousRow;

	for (int i = 0; i <= rowIndex; i++) {
		vector<int> currentRow;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				currentRow.push_back(1);
			} else {
				int ele = previousRow[j - 1] + previousRow[j];
				currentRow.push_back(ele);
			}
		}
		previousRow = currentRow;
	}

	return previousRow;
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

void runTestCase(int testNum, int rowIndex, vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	cout << "rowIndex: " << rowIndex << endl;
	printArray(expected, "Expected");

	vector<int> result = getRow(rowIndex);
	printArray(result, "Result  ");

	bool passed = arraysEqual(result, expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, 3, {1, 3, 3, 1});

	// Test Case 2: Example 2 from problem
	runTestCase(2, 0, {1});

	// Test Case 3: Example 3 from problem
	runTestCase(3, 1, {1, 1});

	// Test Case 4: Row 2
	runTestCase(4, 2, {1, 2, 1});

	// Test Case 5: Row 4
	runTestCase(5, 4, {1, 4, 6, 4, 1});

	// Test Case 6: Row 5
	runTestCase(6, 5, {1, 5, 10, 10, 5, 1});

	// Test Case 7: Row 6
	runTestCase(7, 6, {1, 6, 15, 20, 15, 6, 1});

	// Test Case 8: Row 7
	runTestCase(8, 7, {1, 7, 21, 35, 35, 21, 7, 1});

	// Test Case 9: Row 8
	runTestCase(9, 8, {1, 8, 28, 56, 70, 56, 28, 8, 1});

	// Test Case 10: Row 9
	runTestCase(10, 9, {1, 9, 36, 84, 126, 126, 84, 36, 9, 1});

	// Test Case 11: Row 10
	runTestCase(11, 10, {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1});

	// Test Case 12: Row 11
	runTestCase(12, 11, {1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1});

	// Test Case 13: Row 12
	runTestCase(13, 12,
				{1, 12, 66, 220, 495, 792, 924, 792, 495, 220, 66, 12, 1});

	// Test Case 14: Row 13
	runTestCase(
		14, 13,
		{1, 13, 78, 286, 715, 1287, 1716, 1716, 1287, 715, 286, 78, 13, 1});

	// Test Case 15: Row 14
	runTestCase(15, 14,
				{1, 14, 91, 364, 1001, 2002, 3003, 3432, 3003, 2002, 1001, 364,
				 91, 14, 1});

	// Test Case 16: Row 15
	runTestCase(16, 15,
				{1, 15, 105, 455, 1365, 3003, 5005, 6435, 6435, 5005, 3003,
				 1365, 455, 105, 15, 1});

	// Test Case 17: Row 20
	runTestCase(17, 20, {1,		20,		190,	1140,	4845,	15504,	38760,
						 77520, 125970, 167960, 184756, 167960, 125970, 77520,
						 38760, 15504,	4845,	1140,	190,	20,		1});

	// Test Case 18: Row 25
	runTestCase(18, 25,
				{1,		  25,	   300,		2300,	 12650,	  53130,   177100,
				 480700,  1081575, 2042975, 3268760, 4457400, 5200300, 5200300,
				 4457400, 3268760, 2042975, 1081575, 480700,  177100,  53130,
				 12650,	  2300,	   300,		25,		 1});

	// Test Case 19: Row 30
	runTestCase(19, 30, {1,			30,		   435,		  4060,		 27405,
						 142506,	593775,	   2035800,	  5852925,	 14307150,
						 30045015,	54627300,  86493225,  119759850, 145422675,
						 155117520, 145422675, 119759850, 86493225,	 54627300,
						 30045015,	14307150,  5852925,	  2035800,	 593775,
						 142506,	27405,	   4060,	  435,		 30,
						 1});

	// Test Case 20: Row 33 (maximum constraint)
	runTestCase(
		20, 33,
		{1,			 33,		528,	   5456,	   40920,	   237336,
		 1107568,	 4272048,	13884156,  38567100,   92561040,   193536720,
		 354817320,	 573166440, 818809200, 1037158320, 1166803110, 1166803110,
		 1037158320, 818809200, 573166440, 354817320,  193536720,  92561040,
		 38567100,	 13884156,	4272048,   1107568,	   237336,	   40920,
		 5456,		 528,		33,		   1});

	return 0;
}