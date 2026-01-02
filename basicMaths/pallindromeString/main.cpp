#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
	s.erase(remove_if(s.begin(), s.end(),
					  [](unsigned char c) { return !isalnum(c); }),
			s.end());

	transform(s.begin(), s.end(), s.begin(),
			  [](unsigned char c) { return tolower(c); });

	string reversed;
	transform(s.rbegin(), s.rend(), back_inserter(reversed),
			  [](unsigned char c) { return c; });

	return s == reversed;
}

bool isPalindrome(string s) {
	string filtered;
	for (char c : s) {
		if (isalnum(c)) {
			filtered += tolower(c);
		}
	}

	auto left = filtered.begin();
	auto right = filtered.rbegin();
	for (; left != filtered.end() && right != filtered.rend();
		 left++, right++) {
		if (*left != *right) {
			return false;
		}
	}
	return true;
}

bool isPalindrome(string s) {
	string filtered;
	for (char c : s) {
		if (isalnum(c)) {
			filtered += tolower(c);
		}
	}
	int len = filtered.size();
	for (int start = 0; start < len / 2; start++) {
		if (filtered[start] != filtered[len - 1 - start]) {
			return false;
		}
	}

	return true;
}

int main() {
	string x;

	for (int i = 0; i < 3; i++) {
		cin >> x;
		cout << isPalindrome(x) << endl;
	}
	return 0;
}