#include <vector>
#include <iostream>
using namespace std;
struct node {
    int a, b;
};
int main() {
    int v, e, a, b, k, c;
    scanf("%d%d", &v, &e);
    vector<node> G;
    for (int i = 0; i < e; i++) {
        scanf("%d%d", &a, &b);
        G.push_back({a, b});
    }
    scanf("%d", &k);
    for (int cnt = 0; cnt < k; cnt++) {
        int cover[v] = {0};
        scanf("%d", &c);
        for (int i = 0; i < c; i++) {
            scanf("%d", &a);
            cover[a] = 1;
        }
        int flag = 1;
        for (int i = 0; i < G.size(); i++) {
            if (cover[G[i].a] == 0 && cover[G[i].b] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    system("pause");
    return 0;
}