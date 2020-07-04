#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long n, m;
    int sum = 0, tmp, start, j;
    scanf("%lld", &n);
    for (int i = 2; i < sqrt(n) + 1; i++){
        if (n % i == 0) {
            tmp = i;
            for (j = 1; i + j < sqrt(n) + 1; j++) {
                tmp *= i + j;
                if (n % tmp != 0) break;
            }
            if (j > sum) {
                start = i;
                sum = j;
            }
        }
    }
    if (sum != 0) {
        printf("%d\n", sum);
        for (int i = 0; i < sum; i++) {
            if (i != 0) printf("*");
            printf("%d", start + i);
        }
    } else {
        printf("1\n%lld", n);
    }
    system("pause");
    return 0;
}
