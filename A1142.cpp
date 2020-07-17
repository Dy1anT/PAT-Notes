#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;


int main() {
    int n, m, a, b, c;
    scanf("%d%d", &n, &m);
    vector<int> G[n + 1];
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b); 
        G[b].push_back(a);
    }
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &c);
        int hash[n + 1] = {0};
        int clique[n + 1] = {0};
        for (int j = 0; j < c; j++) {
            scanf("%d", &a);
            clique[a] = 1;
            hash[a]++;
            for (auto it:G[a]) {
                hash[it]++;
            }
        }
        int cnt = 0, flag = 1;
        for (int j = 1; j <= n; j++) {
            if (hash[j] == c) cnt++;
            if (clique[j] && hash[j] != c) flag = 0;
        }
        if (flag == 1 && cnt == c) printf("Yes\n");
        else if (flag == 1 && cnt > c) printf("Not Maximal\n");
        else if (flag == 0) printf("Not a Clique\n");
    }
    system("pause");
    return 0;
}