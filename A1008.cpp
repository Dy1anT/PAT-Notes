#include <iostream>
using namespace std;

int main() {
    int pos = 0, t, n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t >= pos) {
            ans += 6 * (t - pos);
        } else {
            ans += 4 * (pos - t);
        }
        pos = t;
        ans += 5;
    }
    cout << ans;
    return 0;
}