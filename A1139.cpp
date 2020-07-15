#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct node {
    string a, b;
};

bool cmp(node a, node b) {
    return a.a!=b.a?a.a<b.a:a.b<b.b;
}
int main() {
    int m, n, c;
    string a, b;
    cin >> m >> n;
    unordered_map<string, vector<string>> op;
    unordered_map<string, vector<string>> sa;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a.size() != b.size()) {
            op[a].push_back(b);
            op[b].push_back(a);
        } else {
            sa[a].push_back(b);
            sa[b].push_back(a);
        }
    }
    cin >> c;
    for (int i = 0; i < c; i++) {
        int cnt = 0;
        vector<node> ans;
        cin >> a >> b;
        if (a.size() != b.size()) {
            for (auto i: sa[a]) {
                for (auto j:op[i]) {
                    for (auto k:sa[b]) {
                        if (k == j){
                            if (i[0]=='-') i = i.substr(1, i.size() - 1);
                            if (j[0]=='-') j = j.substr(1, j.size() - 1);
                            ans.push_back({i, j});
                            cnt++;
                            break;
                        }
                    }
                }
            }
        } else {
            for (auto i: sa[a]) {
                if(i == b) continue;
                for (auto j:sa[i]) {
                    if (j == a || j == b) continue;
                    for (auto k:sa[b]) {
                        if (k == j){
                            if (i[0]=='-') i = i.substr(1, i.size() - 1);
                            if (j[0]=='-') j = j.substr(1, j.size() - 1);
                            ans.push_back({i, j});
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", cnt);
        for (auto it: ans) printf("%s %s\n", it.a.c_str(), it.b.c_str());
    }
    system("pause");
    return 0;
}