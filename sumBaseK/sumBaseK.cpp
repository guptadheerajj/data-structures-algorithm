#include <bits/stdc++.h>
using namespace std;

int sumBase(int n, int k) {
	int tempNum = n;
	int baseKNumber = 0;
	while (tempNum != 0) {
		int remainder = tempNum % k;
		baseKNumber = baseKNumber * 10 + remainder;
		tempNum = tempNum / k;
	}

	int sum = 0;
	while (baseKNumber != 0) {
		sum += baseKNumber % 10;
		baseKNumber /= 10;
	}

	return sum;
}

int main() {
	cout << sumBase(48, 7);
	return 0;
}