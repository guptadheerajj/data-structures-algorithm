#include <bits/stdc++.h>
using namespace std;

// take pivot as the first element in the array
// now tak lows and highs
// find the low elment that is greater than pivot and high element that is
// smaller than pivot swap them if high < low then that means thats the index
// where the pivot belongs
// swap high with the pivot i.e. first element
int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[low];

	int left = low;
	int right = high;

	while (right >= left) {
		while (pivot >= arr[left] && left <= high - 1) {
			left++;
		}
		while (pivot < arr[right] && right >= low - 1) {
			right--;
		}
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}

	arr[low] = arr[right];
	arr[right] = pivot;

	return right;
}

void quickSort(vector<int>& arr, int low, int high) {
	if (low >= high) {
		return;
	}
	int pivotIndex = partition(arr, low, high);
	quickSort(arr, low, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, high);
}

int main() {
	vector<int> arr = {10, 7, 8, 9, 1, 5, -1, 3};

	quickSort(arr, 0, arr.size() - 1);

	for (int num : arr) {
		cout << num << " ";
	}

	cout << endl;
	return 0;
}