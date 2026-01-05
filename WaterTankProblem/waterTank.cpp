// 1, 8, 6, 2, 5, 4, 8, 3, 7
// 49 is output
#include <bits/stdc++.h>
using namespace std;

// brute force
int maxArea(vector<int>& height) {
	int maximumArea = 0;
	int area = 0;

	for (int i = 0; i < height.size(); i++) {
		for (int j = i + 1; j < height.size(); j++) {
			if (height[i] < height[j]) {
				area = height[i] * (j - i);
			} else {
				area = height[j] * (j - i);
			}
			if (area > maximumArea) {
				maximumArea = area;
			}
		}
	}

	return maximumArea;
}

// using left and right iterators
int maxArea(vector<int>& height) {
	int finalArea = 0;
	int left = 0;
	int right = height.size() - 1;

	while (left < right) {
		int smallHeight = min(height[left], height[right]);
		int base = right - left;

		int area = smallHeight * base;

		if (area > finalArea) {
			finalArea = area;
		}

		if (height[left] < height[right]) {
			left++;
		} else {
			right--;
		}
	}

	return finalArea;
}

int main() {
	vector<int> height = {1, 1};
	cout << maxArea(height) << endl;

	return 0;
}
