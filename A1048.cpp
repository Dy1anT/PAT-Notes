#include <iostream>
using namespace std;

int main() {
    int n, m, num, a[10000] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        a[num]++;
    }
    for (int i = 0; 2 * i <= m; i++) {
        if (a[i]) {
            if (2 * i < m && a[m - i]) {
                printf("%d %d", i, m - i);
                return 0;
            } else if (2 * i == m && a[i] >= 2) {
                printf("%d %d", i, i);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}