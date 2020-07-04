#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m = 0;
	string usr, pwd, s;
	vector<string> username;
	vector<string> password;
	cin >> n;
	for (int a = 0; a < n; a++) {
		cin >> usr >> pwd;
		s = pwd;
		for (int i = 0; i < pwd.length(); i++) {
			if (pwd[i] == '1')  pwd[i] = '@';
			if (pwd[i] == '0')  pwd[i] = '%';
			if (pwd[i] == 'l')  pwd[i] = 'L';
			if (pwd[i] == 'O')  pwd[i] = 'o';
		}
		if (pwd != s) {
			m++;
			username.push_back(usr);
			password.push_back(pwd);
		}
	}
	if (m != 0) {
		cout << m << endl;
		for (int i = 0; i < m; i++) {
			cout << username[i] << ' ' << password[i] << endl;
		}
	} else if (n == 1) {
		cout << "There is 1 account and no account is modified" << endl;
	} else {
		cout << "There are " << n << " accounts and no account is modified" << endl;
	}
	return 0;
}
