#include <bits/stdc++.h>
using namespace std;

// find first occurance of needle in heystack
int strStr(string haystack, string needle) {
	int index = 0;
	for (int i = 0, j = 0; i < haystack.size() && j < needle.size(); i++) {
		if (haystack[i] == needle[j]) {
			j++;
		} else {
			j = 0;
			index = i + 1;
		}
	}

	if ((index + needle.size() - 1) >= haystack.size()) {
		index = -1;
	}

	return index;
}

int strStr(string haystack, string needle) {
	int index = -1;
	for (int i = 0; i < haystack.size(); i++) {
		if (needle == haystack.substr(i, needle.size())) {
			index = i;
			break;
		}
	}
	return index;
}

int main() {
	// string haystack1 = "sadbutsad";
	// string needle1 = "sad";
	// string haystack1 = "leetcode";
	// string needle1 = "leeto";
	string haystack1 = "mississippi";
	string needle1 = "issip";
	cout << strStr(haystack1, needle1) << endl;
	return 0;
}