#include <bits/stdc++.h>
using namespace std;

// by recursion
int fib(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	return fib(n - 1) + fib(n - 2);
}

int fib(int n) {
	if (n <= 1)
		return n;
	int a = 0;
	int fi = 1;
	for (int i = 2; i <= n; i++) {
		fi = a + fi;
		a = fi - a;
	}
	return fi;
}

int main() {
	cout << fib(4) << endl;

	return 0;
}