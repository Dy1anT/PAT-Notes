#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> mp;
vector<int> pre;

int main() {
    int n, m, u, v;
    cin >> m >> n;
    pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        mp[pre[i]] = i;
    }
    while (m--) {
        cin >> u >> v;
        if (mp[u] == 0 && mp[v] == 0) {printf("ERROR: %d and %d are not found.\n", u, v); continue;}
        else if (mp[u] == 0) {printf("ERROR: %d is not found.\n", u); continue;}
        else if (mp[v] == 0) {printf("ERROR: %d is not found.\n", v); continue;}
        int pos = 1, tmp = pos;
        while(1) {
            if (u > pre[pos] && v > pre[pos]) {
                tmp = pos;
                while(pre[++pos] < pre[tmp]) ;
            } else if (u < pre[pos] && v < pre[pos]) {
                pos++;
            } else if (u == pre[pos]) {
                printf("%d is an ancestor of %d.\n", u, v);
                break;
            } else if (v == pre[pos]) {
                printf("%d is an ancestor of %d.\n", v, u);
                break;
            } else if ((u < pre[pos] && v > pre[pos]) || (u > pre[pos] && v < pre[pos])) {
                printf("LCA of %d and %d is %d.\n", u, v, pre[pos]);
                break;
            }
        }
    }
    system("pause");
    return 0;
}