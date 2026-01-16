#include <bits/stdc++.h>

using namespace std;

// brute force approach
int removeDuplicates(vector<int>& nums) {
	set<int> st;
	for (int i = 0; i < nums.size(); i++) {
		st.insert(nums[i]);
	}

	int index = 0;
	for (auto it : st) {
		nums[index] = it;
		index++;
	}

	return st.size();
}
// first approach -> 4ms
// int removeDuplicates(vector<int>& nums) {
// 	int shift = 0;
// 	int current = nums[0];
// 	int k = 1;
// 	for (int i = 1; i < nums.size(); i++) {
// 		if (current == nums[i]) {
// 			shift++;
// 			continue;
// 		}
// 		k++;
// 		current = nums[i];
// 		for (int j = shift, m = i - 1; j > 0; j--, m--) {
// 			nums[m] = nums[i];
// 		}
// 	}
// 	return k;
// }

// 0 ms
// int removeDuplicates(vector<int>& nums) {
// 	int shift = 0;
// 	int current = nums[0];
// 	int k = 1;
// 	for (int i = 1; i < nums.size(); i++) {
// 		if (current == nums[i]) {
// 			shift++;
// 			continue;
// 		}
// 		k++;
// 		current = nums[i];
// 		nums[i - shift] = nums[i];
// 	}
// 	return k;
// }

// best approach
// int removeDuplicates(vector<int>& nums) {
// 	int result = 1;
// 	int size = nums.size();

// 	for (int i = 1; i < size; i++) {
// 		if (nums[result - 1] != nums[i]) {
// 			nums[result] = nums[i];
// 			result++;
// 		}
// 	}

// 	return result;
// }

int main() {
	// Test case 1: Array with duplicates
	vector<int> nums1 = {1, 1, 2, 2, 2, 3, 4, 4, 5};
	cout << "Original array: ";
	for (int num : nums1) {
		cout << num << " ";
	}
	cout << endl;

	int k = removeDuplicates(nums1);
	cout << "Number of unique elements: " << k << endl;
	cout << "Modified array: ";
	for (int i = 0; i < k; i++) {
		cout << nums1[i] << " ";
	}
	cout << endl << endl;

	// Test case 2: Array with no duplicates
	vector<int> nums2 = {1, 2, 3, 4, 5};
	cout << "Original array: ";
	for (int num : nums2) {
		cout << num << " ";
	}
	cout << endl;

	k = removeDuplicates(nums2);
	cout << "Number of unique elements: " << k << endl;
	cout << "Modified array: ";
	for (int i = 0; i < k; i++) {
		cout << nums2[i] << " ";
	}
	cout << endl << endl;

	// Test case 3: Array with all same elements
	vector<int> nums3 = {2, 2, 2, 2, 2};
	cout << "Original array: ";
	for (int num : nums3) {
		cout << num << " ";
	}
	cout << endl;

	k = removeDuplicates(nums3);
	cout << "Number of unique elements: " << k << endl;
	cout << "Modified array: ";
	for (int i = 0; i < k; i++) {
		cout << nums3[i] << " ";
	}
	cout << endl;

	return 0;
}