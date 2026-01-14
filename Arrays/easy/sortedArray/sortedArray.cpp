#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
	int size = nums.size();
	int count = 0;
	if (nums[0] < nums[size - 1]) {
		count++;
	}
	for (int i = 1; i < size; i++) {
		if (nums[i] < nums[i - 1]) {
			count++;
		}
		if (count >= 2) {
			return false;
		}
	}
	return true;
}

int main() {
	// Test case 1: Sorted array
	vector<int> test1 = {1, 2, 3, 4, 5};
	cout << "Test 1: [1, 2, 3, 4, 5] -> " << (check(test1) ? "true" : "false")
		 << endl;

	// Test case 2: Rotated sorted array
	vector<int> test2 = {3, 4, 5, 1, 2};
	cout << "Test 2: [3, 4, 5, 1, 2] -> " << (check(test2) ? "true" : "false")
		 << endl;

	// Test case 3: Not sorted
	vector<int> test3 = {2, 1, 3, 4};
	cout << "Test 3: [2, 1, 3, 4] -> " << (check(test3) ? "true" : "false")
		 << endl;

	// Test case 4: All same elements
	vector<int> test4 = {1, 1, 1};
	cout << "Test 4: [1, 1, 1] -> " << (check(test4) ? "true" : "false")
		 << endl;

	// Test case 5: Single element
	vector<int> test5 = {1};
	cout << "Test 5: [1] -> " << (check(test5) ? "true" : "false") << endl;

	// Test case 6: Rotated with duplicates
	vector<int> test6 = {3, 4, 5, 1, 2};
	cout << "Test 6: [3, 4, 5, 1, 2] -> " << (check(test6) ? "true" : "false")
		 << endl;

	// Test case 7: Unsorted array
	vector<int> test7 = {1, 3, 2, 4, 5};
	cout << "Test 7: [1, 3, 2, 4, 5] -> " << (check(test7) ? "true" : "false")
		 << endl;

	return 0;
}