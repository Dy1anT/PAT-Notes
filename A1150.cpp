#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

struct edge {
    int a, dist;
};
int main() {
    int n, m, a, b, c, d;
    scanf("%d%d", &n, &m);
    vector<edge> G[n + 1];
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &d);
        G[a].push_back({b, d});
        G[b].push_back({a, d});
    }

    int k, shortest = INT_MAX, shorti;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c);
        int hash[n + 1] = {0};
        int pre, start, cnt = 0, dist = 0, na = 0;
        scanf("%d", &start);
        pre = start;
        for (int j = 1; j < c; j++) {
            scanf("%d", &a);
            for (auto it:G[pre]) {
                if (it.a == a) {
                    dist += it.dist;
                    if(hash[it.a] == 0) {
                        cnt++;
                        hash[it.a]++;
                    }
                    pre = a;
                    break;
                }
            }
            if (pre != a) na = 1;
        }
        if(cnt == n && start == a && c == n + 1) {
            printf("Path %d: %d (TS simple cycle)\n", i, dist);
            if (dist < shortest) {
                shortest = dist;
                shorti = i;
            }
        } else if (cnt == n && start == a && c > n + 1) {
            printf("Path %d: %d (TS cycle)\n", i, dist);
            if (dist < shortest) {
                shortest = dist;
                shorti = i;
            }
        } else if (cnt < n && na == 0) {
            printf("Path %d: %d (Not a TS cycle)\n", i, dist);
        } else {
            printf("Path %d: NA (Not a TS cycle)\n", i, dist);
        }
    }
    printf("Shortest Dist(%d) = %d", shorti, shortest);
    system("pause");
    return 0;
}