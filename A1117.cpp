#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int n, x, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        a.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1) ans = i + 1;
    }
    printf("%d", ans);
    return 0;
}