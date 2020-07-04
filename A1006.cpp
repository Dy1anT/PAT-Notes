#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string id, MINid, MAXid;
    int h1, h2, m1, m2, s1, s2;
    int MINtime, MAXtime;
    cin >> id;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
    MINtime = 3600 * h1 + 60 * m1 + s1;
    MAXtime = 3600 * h2 + 60 * m2 + s2;
    MAXid = MINid = id;
    for (int i = 1; i < n; i++) {
        cin >> id;
        scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
        if (3600 * h1 + 60 * m1 + s1 < MINtime) {
            MINtime = 3600 * h1 + 60 * m1 + s1;
            MINid = id;
        }
        if (3600 * h2 + 60 * m2 + s2 > MAXtime) {
            MAXtime = 3600 * h2 + 60 * m2 + s2;
            MAXid = id;
        }
    }
    cout << MINid << " " << MAXid;
    return 0;
}