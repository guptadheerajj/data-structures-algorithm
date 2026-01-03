#include <bits/stdc++.h>

using namespace std;

// using recursion
void reverseArray(int* arr, int size, int i) {
	if (i == size) {
		return;
	}
	int temp = arr[i];
	reverseArray(arr, size, i + 1);
	arr[size - i - 1] = temp;
}

// inplace and using single variable
void reverse(int arr[], int n) {
	if (n < 2) {
		return;
	}
	int temp = *arr;
	*arr = *(arr + n - 1);
	*(arr + n - 1) = temp;
	reverse(arr + 1, n - 2);
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6};

	int size = sizeof(arr) / sizeof(arr[1]);

	// reverseArray(arr, size, 0);
	reverse(arr, size);

	for (int it : arr) {
		cout << it << endl;
	}

	return 0;
}