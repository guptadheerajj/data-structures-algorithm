#include <bits/stdc++.h>
using namespace std;

// brute force -> time limit exceed
// void rotate(vector<int>& nums, int k) {
// 	int size = nums.size();
// 	k = k % size;
// 	for (int i = 0; i < k; i++) {
// 		int last = nums[size - 1];
// 		for (int j = size - 1; j > 0; j--) {
// 			nums[j] = nums[j - 1];
// 		}
// 		nums[0] = last;
// 	}
// }

// brute force by using extra space -> space complexity is O(n)
// void rotate(vector<int>& nums, int k) {
// 	vector<int> rotateNums;
// 	int size = nums.size();
// 	k = k % size;
// 	int last = size - k;

// 	for (int last = size - k; last < size; last++) {
// 		rotateNums.push_back(nums[last]);
// 	}

// 	for (int i = 0; i < size - k; i++) {
// 		rotateNums.push_back(nums[i]);
// 	}

// 	for (int i = 0; i < size; i++) {
// 		nums[i] = rotateNums[i];
// 	}
// }

void rotate(vector<int>& nums, int k) {
	int size = nums.size();
	k = k % size;
	int dividingIndex = size - k;

	for (int i = 0; i < dividingIndex / 2; i++) {
		int temp = nums[i];
		nums[i] = nums[dividingIndex - 1 - i];
		nums[dividingIndex - 1 - i] = temp;
	}

	for (int i = dividingIndex, j = size - 1; i < dividingIndex - k / 2; i++) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		j--;
	}

	for (int i = 0; i < size / 2; i++) {
		int temp = nums[i];
		nums[i] = nums[size - 1 - i];
		nums[size - 1 - i] = temp;
	}

	// int size = nums.size();
	// int low = 0;
	// k = k % size;
	// if (k == 0) {
	// 	return;
	// }
	// int high = size - k;

	// while (low < size - 1) {
	// 	int temp = nums[low];
	// 	nums[low] = nums[high];
	// 	nums[high] = temp;

	// 	high++;
	// 	if (high >= size) {
	// 		high = size - k;
	// 	}
	// 	low++;
	// }
}

int main() {
	// Test case 1: Rotate by 3
	vector<int> nums1 = {1, 2, 3, 4, 5, 6};
	cout << "Test case 1:" << endl;
	cout << "Original array: ";
	for (int num : nums1) {
		cout << num << " ";
	}
	cout << endl;

	int k = 4;
	rotate(nums1, k);
	cout << "After rotating by " << k << ": ";
	for (int num : nums1) {
		cout << num << " ";
	}
	cout << endl << endl;
	nums1 = {1, 2, 3, 4, 5, 6, 7};
	cout << "Test case 1:" << endl;
	cout << "Original array: ";
	for (int num : nums1) {
		cout << num << " ";
	}
	cout << endl;

	k = 3;
	rotate(nums1, k);
	cout << "After rotating by " << k << ": ";
	for (int num : nums1) {
		cout << num << " ";
	}
	cout << endl << endl;

	// Test case 2: Rotate by 2
	// vector<int> nums2 = {-1, -100, 3, 99};
	// cout << "Test case 2:" << endl;
	// cout << "Original array: ";
	// for (int num : nums2) {
	// 	cout << num << " ";
	// }
	// cout << endl;

	// k = 2;
	// rotate(nums2, k);
	// cout << "After rotating by " << k << ": ";
	// for (int num : nums2) {
	// 	cout << num << " ";
	// }
	// cout << endl << endl;

	// // Test case 3: k greater than array length
	// vector<int> nums3 = {1, 2, 3};
	// cout << "Test case 3:" << endl;
	// cout << "Original array: ";
	// for (int num : nums3) {
	// 	cout << num << " ";
	// }
	// cout << endl;

	// k = 5;
	// rotate(nums3, k);
	// cout << "After rotating by " << k << " (k > n): ";
	// for (int num : nums3) {
	// 	cout << num << " ";
	// }
	// cout << endl << endl;

	// // Test case 4: Single element
	// vector<int> nums4 = {1};
	// cout << "Test case 4:" << endl;
	// cout << "Original array: ";
	// for (int num : nums4) {
	// 	cout << num << " ";
	// }
	// cout << endl;

	// k = 1;
	// rotate(nums4, k);
	// cout << "After rotating by " << k << ": ";
	// for (int num : nums4) {
	// 	cout << num << " ";
	// }
	// cout << endl;

	return 0;
}