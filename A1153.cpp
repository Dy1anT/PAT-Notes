#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    string id;
    int score;
};
bool cmp(node a, node b) {
    return a.score != b.score? a.score > b.score: a.id < b.id;
}

int main() {
    vector<node> list;
    int m, n;
    cin >> m >> n;
    node a;
    for (int i = 0; i < m; i++) {

        cin >> a.id >> a.score;
        list.push_back(a);
    }
    int task;
    string order;
    
    for (int i = 1; i <= n; i++) {
        cin >> task >> order;
        printf("Case %d: %d %s\n", i, task, order.c_str());
        if (task == 1) {
            vector<node> ans;
            for (auto it:list) {
                if (it.id.substr(0, 1) == order) 
                    ans.push_back(it);
            }
            sort(ans.begin(), ans.end(), cmp);
            for (auto it:ans) 
                printf("%s %d\n", it.id.c_str(), it.score);
            if (ans.size() == 0) printf("NA\n");
        } else if (task == 2) {
            int sum = 0, cnt = 0;
            for (auto it:list) {
                if (it.id.substr(1, 3) == order) {
                    sum += it.score;
                    cnt++;
                }
            }
            if (cnt == 0) printf("NA\n");
            else printf("%d %d\n", cnt, sum);
        } else if (task == 3) {
            vector<node> ans;
            unordered_map<string, int> mp;
            for (auto it:list) {
                if (it.id.substr(4, 6) == order) {
                    mp[it.id.substr(1, 3)]++;
                }
            }
            for (auto it:mp) {
                ans.push_back({it.first, it.second});
            }
            sort(ans.begin(), ans.end(), cmp);
            for (auto it:ans) 
                printf("%s %d\n", it.id.c_str(), it.score);
            if (ans.size() == 0) printf("NA\n");
        }
    }
    system("pause");
    return 0;
}