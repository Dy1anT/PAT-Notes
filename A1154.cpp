#include <vector>
#include <iostream>
#include <set>
using namespace std;

int main() {
    int v, e, a, b, c;
    scanf("%d%d", &v, &e);
    vector<int> G[v];
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int color[v];
    set<int> se;
    scanf("%d", &c);
    for (int cnt = 0; cnt < c; cnt++) {
        se.clear();
        int flag = 1;
        for (int i = 0; i < v; i++) {
            scanf("%d", &color[i]);
            se.insert(color[i]);
        }
        for (int i = 0; i < v && flag; i++) {
            for (int j = 0; j < G[i].size() && flag; j++) {
                if(color[i] == color[G[i][j]]) flag = 0;
            }
        }
        if (flag) printf("%d-coloring\n", se.size());
        else printf("No\n");
    }
    system("pause");
    return 0;
}