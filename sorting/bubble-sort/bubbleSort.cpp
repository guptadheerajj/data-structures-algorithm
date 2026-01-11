#include <bits/stdc++.h>
using namespace std;

// best case is O(n)
// for i = 0; it will compare all the adjacent elements, if the swapping does
// not occurs then it emans that array is in ascending order/sorted
void bubbleSort(int arr[], int size) {
	int tp = size;
	for (int i = 0; i < size; i++) {
		int didSwap = 0;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				didSwap = 1;
			}
		}

		if (didSwap == 0) {
			break;
		}
		cout << "Runs\n";
	}
}

int main() {
	// int arr[] = {45, 24, 23, 12, 2, 1};
	int arr[] = {1, 2, 3, 4, 6, 5};
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