#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(char a, char b) {return a > b;}

int main() {
    string s, ss, an;
    cin >> s;
    while (s.size() < 4) s = '0' + s;
    ss = s;
    int a, b, ans = 1;
    while (ans != 6174 && ans != 0) {
        sort(s.begin(), s.end(), cmp);
        sort(ss.begin(), ss.end());
        a = stoi(s);
        b = stoi(ss);
        ans = a - b;
        an = to_string(ans);
        while (an.size() < 4) an = '0' + an;
        cout << s << " - " << ss << " = " << an <<endl;
        s = ss = an;
    }
    system("pause");
    return 0;
}