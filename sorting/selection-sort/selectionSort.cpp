#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minimumIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minimumIndex]) {
				minimumIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minimumIndex];
		arr[minimumIndex] = temp;
	}
}

int main() {
	int arr[] = {3, 2, 5, 1, 4, 9, 7, 8, 0, 6};

	int size = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, size);

	for (auto it : arr) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}