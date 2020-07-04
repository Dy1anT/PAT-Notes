#include <iostream>
using namespace std;
int main() {
    char WTL[3] = {'W', 'T', 'L'};
    double profit = 1;
    for (int i = 0; i < 3; i++) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        double max = a;
        int flag = 0;
        if (b > max) {max = b; flag = 1;}
        if (c > max) {max = c; flag = 2;}
        printf("%c ", WTL[flag]);
        profit *= max;
    }
    profit = 2 * (profit * 0.65 - 1);
    printf("%.2f", profit);
    return 0;
}