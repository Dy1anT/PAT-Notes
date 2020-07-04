#include <iostream>
using namespace std;

int main() {
    int a, b, t, c = 0;
    double sum[1001] = {0};
    double num;
    string s = "";
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d%lf", &t, &num);
        sum[t] += num;
    }
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        scanf("%d%lf", &t, &num);
        sum[t] += num;
    }
    for (int i = 0; i < 1001; i++) {
        if (sum[i] != 0) c++;
    }
    printf("%d", c);
    for (int i = 1000; i >= 0; i--) {
        if (sum[i] != 0.0) {
            printf(" %d %.1f", i, sum[i]);
        }
    }
    system("pause");
    return 0;
}
