#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size) {
	int tp = size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int arr[] = {45, 24, 23, 12, 2, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << "Before: ";
	for (auto it : arr) {
		cout << it << " ,";
	}
	cout << endl;

	bubbleSort(arr, size);

	cout << "After: ";
	for (auto it : arr) {
		cout << it << " ,";
	}
	cout << endl;

	return 0;
}