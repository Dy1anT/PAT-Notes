#include <iostream>
using namespace std;


void postorder(int data[], int i, int m) {
    if (i > m) return;
    postorder(data, i * 2, m);
    postorder(data, i * 2 + 1, m);
    printf("%d", data[i]);
    if (i != 1) printf(" ");
    return;
}
int main() {
    int n, m;
    cin >> n >> m;
    int data[m + 1];
    while(n--) {
        for (int i = 1; i <= m; i++) {
            cin >> data[i];
        }
        int max = 1, min = 1;
        for (int i = 2; i <= m; i++) {
            if (i % 2 == 0) {
                if (data[i] > data[i / 2])
                    max = 0;
            } else {
                if (data[i] > data[(i - 1) / 2])
                    max = 0;
            }
            if (i % 2 == 0) {
                if (data[i] < data[i / 2])
                    min = 0;
            } else {
                if (data[i] < data[(i - 1) / 2])
                    min = 0;
            }
        }
        if (max) {
            printf("Max Heap\n");
        } else if (min) {
            printf("Min Heap\n");
        } else {
            printf("Not Heap\n");
        }
        postorder(data, 1, m);
        printf("\n");
    }
    system("pause");
    return 0;
}