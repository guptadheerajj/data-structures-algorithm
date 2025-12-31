#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second < p2.second) {
		return true;
	}
	if (p1.second > p2.second) {
		return false;
	}
	if (p1.first > p2.first) {
		return true;
	}
	return false;
}

int main() {
	pair<int, int> arr[] = {{1, 2}, {2, 1}, {4, 1}};

	for (auto it : arr) {
		cout << it.first << ", " << it.second << endl;
	}

	int arrSize = sizeof(arr) / sizeof(arr[1]);

	sort(arr, arr + arrSize, comp);

	cout << "After sort" << endl;
	for (auto it : arr) {
		cout << it.first << ", " << it.second << endl;
	}

	return 0;
}