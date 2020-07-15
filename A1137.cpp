#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    string id;
    int online;
    int mid, final;
    int score;
};
bool cmp(node a, node b) {
    return a.score != b.score? a.score > b.score: a.id < b.id;
}
int main() {
    int p, m, n, num;
    cin >> p >> m >> n;
    string name;
    unordered_map<string, node> mp;
    for (int i = 0; i < p; i++) {
        cin >> name >> num;
        mp[name].id = name;
        mp[name].online = num;
        mp[name].final = -1;
        mp[name].mid = -1;
    }
    for (int i = 0; i < m; i++) {
        cin >> name >> num;
        mp[name].mid = num;    
    }
    for (int i = 0; i < n; i++) {
        cin >> name >> num;
        mp[name].final = num;    
    }
    vector<node> ans;
    for (auto it: mp) {
        if(it.second.online >= 200) {
            node x = it.second;
            if (x.mid > x.final) {
                x.score = int(x.mid * 0.4 + x.final * 0.6 + 0.5);
            } else x.score = x.final;
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for (auto it: ans) {
        if (it.score >= 60)
            printf("%s %d %d %d %d\n", it.id.c_str(), it.online, it.mid, it.final, it.score);
    }
    system("pause");
    return 0;
}