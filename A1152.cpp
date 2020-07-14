#include <string>
#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n == 1 || n == 0) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    string s, sub;
    int i, n, len;
    cin >> n >> len >> s;
    for (i = 0; i <= n - len; i++) {
        sub = s.substr(i, len);
        if (isPrime(stoi(sub))) {
            cout << sub;
            break;
        }
    } 
    if (i > n - len) cout << "404";
    return 0;
}