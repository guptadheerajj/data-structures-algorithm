#include <bits/stdc++.h>
using namespace std;

// brute TC: O(n * 32) SC: O(1)
int countMonobit(int n) {
	int count = 1;
	for (int i = 1; i <= n; i++) {
		bool isMonobit = true;
		string s = bitset<32>(i).to_string();
		s.erase(0, s.find('1'));

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '0') {
				isMonobit = false;
				break;
			}
		}

		if (isMonobit) {
			count++;
		}
	}

	return count;
}

////////////////
// Test Cases //
////////////////

void runTestCase(int testNum, int n, int expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	cout << "n       : " << n << endl;
	cout << "Expected: " << expected << endl;

	int result = countMonobit(n);
	cout << "Result  : " << result << endl;

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Example 1 from problem
	runTestCase(1, 1, 2);

	// Test Case 2: Example 2 from problem
	runTestCase(2, 4, 3);

	// Test Case 3: n = 0 (only 0)
	runTestCase(3, 0, 1);

	// Test Case 4: n = 2
	runTestCase(4, 2, 2);

	// Test Case 5: n = 3 (includes 0, 1, 3)
	runTestCase(5, 3, 3);

	// Test Case 6: n = 7 (includes 0, 1, 3, 7)
	runTestCase(6, 7, 4);

	// Test Case 7: n = 8
	runTestCase(7, 8, 4);

	// Test Case 8: n = 15 (includes 0, 1, 3, 7, 15)
	runTestCase(8, 15, 5);

	// Test Case 9: n = 16
	runTestCase(9, 16, 5);

	// Test Case 10: n = 31 (includes 0, 1, 3, 7, 15, 31)
	runTestCase(10, 31, 6);

	// Test Case 11: n = 63 (includes 0, 1, 3, 7, 15, 31, 63)
	runTestCase(11, 63, 7);

	// Test Case 12: n = 64
	runTestCase(12, 64, 7);

	// Test Case 13: n = 127 (includes 0, 1, 3, 7, 15, 31, 63, 127)
	runTestCase(13, 127, 8);

	// Test Case 14: n = 128
	runTestCase(14, 128, 8);

	// Test Case 15: n = 255 (includes 0, 1, 3, 7, 15, 31, 63, 127, 255)
	runTestCase(15, 255, 9);

	// Test Case 16: n = 511 (includes all up to 511)
	runTestCase(16, 511, 10);

	// Test Case 17: n = 512
	runTestCase(17, 512, 10);

	// Test Case 18: n = 1000 (maximum constraint)
	runTestCase(18, 1000, 10);

	// Test Case 19: Just before a Monobit number
	runTestCase(19, 30, 5);

	// Test Case 20: Just after a Monobit number
	runTestCase(20, 32, 6);

	return 0;
}