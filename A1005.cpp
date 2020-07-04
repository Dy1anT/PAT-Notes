#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		sum += (s[i] - '0');
	}
	string ssum = to_string(sum);
	for (int i = 0; i < ssum.length(); i++) {
		if (i != 0) cout << " ";
		if (ssum[i] == '1') cout << "one";
		else if  (ssum[i] == '2') cout << "two";
		else if (ssum[i] == '3') cout << "three";
		else if (ssum[i] == '4') cout << "four";
		else if (ssum[i] == '5') cout << "five";
		else if (ssum[i] == '6') cout << "six";
		else if (ssum[i] == '7') cout << "seven";
		else if (ssum[i] == '8') cout << "eight";
		else if (ssum[i] == '9') cout << "nine";
		else if (ssum[i] == '0') cout << "zero";
	}
	return 0;
}
