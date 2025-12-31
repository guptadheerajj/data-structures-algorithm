#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0) {
		return false;
	}
	int num = x;

	int reversedNumber = 0;

	while (x != 0) {
		reversedNumber = reversedNumber * 10 + (x % 10);
		x /= 10;
	}
	return reversedNumber == num;
}

int main() {
	int x;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		cout << isPalindrome(x) << endl;
	}
	return 0;
}