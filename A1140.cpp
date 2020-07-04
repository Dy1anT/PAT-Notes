#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, k;
    string s, ans;
    cin >> s >> a;
    for (int i = 0; i < a - 1; i++) {
        ans = "";
        for (int j = 0; j < s.length(); j = k) {
            for (k = j; k < s.length() && s[j] == s[k]; k++);
            ans +=  s[j] + to_string(k - j);
        }
        s = ans;
    }
    cout << s;
    //system("pause");
    return 0;
}
