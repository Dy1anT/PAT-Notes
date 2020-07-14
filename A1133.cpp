#include <string>
#include <iostream>
using namespace std;
struct node {
    string add;
    int num;
    int next;
}node[100000];

int main() {
    int head, n, k;
    int data, add, next;
    string address;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        cin >> address >> data >> next;
        add = stoi(address);
        node[add].num = data;
        node[add].next = next;
        node[add].add = address;
    }
    int pos = head;
    int cnt = 0;
    for (pos = head; pos != -1; pos = node[pos].next) {
        if (node[pos].num < 0) {
            if (cnt != 0) cout << node[pos].add << endl;
            cout << node[pos].add << " " << node[pos].num << " ";
            cnt++;
        }
    }
    pos = head;
    for (pos = head; pos != -1; pos = node[pos].next) {
        if (node[pos].num >= 0 && node[pos].num <= k) {
            if (cnt != 0) cout << node[pos].add << endl;
            cout << node[pos].add << " " << node[pos].num << " ";
            cnt++;
        }
    }
    pos = head;
    for (pos = head; pos != -1; pos = node[pos].next) {
        if (node[pos].num > k) {
            if (cnt != 0) cout << node[pos].add << endl;
            cout << node[pos].add << " " << node[pos].num << " ";
            cnt++;
        }
    }
    cout << "-1" << endl;
    system("pause");
    return 0;
}