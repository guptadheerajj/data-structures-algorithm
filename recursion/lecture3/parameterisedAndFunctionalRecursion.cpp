#include <bits/stdc++.h>

using namespace std;

// parameterised recursive function -> it does not returns a value
void printSumOfN(int i, int sum) {
	if (i < 1) {
		cout << sum << endl;
		return;
	}
	printSumOfN(i - 1, sum + i);
}

// functional recursive function -> it returns a value like sum
int getSum(int n) {
	if (n == 1) {
		return 1;
	}
	return n + getSum(n - 1);
}

int getFactorial(int n) {
	if (n == 1) {
		return 1;
	}

	return n * getFactorial(n - 1);
}

int main() {
	// printSumOfN(10, 0);
	// cout << getSum(5) << endl;
	cout << getFactorial(5) << endl;
	return 0;
}