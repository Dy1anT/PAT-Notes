#include <iostream>
using namespace std;

int main() {
    int m, n, cnt = 0, mid, ans;
    int a[200005], b[200005];
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int i = 1, j = 1;
    mid = (m + n + 1) / 2;
    while (i <= m && j <= n) {
        ans = a[i] <= b[j] ? a[i++] : b[j++];
        if (++cnt == mid) break;
    }
    if (mid > cnt && i <= m)
        ans = a[i - 1 + mid - cnt];
    if (mid > cnt && j <= n)
        ans = b[j - 1 + mid - cnt];
    printf("%d", ans);
    //system("pause");
    return 0;
}