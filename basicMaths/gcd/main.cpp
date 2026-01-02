#include <bits/stdc++.h>

using namespace std;

int getGCD(int a, int b) {
	while (a > 0 && b > 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}
	return a > b ? a : b;
}

int main() {
	int a, b;

	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		cout << getGCD(a, b) << endl;
	}

	return 0;
}
