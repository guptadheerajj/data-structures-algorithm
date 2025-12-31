#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
	int reversedNumber = 0;

	while (x != 0) {
		int lastDigit = x % 10;

		// upper limit checking for 32 bit integer
		if (reversedNumber > INT_MAX / 10 ||
			(reversedNumber == INT_MAX / 10 && lastDigit > 7)) {
			return 0;
		}

		// lower limit checking for 32 bit integer
		if (reversedNumber < INT_MIN / 10 ||
			(reversedNumber == INT_MIN / 10 && lastDigit < -8)) {
			return 0;
		}

		reversedNumber = reversedNumber * 10 + lastDigit;

		x /= 10;
	}
	return reversedNumber;
}

int main() {
	int x;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		cout << reverse(x) << endl;
	}
	return 0;
}