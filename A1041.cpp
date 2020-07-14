#include <iostream>
using namespace std;

int main() {
    int n;
    int a[100000], hash[100000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ++hash[a[i]];
    }
    for (int i = 0; i < n; i++) {
        if (hash[a[i]] == 1) {
            printf("%d", a[i]);
            system("pause");
            return 0;
        }
    }
    printf("None");
    system("pause");
    return 0;
}