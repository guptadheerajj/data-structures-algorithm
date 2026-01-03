#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void printName5Times(string s) {
	if (counter == 5) {
		return;
	}
	cout << s << endl;
	counter++;
	printName5Times(s);
}

void printNameNTimes(int n) {
	if (n == 0) {
		return;
	}
	cout << "Dheeraj" << endl;

	printNameNTimes(--n);
}

void print1ToN(int i, int n) {
	if (i > n) {
		return;
	}
	cout << i++ << endl;
	;
	print1ToN(i, n);
}

// print 1 to N but we cannnot use ++ like fn(n+1, i)
// using back tracking
void print1ToN(int n) {
	if (n < 1) {
		return;
	}
	print1ToN(n - 1);
	cout << n << endl;
	return;
}

// by using backtracking orint N to 1 without using i-1
void printNTo1(int i, int n) {
	if (i > 5) {
		return;
	}
	printNTo1(i + 1, n);
	cout << i << endl;
}

int main() {
	// printName5Times("Dheeraj");
	// printNameNTimes(5);
	// print1ToN(1, 10);
	// print1ToN(10);s
	printNTo1(1, 5);
	return 0;
}