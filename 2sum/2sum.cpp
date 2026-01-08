#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> solution;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (target == (nums[i] + nums[j])) {
				solution.push_back(i);
				solution.push_back(j);
				break;
			}
		}
	}
	return solution;
}

int main() {
	return 0;
}