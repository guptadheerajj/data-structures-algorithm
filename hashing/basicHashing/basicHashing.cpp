#include <bits/stdc++.h>
using namespace std;

int main() {
	int size;
	cin >> size;

	string s(size, '\0');

	for (int i = 0; i < size; i++) {
		cin >> s[i];
	}

	int hash[26] = {0};

	// prepare hash
	for (int i = 0; i < size; i++) {
		hash[s[i] - 'a'] += 1;
	}

	// print hash
	// for (auto it : hash) {
	// 	cout << it << " ";
	// }

	int totalNumbers;
	cin >> totalNumbers;

	// get frequency
	char ch;
	while (totalNumbers--) {
		cin >> ch;
		cout << hash[ch - 'a'] << endl;
	}

	return 0;
}