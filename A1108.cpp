#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

int main() {
    int n, m, xs, dn;
    double a, sum = 0;
    string s;
    scanf("%d", &n);
    m = n;
    for (int i =0; i < m; i++) {
        cin >> s;
        xs = 0 ;dn = 0;a = 0;
        for (int j = 0; j < s.length(); j++) {
            if ((s[j] - '0' < 0 || s[j] - '0' > 9) && (s[j] != '.' && s[j] != '-')) {
                cout << "ERROR: " << s <<" is not a legal number" << endl;
                n--;
                break;
            }
            if (dn == 1) xs++;
            if (s[j] == '.') dn++;
            if (dn > 1 || xs > 2) {
                cout << "ERROR: " << s <<" is not a legal number" << endl;
                n--;
                break;
            }
            if (j != 0 && s[j] == '-') {
                cout << "ERROR: " << s <<" is not a legal number" << endl;
                n--;
                break;
            }
            if (j == 0 && s[j] == '.') {
                cout << "ERROR: " << s <<" is not a legal number" << endl;
                n--;
                break; 
            }
            if (j == s.length() - 1) {
                if (s[0] == '-') a = 0 - stod(s.substr(1));
                else a = stod(s);
                if(a > 1000 || a < -1000){
                    cout << "ERROR: " << s <<" is not a legal number" << endl;
                    n--;
                    break;
                }
                sum += a;
            }
        }
    }
    if (n == 0) cout << "The average of 0 numbers is Undefined" << endl;
    else if (n == 1) cout << "The average of 1 number is " << fixed << setprecision(2) << sum << endl;
    else if (n > 1) cout << "The average of " << n <<" numbers is " << fixed << setprecision(2) << sum / n << endl;
    //system("pause");
    return 0;
}
