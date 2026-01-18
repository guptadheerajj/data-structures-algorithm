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

// using temporary space of nums - k
// void rotate(vector<int>& nums, int k) {
// 	int size = nums.size();
// 	k = k % size;
// 	vector<int> temp;

// 	for (int i = 0; i < size - k; i++) {
// 		temp.push_back(nums[i]);
// 	}

// 	for (int i = size - k; i < size; i++) {
// 		nums[i - (size - k)] = nums[i];
// 	}

// 	for (int i = k; i < size; i++) {
// 		nums[i] = temp[i - k];
// 	}
// }

// best: space -> O(1), time -> O(2n) [(n-d) + (d) + (n)]
// void rotate(vector<int>& nums, int k) {
// 	k = k % nums.size();
// 	reverse(nums.begin(), nums.end() - k);
// 	reverse(nums.end() - k, nums.end());
// 	reverse(nums.begin(), nums.end());
// }

// by using custom reverse function
void myReverse(vector<int>& nums, int start, int end) {
	while (start <= end) {
		int temp = nums[start];
		nums[start] = nums[end];
		nums[end] = temp;
		start++;
		end--;
	}
}

void rotate(vector<int>& nums, int k) {
	int size = nums.size();
	k = k % size;
	myReverse(nums, 0, size - k - 1);
	myReverse(nums, size - k, size - 1);
	myReverse(nums, 0, size - 1);
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
	vector<int> nums2 = {-1, -100, 3, 99};
	cout << "Test case 2:" << endl;
	cout << "Original array: ";
	for (int num : nums2) {
		cout << num << " ";
	}
	cout << endl;

	k = 2;
	rotate(nums2, k);
	cout << "After rotating by " << k << ": ";
	for (int num : nums2) {
		cout << num << " ";
	}
	cout << endl << endl;

	// // Test case 3: k greater than array length
	vector<int> nums3 = {1, 2, 3};
	cout << "Test case 3:" << endl;
	cout << "Original array: ";
	for (int num : nums3) {
		cout << num << " ";
	}
	cout << endl;

	k = 5;
	rotate(nums3, k);
	cout << "After rotating by " << k << " (k > n): ";
	for (int num : nums3) {
		cout << num << " ";
	}
	cout << endl << endl;

	// // Test case 4: Single element
	vector<int> nums4 = {1};
	cout << "Test case 4:" << endl;
	cout << "Original array: ";
	for (int num : nums4) {
		cout << num << " ";
	}
	cout << endl;

	k = 1;
	rotate(nums4, k);
	cout << "After rotating by " << k << ": ";
	for (int num : nums4) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}