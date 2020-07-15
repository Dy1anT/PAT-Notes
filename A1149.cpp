#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    unordered_map<string, vector<string>> mp;
    int n, m, c;
    string a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for (int i = 0; i < m; i++) {
        vector<string> list;
        cin >> c;
        for (int j = 0; j < c; j++) {
            cin >> a;
            list.push_back(a);
        }
        int flag = 1;
        for (int j = 0; j < list.size() && flag; j++) {
            for (int k = 0; k < mp[list[j]].size() && flag; k++) {
                for (int t = j; t < list.size() && flag; t++) {
                    if (mp[list[j]][k] == list[t]) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}