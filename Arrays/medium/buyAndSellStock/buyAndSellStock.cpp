#include <bits/stdc++.h>
using namespace std;

// Brute Force TC: O(n square) SC: O(1)
// int maxProfit(vector<int>& prices) {
// 	int size = prices.size();
// 	int maxProf = 0;

// 	for (int i = 0; i < size - 1; i++) {
// 		for (int j = i + 1; j < size; j++) {
// 			int prof = prices[j] - prices[i];
// 			if (prof > maxProf) {
// 				maxProf = prof;
// 			}
// 		}
// 	}

// 	return maxProf;
// }

// Using similar to kedane's algo
int maxProfit(vector<int>& prices) {
	int size = prices.size();
	int maxProf = 0;
	int buy = prices[0];
	int sell;

	for (int i = 1; i < size; i++) {
		sell = prices[i];
		int profit = sell - buy;

		if (profit > maxProf) {
			maxProf = profit;
		}

		if (sell < buy) {
			buy = sell;
		}
	}

	return maxProf;
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

void runTestCase(int testNum, vector<int> prices, int expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(prices, "prices  ");
	cout << "Expected: " << expected << endl;

	int result = maxProfit(prices);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, {7, 1, 5, 3, 6, 4}, 5);

	// Test Case 2: Example 2 from problem - decreasing prices
	runTestCase(2, {7, 6, 4, 3, 1}, 0);

	// Test Case 3: Single price
	runTestCase(3, {5}, 0);

	// Test Case 4: Two prices - profit possible
	runTestCase(4, {3, 7}, 4);

	// Test Case 5: Two prices - no profit
	runTestCase(5, {7, 3}, 0);

	// Test Case 6: All same prices
	runTestCase(6, {5, 5, 5, 5}, 0);

	// Test Case 7: Increasing prices
	runTestCase(7, {1, 2, 3, 4, 5}, 4);

	// Test Case 8: Buy at minimum, sell at maximum
	runTestCase(8, {5, 1, 5, 6, 7, 1, 10}, 9);
	// runTestCase(8, {5, 2, 5, 6, 7, 1, 2}, 9);

	// Test Case 9: Maximum profit at end
	runTestCase(9, {3, 2, 1, 4}, 3);

	// Test Case 10: Maximum profit in middle
	runTestCase(10, {2, 8, 1, 5, 4}, 6);

	// Test Case 11: Multiple small gains
	runTestCase(11, {1, 2, 4, 2, 5, 7, 2, 4}, 6);

	// Test Case 12: Price drops after peak
	runTestCase(12, {3, 3, 5, 0, 0, 3, 1, 4}, 4);

	// Test Case 13: Zero prices
	runTestCase(13, {0, 0, 0}, 0);

	// Test Case 14: Starting from zero
	runTestCase(14, {0, 6, 3, 8}, 8);

	// Test Case 15: Large gap in middle
	runTestCase(15, {2, 1, 2, 1, 0, 1, 2}, 2);

	// Test Case 16: Best profit at beginning
	runTestCase(16, {1, 5, 2, 3, 1}, 4);

	// Test Case 17: V-shaped prices
	runTestCase(17, {10, 5, 1, 5, 10}, 9);

	// Test Case 18: Plateau before profit
	runTestCase(18, {2, 2, 2, 5}, 3);

	// Test Case 19: Multiple peaks
	runTestCase(19, {1, 4, 2, 7, 1, 5}, 6);

	// Test Case 20: Large numbers
	runTestCase(20, {10000, 1, 5000, 2, 10000}, 9999);

	// Test Case 20: Large numbers
	runTestCase(21, {9, 2, 1, 9, 0, 6, 7}, 8);

	return 0;
}