#include <bits/stdc++.h>

using namespace std;

void printAllDivisions(int x) {
	vector<int> divisors;
	for (int i = 1; i <= sqrt(x); i++) {
		if (x % i == 0) {
			divisors.push_back(i);
			if (i != (x / i)) {
				divisors.push_back(x / i);
			}
		}
	}
	sort(divisors.begin(), divisors.end());

	for (int it : divisors) {
		cout << it << " ";
	}
}

int main() {
	int x;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		printAllDivisions(x);
		cout << endl;
	}
	return 0;
}