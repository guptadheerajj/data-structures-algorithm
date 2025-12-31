#include <bits/stdc++.h>

using namespace std;

bool isArmstrong(int x) {
	int temporary = x;
	int numberOfDigits = 0;
	int sum = 0;

	while (temporary != 0) {
		temporary /= 10;
		numberOfDigits++;
	}

	temporary = x;
	while (temporary != 0) {
		sum += pow((temporary % 10), numberOfDigits);
		temporary /= 10;
	}

	return sum == x;
}

int main() {
	int x;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		cout << isArmstrong(x) << endl;
	}
	return 0;
}