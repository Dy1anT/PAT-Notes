#include <iostream>
using namespace std;
bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int msize, n, m, num;
    scanf("%d%d%d", &msize, &n, &m);
    while(!isPrime(msize)) msize++;
    int hashtable[msize] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        for (int j = 0; j < msize; j++) {
            if (hashtable[(num + j * j) % msize] == 0) {
                hashtable[(num + j * j) % msize] = num;
                break;
            } else if (j == msize - 1) {
                printf("%d cannot be inserted.\n", num);
            }
        }
    }
    double cnt = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        for (int j = 0; j <= msize; j++) {
            cnt++;
            if (hashtable[(num + j * j) % msize] == num || hashtable[(num + j * j) % msize] == 0) {
                break;
            }
        }
    }
    printf("%.1f", cnt / m);
    system("pause");
    return 0;
}