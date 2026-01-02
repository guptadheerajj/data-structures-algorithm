#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int x;

	for (int i = 0; i < 5; i++) {
		cin >> x;
		cout << isPrime(x);
		cout << endl;
	}
	return 0;
}