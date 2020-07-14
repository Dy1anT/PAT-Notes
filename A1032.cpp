#include <string>
#include <iostream>
using namespace std;
struct node {
    char s;
    int next = 0;
    int flag = 0;
}node[100000];

int main() {
    int s1, s2, n, add, nex;
    char data;
    cin >> s1 >> s2 >> n;
    for (int i = 0; i < n; i++) {
       cin >> add >> data >> nex;
        node[add].s = data;
        node[add].next = nex;
    }
    while(s1 != -1) {
        node[s1].flag = 1;
        s1 = node[s1].next;
    }
    while(s2 != -1) {
        if (node[s2].flag == 1) {
            string ans = to_string(s2);
            while(ans.size() < 5) ans = '0' + ans;
            cout << ans;
            system("pause");
            return 0;
        }
        s2 = node[s2].next;
    }
    cout << "-1";
    system("pause");
    return 0;
}