#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> pre;
vector<int> in;
map<int, int> mp;

int main() {
    int n;
    cin >> n;
    pre.resize(n + 1);
    in.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> in[i];
        mp[in[i]] = i;
    }
    int pos = 1, mid, low = 1, high = n;
    while(1) {
        mid = mp[pre[pos]];
        if (mid - low > 0) {
            high = mid - 1;
            pos++;
        } else if (high - mid > 0) {
            low = mid + 1;
            pos++;
        } else if (high - mid == 0 && mid - low == 0) {
            cout << in[mid];
            break;
        }
    }
    system("pause");
    return 0;
}