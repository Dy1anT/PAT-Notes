#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    int n, a, sum = 0;
    scanf("%d", &n);
    v.push_back(0);
    for (int i = 0; i< n; i++) {
        scanf("%d", &a);
        sum += a;
        v.push_back(sum);
    }
    int m, x, y, tmp;
    int dis;
    scanf("%d", &m);
    for (int i = 0; i< m; i++) {
        scanf("%d%d", &x, &y);
        if (x > y) {tmp = x; x = y; y = tmp;}
        dis = v[y - 1] - v[x - 1];
        if (sum - dis < dis) dis = sum - dis;
        printf("%d\n", dis);
    }
    system("pause");
    return 0;
}
