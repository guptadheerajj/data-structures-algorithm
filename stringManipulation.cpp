#include <bits/stdc++.h>
using namespace std;

int main() {
	// // length of string
	// string s;
	// cin >> s;
	// int length = s.size();
	// cout << length << endl;

	// // join the strings
	// string s1;
	// string s2;

	// cin >> s1;
	// cin >> s2;

	// string result = s1 + s2;
	// cout << result << endl;

	// // compare strings
	// string s1;
	// string s2;

	// cin >> s1;
	// cin >> s2;

	// if (s1 == s2) {
	// 	cout << "Strings are same";
	// } else {
	// 	cout << "Strings are not same";
	// }

	// // first character of string
	// string s;
	// cin >> s;

	// cout << s.at(0) << endl;

	// // last character of string
	// string s;
	// cin >> s;

	// cout << s.at(s.size() - 1) << endl;

	// // alphanumeric check
	// string s;
	// cin >> s;
	// bool isAlphaNum = true;

	// for (auto ch : s) {
	// 	if (!isalnum((unsigned char)ch)) {
	// 		isAlphaNum = false;
	// 		break;
	// 	}
	// }

	// cout << (bool)isAlphaNum << endl;

	// // uppercase check
	// string s;
	// cin >> s;
	// bool isUpper = true;
	// for (auto ch : s) {
	// 	if (!isupper((unsigned char)ch)) {
	// 		isUpper = false;
	// 		break;
	// 	}
	// }

	// cout << isUpper << endl;

	// // lower check
	// string s;
	// cin >> s;
	// bool isLower = true;

	// for (auto ch : s) {
	// 	if (!islower((unsigned char)ch)) {
	// 		isLower = false;
	// 		break;
	// 	}
	// }

	// cout << isLower << endl;

	// // reverse a string
	// string s;
	// cin >> s;
	// string res;
	// for (int i = s.size() - 1; i >= 0; i--) {
	// 	res.push_back(s[i]);
	// }
	// cout << res << endl;

	// split by space
	string s;
	getline(cin, s);

	string temp;
	vector<string> res;

	for (auto ch : s) {
		if (ch == ' ') {
			if (!temp.empty()) {
				res.push_back(temp);
				temp.clear();
			}
			continue;
		}
		temp += ch;
	}

	if (!temp.empty()) {
		res.push_back(temp);
	}

	for (auto s : res) {
		cout << s << endl;
	}

	// // remove vowels
	// string s;
	// string vowels = "aeiouAEIOU";
	// cin >> s;
	// string res;

	// for (auto ch : s) {
	// 	size_t pos = vowels.find(ch);
	// 	if (pos != string::npos) {
	// 		continue;
	// 	}
	// 	res += ch;
	// }

	// s = res;
	// cout << res << endl;

	// // reverse words in a string
	// string s;
	// getline(cin, s);
	// string res;
	// vector<string> words;

	// string temp = "";
	// for (char ch : s) {
	// 	if (ch == ' ') {
	// 		words.push_back(temp);
	// 		temp = "";
	// 		continue;
	// 	}
	// 	temp += ch;
	// }

	// words.push_back(temp);

	// for (auto& word : words) {
	// 	reverse(word.begin(), word.end());
	// }

	// for (int i = 0; i < words.size(); i++) {
	// 	res += words[i];
	// 	if (i < words.size() - 1) {
	// 		res += ' ';
	// 	}
	// }

	// cout << res << endl;

	// // print ASCII value
	// char ch;
	// cin >> ch;

	// cout << (int)ch << endl;

	// // remove a character
	// string s;
	// char ch;
	// cin >> s;
	// cin.ignore();
	// cin >> ch;

	// for (int i = 0; i < s.size(); i++) {
	// 	if (s[i] == ch) {
	// 		s.erase(i, 1);
	// 		i--;
	// 	}
	// }

	// cout << s << endl;

	// // search for a word
	// string s;
	// string word;
	// getline(cin, s);
	// cin.ignore();
	// cin >> word;

	// if (s.find(word) != string::npos) {
	// 	cout << "Found, True" << endl;
	// } else {
	// 	cout << "Not Found, False" << endl;
	// }

	// // count vowels
	// string s;
	// getline(cin, s);
	// int count = 0;
	// string vowels = "aeiouAEIOU";

	// for (auto ch : s) {
	// 	if (vowels.find(ch) != string::npos) {
	// 		count++;
	// 	}
	// }

	// cout << count << endl;

	// // Anagram check
	// string s1;
	// string s2;

	// cin >> s1;
	// cin >> s2;

	// sort(s1.begin(), s1.end());
	// sort(s2.begin(), s2.end());

	// if (s1 == s2) {
	// 	cout << "It is an anagram" << endl;
	// } else {
	// 	cout << "It is NOT an anagram" << endl;
	// }

	// pallindrome check
	// string s;
	// cin >> s;

	// int i = 0;
	// int j = s.size() - 1;
	// bool isPallindrome = true;
	// while (i < j) {
	// 	if (s[i] != s[j]) {
	// 		isPallindrome = false;
	// 		break;
	// 	}

	// 	i++;
	// 	j--;
	// }

	// if (isPallindrome) {
	// 	cout << s << " is a pallindrome" << endl;
	// } else {
	// 	cout << s << " is NOT a pallindrome" << endl;
	// }

	return 0;
}