#include <iostream>
#include <string>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	string s = to_string(a + b);
	string output = "";
	int pos = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		output = s[i] + output;
		pos ++;
		if (pos % 3 == 0 && i != 0 && s[i - 1] != '-') {
			output = ',' + output;
		}
	}
	cout << output << endl;
	return 0;
}
