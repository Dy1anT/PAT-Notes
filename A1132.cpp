#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s, s1, s2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        s1 = s.substr(0, s.size() / 2);
        s2 = s.substr(s.size() / 2, s.size() / 2);
        if (stoi(s1) * stoi(s2) == 0) cout << "No" << endl;
        else if (stoi(s) % (stoi(s1) * stoi(s2)) == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    system("pause");    
    return 0;
}