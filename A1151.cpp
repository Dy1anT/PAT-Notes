#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> pre;
vector<int> in;
map<int, int> mp;

int main() {
    int n, m, u, v;
    scanf("%d%d", &m, &n);
    pre.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        mp[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
    while(m--) {
        scanf("%d%d", &u, &v);
        if (mp[u] == 0 && mp[v] == 0) {printf("ERROR: %d and %d are not found.\n", u, v); continue;}
        else if (mp[u] == 0) {printf("ERROR: %d is not found.\n", u); continue;}
        else if (mp[v] == 0) {printf("ERROR: %d is not found.\n", v); continue;}
        int vi = mp[v], ui = mp[u];
        int pos = 1, mid, low = 0;

        while(1) {
            mid = mp[pre[pos]];
            if (ui < mid && vi < mid) {
                pos++;
            } else if (ui > mid && vi > mid) {
                pos += mid - low;
                low = mid;
            } else if (ui == mid) {
                printf("%d is an ancestor of %d.\n", u, v);
                break;
            } else if (vi == mid) {
                printf("%d is an ancestor of %d.\n", v, u);
                break;
            } else if ((ui < mid && vi > mid) || (ui > mid && vi < mid)) {
                printf("LCA of %d and %d is %d.\n", u, v, in[mid]);
                break;
            }
        }
    }
    system("pause");
    return 0;
}