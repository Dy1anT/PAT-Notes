#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	vector<string> list;
	string s, Kuchiguse = "";
	int n, min_length = 256, flag = 1;
    scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		reverse(s.begin(), s.end());
		list.push_back(s);
		if (s.length() < min_length) min_length = s.length();
	}
	for (int i = 0; i < min_length; i++) {
		for (int j = 1; j < n; j++) {
			if (list[0][i] != list[j][i] || list[0][i] == ' ') flag = 0;
		}
		if (flag == 1) Kuchiguse = list[0][i] + Kuchiguse;
		else break;
	}
	if (Kuchiguse.length() != 0) cout << Kuchiguse;
	else cout << "nai";
	return 0;
}
