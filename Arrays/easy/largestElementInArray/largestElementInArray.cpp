#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& nums) {
	int maxElement = -1;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > maxElement) {
			maxElement = nums[i];
		}
	}
	return maxElement;
}

int main() {
	vector<int> nums = {5, 12, 3, 45, 93, 23, 8, 67, 34};

	int result = largestElement(nums);
	cout << "Largest element: " << result << endl;

	return 0;
}