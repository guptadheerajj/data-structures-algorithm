#include <bits/stdc++.h>
using namespace std;

int main() {
	int size;
	cin >> size;

	int arr[size];

	// input array
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
		// mpp[arr[i]] += 1;
	}

	int numberOfQueries;
	cin >> numberOfQueries;

	// hash using map
	map<int, int> mpp;
	for (int i = 0; i < size; i++) {
		mpp[arr[i]] += 1;
	}

	int queries;

	while (numberOfQueries--) {
		cin >> queries;
		cout << mpp[queries] << endl;
	}

	return 0;
}