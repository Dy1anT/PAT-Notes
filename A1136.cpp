#include <iostream>
#include <algorithm>
using namespace std;
string rev(string s) {
	string re(s.rbegin(), s.rend());
	return re;
}
string add(string s1, string s2) {
	string sum = s1;
	int carry = 0;
	for (int i = s1.size() - 1; i >= 0; i--) {
		sum[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
		carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
	}
	if(carry > 0) sum = "1" + sum;
	return sum;
}
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 10; i++) {
		if (s == rev(s)) {
			cout << s << " is a palindromic number.\n";
			return 0;
		} else {
			cout << s << " + " << rev(s) << " = " << add(s, rev(s)) << endl;
			s = add(s, rev(s));
		}
	}
	cout  << "Not found in 10 iterations.\n";
	return 0;
}
