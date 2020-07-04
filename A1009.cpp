#include <iostream>
using namespace std;

int main() {
    int a, b, t, c = 0;
    double x1[1001] = {0};
    double x2[2001] = {0};
    double num;
    string s = "";
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d%lf", &t, &num);
        x1[t] = num;
    }
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        scanf("%d%lf", &t, &num);
        for (int j = 0; j < 1001; j++) {
            if (x1[j] != 0.0) {
                x2[j + t] += x1[j] * num;
            } 
    }
    }
    for (int i = 0; i < 2001; i++) {
        if (x2[i] != 0) c++;
    }
    printf("%d", c);
    for (int i = 2000; i >= 0; i--) {
        if (x2[i] != 0.0) {
            printf(" %d %.1f", i, x2[i]);
        }
    }
    system("pause");
    return 0;
}
