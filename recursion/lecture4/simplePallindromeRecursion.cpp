#include <bits/stdc++.h>
using namespace std;

// pallindrome using recursion
bool isPallindrome(int i, string& s) {
	if (i >= s.size() / 2) {
		return true;
	}

	// cout << "s[i]: " << s[i] << "s[s.size() - i - 1]" << s[s.size() - i - 1]
	// 	 << endl;

	if (s[i] != s[s.size() - i - 1]) {
		return false;
	}
	return isPallindrome(i + 1, s);
}

int main() {
	string s1 = "DheerajareehD";
	string s2 = "Dheerajj";

	cout << "S1: " << isPallindrome(0, s1) << endl;
	cout << "S2: " << isPallindrome(0, s2) << endl;

	return 0;
}