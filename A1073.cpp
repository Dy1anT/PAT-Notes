#include <iostream>
#include <string>
using namespace std;
int main() {
	string s; 
	cin >> s;
	int e; 
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == 'E') e = i;
	}
	int n = stoi(s.substr(e + 1));
	if (s[0] == '-') cout << "-";
	s = s.substr(1, e - 1);
	if (n < 0) {
		cout << "0.";
		while(++n) cout << "0";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') continue;
			cout << s[i];
		}
	} else if (n >= (s.size() - 2)) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') continue;
			cout << s[i];
		}
		for (int i = 0; i < n - (s.size() - 2); i++) cout << "0";
	} else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') continue;
			cout << s[i];
			if (i == n + 1) cout << ".";
		}
	}
	return 0;
}