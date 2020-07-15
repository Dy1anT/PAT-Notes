#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string , int> mp;
    int m, n, s, flag = 0;
    string name;
    scanf("%d%d%d", &m, &n, &s);
    for (int i = 1; i <= m; i++) {
        cin >> name;
        if (mp[name] == 1) s++;
        if (i == s && mp[name] == 0) {
            mp[name] = 1;
            cout << name << endl;
            flag = 1;
            s += n;
        }
    }
    if (!flag) cout << "Keep going..."; 
    system("pause");
    return 0;
}