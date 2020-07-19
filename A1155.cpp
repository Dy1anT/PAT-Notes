#include <vector>
#include <iostream>
using namespace std;
vector<int> stack;
void dfs(int a[], int i, int n) {
    if (i > n) {
        for (int j = 0; j < stack.size(); j++) {
            cout << stack[j];
            if (j != stack.size() - 1) cout << " ";
            else cout << "\n";
        }
        return;
    }
    stack.push_back(a[i]);
    if (2 * i + 1 <= n) {
        dfs(a, 2 * i + 1, n);
        dfs(a, 2 * i, n);
    } else {
        dfs(a, 2 * i, n);
    }
    stack.pop_back();
}
int main() {
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int max = 1, min = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i / 2]) max = 0;
        if (a[i] < a[i / 2]) min = 0;
    }
    dfs(a, 1, n);
    if (max) cout << "Max Heap\n";
    else if (min) cout << "Min Heap\n";
    else cout << "Not Heap\n";
    system("pause");
    return 0;
}