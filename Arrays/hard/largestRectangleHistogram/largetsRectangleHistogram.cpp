#include <bits/stdc++.h>
using namespace std;

// Brute force, Time Limit Exceeded
int largestRectangleArea(vector<int>& heights) {
	int size = heights.size();
	int largestArea = 0;

	for (int i = 0; i < size; i++) {
		int ht = heights[i];
		int base = 0;
		int area = 0;

		for (int j = i; j >= 0; j--) {
			if (heights[j] < ht) {
				break;
			}
			base++;
		}

		for (int k = i + 1; k < size; k++) {
			if (heights[k] < ht) {
				break;
			}
			base++;
		}

		largestArea = max(largestArea, (base * ht));
	}

	return largestArea;
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

void runTestCase(int testNum, vector<int> heights, int expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(heights, "heights ");
	cout << "Expected: " << expected << endl;

	int result = largestRectangleArea(heights);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {2, 1, 5, 6, 2, 3}, 10);

	// Test Case 2: Example 2 from problem
	runTestCase(2, {2, 4}, 4);

	// Test Case 3: Single bar
	runTestCase(3, {5}, 5);

	// Test Case 4: All same height
	runTestCase(4, {3, 3, 3, 3}, 12);

	// Test Case 5: Increasing heights
	runTestCase(5, {1, 2, 3, 4, 5}, 9);

	// Test Case 6: Decreasing heights
	runTestCase(6, {5, 4, 3, 2, 1}, 9);

	// Test Case 7: All zeros
	runTestCase(7, {0, 0, 0}, 0);

	// Test Case 8: With zeros in middle
	runTestCase(8, {2, 0, 2}, 2);

	// Test Case 9: Single zero
	runTestCase(9, {0}, 0);

	// Test Case 10: Peak in middle
	runTestCase(10, {1, 2, 3, 2, 1}, 6);

	// Test Case 11: Valley pattern
	runTestCase(11, {3, 1, 3}, 3);

	// Test Case 12: Two bars same height
	runTestCase(12, {5, 5}, 10);

	// Test Case 13: Large gap
	runTestCase(13, {1, 100, 1}, 100);

	// Test Case 14: Multiple peaks
	runTestCase(14, {4, 2, 0, 3, 2, 5}, 6);

	// Test Case 15: Plateau pattern
	runTestCase(15, {1, 5, 5, 5, 1}, 15);

	// Test Case 16: Zigzag pattern
	runTestCase(16, {1, 3, 2, 4, 2}, 6);

	// Test Case 17: Rectangle at beginning
	runTestCase(17, {6, 6, 6, 1, 1, 1}, 18);

	// Test Case 18: Rectangle at end
	runTestCase(18, {1, 1, 1, 6, 6, 6}, 18);

	// Test Case 19: Large numbers
	runTestCase(19, {10000, 10000}, 20000);

	// Test Case 20: Complex pattern
	runTestCase(20, {2, 1, 2, 3, 1}, 5);

	// Test Case 21: Staircase up
	runTestCase(21, {1, 2, 3, 4, 5, 6}, 12);

	// Test Case 22: Staircase down
	runTestCase(22, {6, 5, 4, 3, 2, 1}, 12);

	// Test Case 23: Alternating heights
	runTestCase(23, {2, 1, 2, 1, 2}, 5);

	// Test Case 24: Long flat histogram
	runTestCase(24, {7, 7, 7, 7, 7, 7, 7}, 49);

	// Test Case 25: Edge case with single tall bar
	runTestCase(25, {1, 10, 1}, 10);

	return 0;
}