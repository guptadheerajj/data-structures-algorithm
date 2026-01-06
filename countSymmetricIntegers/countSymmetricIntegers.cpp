#include <bits/stdc++.h>
using namespace std;

// for (auto it : digitArray) {
// 	cout << it << " ";
// }
// cout << endl;

// brute force approach
// 1. to find the digits in the number
// 2. check whether the number of digits is even or odd
// 3. if odd we will discard
// 4. if even, then add the first half and second half
// 5. then compare both the half, if equal increase numberOfSymmetric count
// by 1
int countSymmetricIntegers(int low, int high) {
	int numberOfSymmetric = 0;

	for (int i = low; i <= high; i++) {
		vector<int> digitArray;
		int current = i;

		while (current > 0) {
			digitArray.push_back(current % 10);
			current = current / 10;
		}

		if (digitArray.size() % 2 != 0) {
			continue;
		}

		int firstHalf = 0;
		int secondHalf = digitArray.size() / 2;
		int sumOfFirstHalf = 0;
		int sumOfSecondHalf = 0;

		while (firstHalf < (digitArray.size() / 2) &&
			   secondHalf < digitArray.size()) {
			sumOfFirstHalf += digitArray[firstHalf];
			sumOfSecondHalf += digitArray[secondHalf];

			firstHalf++;
			secondHalf++;
		}

		if (sumOfFirstHalf == sumOfSecondHalf) {
			numberOfSymmetric++;
		}
	}

	return numberOfSymmetric;
}

int main() {
	cout << countSymmetricIntegers(1, 100) << endl;

	return 0;
}