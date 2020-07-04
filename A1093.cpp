#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    int P[300000]= {0};
    int T[300000]= {0};
    int p = 0, t = 0, ans = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'P') P[i] = ++p;
        else P[i] = p;
    }
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'T') T[i] = ++t;
        else T[i] = t;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') ans = (ans +(P[i] * T[i]) % 1000000007) % 1000000007;
    }
    cout << ans;
    system("pause");
    return 0;
}
