#include <bits/stdc++.h>
using namespace std;

int secondLargestNumber(vector<int>& nums) {
	int max = nums[0];
	int secondMax = -1;

	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > max) {
			secondMax = max;
			max = nums[i];
		}
		if (nums[i] < max && nums[i] > secondMax) {
			secondMax = nums[i];
		}
	}

	return secondMax;
}

int main() {
	vector<int> nums = {5, 12, 3, 45, 93, 23, 8, 67, 34, 94};

	int result = secondLargestNumber(nums);
	cout << "Second Largest element: " << result << endl;

	return 0;
}