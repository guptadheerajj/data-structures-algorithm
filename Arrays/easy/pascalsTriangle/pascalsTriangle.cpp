#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ans;

	for (int i = 0; i < numRows; i++) {
		vector<int> currentRow;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				currentRow.push_back(1);
			} else {
				int ele = ans[i - 1][j - 1] + ans[i - 1][j];
				currentRow.push_back(ele);
			}
		}
		ans.push_back(currentRow);
	}

	return ans;
}

int main() {
	return 0;
}