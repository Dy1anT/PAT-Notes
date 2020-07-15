#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int , int> mp;
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        mp[num]++;
    }
    int ans = 0;
    while (++ans) {
        if (!mp[ans]) {
            cout << ans;
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}