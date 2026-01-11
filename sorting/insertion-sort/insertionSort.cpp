#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
}

int main() {
	int arr[] = {3, 2, 5, 1, 4, 9, 7, 8, 0, 6, -1};

	int size = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, size);

	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;

	return 0;
}