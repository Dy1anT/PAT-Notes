#include <iostream>
using namespace std;

int main() {
    int order[55];
    int cards[55];
    int shuffle[55];

    int n;
    scanf("%d", &n);
    for (int i = 0; i < 55; i++) {
        cards[i] = i;
    }
    order[0] = 0;
    int a;
    for (int i = 1; i < 55; i++) {
        scanf("%d", &a);
        order[i] = a;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 1; i < 55; i++) {
            shuffle[order[i]] = cards[i];
        }
        for (int i = 1; i < 55; i++) {
            cards[i] = shuffle[i];
        }
    }
    for (int i = 1; i < 55; i++) {
        if (cards[i] >= 1 && cards[i] <= 13) {
            printf("S%d", cards[i]);
        } else if (cards[i] >= 14 && cards[i] <= 26) {
            printf("H%d", cards[i] - 13);
        } else if (cards[i] >= 27 && cards[i] <= 39) {
            printf("C%d", cards[i] - 26);
        } else if (cards[i] >= 40 && cards[i] <= 52) {
            printf("D%d", cards[i] - 39);
        } else if (cards[i] >= 53 && cards[i] <= 54) {
            printf("J%d", cards[i] - 52);
        }
        if (i < 54) printf(" ");
    }
    system("pause");
    return 0;
}
