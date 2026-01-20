#include <bits/stdc++.h>
using namespace std;

// brute force
// vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
// 	set<int> st;
// 	vector<int> unionArray;

// 	for (int i = 0; i < nums1.size(); i++) {
// 		st.insert(nums1[i]);
// 	}

// 	for (int i = 0; i < nums2.size(); i++) {
// 		st.insert(nums2[i]);
// 	}

// 	for (auto it : st) {
// 		unionArray.push_back(it);
// 	}

// 	return unionArray;
// }

// // best using 2 pointers
// int increaseIndex(vector<int>& nums, int current, int index) {
// 	while (index < nums.size()) {
// 		if (nums[index] != current) {
// 			break;
// 		}
// 		index++;
// 	}
// 	return index;
// }
// vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
// 	vector<int> res;

// 	int i = 0;
// 	int j = 0;
// 	while (i < nums1.size() && j < nums2.size()) {
// 		if (nums1[i] == nums2[j]) {
// 			res.push_back(nums1[i]);
// 			i = increaseIndex(nums1, nums1[i], i + 1);
// 			j = increaseIndex(nums2, nums2[j], j + 1);
// 			continue;
// 		}
// 		if (nums1[i] < nums2[j]) {
// 			res.push_back(nums1[i]);
// 			i = increaseIndex(nums1, nums1[i], i + 1);
// 		}
// 		if (nums2[j] < nums1[i]) {
// 			res.push_back(nums2[j]);
// 			j = increaseIndex(nums2, nums2[j], j + 1);
// 		}
// 	}

// 	while (i < nums1.size()) {
// 		res.push_back(nums1[i]);
// 		i = increaseIndex(nums1, nums1[i], i);
// 	}

// 	while (j < nums2.size()) {
// 		res.push_back(nums2[j]);
// 		j = increaseIndex(nums2, nums2[j], j);
// 	}

// 	return res;
// }

// 2 pointers but slightly different approach
vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
	int size1 = nums1.size();
	int size2 = nums2.size();

	int i = 0;
	int j = 0;

	vector<int> unionOfArrays;

	while (i < size1 && j < size2) {
		if (nums1[i] <= nums2[j]) {
			if (unionOfArrays.size() == 0 || unionOfArrays.back() != nums1[i]) {
				unionOfArrays.push_back(nums1[i]);
			}
			i++;
		}

		if (nums2[j] < nums1[i]) {
			if (unionOfArrays.size() == 0 || unionOfArrays.back() != nums2[j]) {
				unionOfArrays.push_back(nums2[j]);
			}
			j++;
		}
	}

	while (i < size1) {
		if (nums1[i] != unionOfArrays.back()) {
			unionOfArrays.push_back(nums1[i]);
		}
		i++;
	}

	while (j < size2) {
		if (nums2[j] != unionOfArrays.back()) {
			unionOfArrays.push_back(nums2[j]);
		}
		j++;
	}

	return unionOfArrays;
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

void runTestCase(int testNum, vector<int> nums1, vector<int> nums2,
				 vector<int> expected) {
	cout << "\n=== Test Case " << testNum << " ===" << endl;

	printArray(nums1, "Array 1 ");
	printArray(nums2, "Array 2 ");
	printArray(expected, "Expected");

	vector<int> result = unionArray(nums1, nums2);
	printArray(result, "Result  ");

	bool passed = (result == expected);
	cout << "Status: " << (passed ? "PASSED ✓" : "FAILED ✗") << endl;
}

int main() {
	// Test Case 1: Basic union with some common elements
	runTestCase(1, {1, 2, 3, 4, 5}, {3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7});

	// Test Case 2: No common elements
	runTestCase(2, {1, 2, 3}, {4, 5, 6}, {1, 2, 3, 4, 5, 6});

	// Test Case 3: All common elements
	runTestCase(3, {1, 2, 3}, {1, 2, 3}, {1, 2, 3});

	// Test Case 4: One array is subset of another
	runTestCase(4, {1, 2, 3, 4, 5}, {2, 3}, {1, 2, 3, 4, 5});

	// Test Case 5: Arrays with duplicates
	runTestCase(5, {1, 1, 2, 2, 3}, {2, 3, 3, 4, 4}, {1, 2, 3, 4});

	// Test Case 9: Single element arrays
	runTestCase(9, {1}, {2}, {1, 2});

	// Test Case 10: Larger arrays with overlap
	runTestCase(10, {1, 3, 5, 7, 9}, {2, 3, 5, 8, 10},
				{1, 2, 3, 5, 7, 8, 9, 10});

	return 0;
}