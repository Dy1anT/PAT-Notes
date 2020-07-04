#include <iostream>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    string fname, mname, fid, mid;
    string name, id;
    int fgrade = -1, mgrade = 101;
    int grade;
    char gender;
    for (int i = 0; i < n; i++) {
        cin >> name >> gender >> id >> grade;
        if (gender == 'M') {
            if (grade < mgrade) {
                mname = name;
                mid = id;
                mgrade = grade;
            }
        } else if (gender == 'F') {
            if (grade > fgrade) {
                fname = name;
                fid = id;
                fgrade = grade;
            }
        }
    }
    if (fgrade == -1) cout << "Absent\n";
    else cout << fname << " " << fid << endl;
    if (mgrade == 101) cout << "Absent\n";
    else cout << mname << " " << mid << endl;
    if (fgrade == -1 || mgrade == 101) cout << "NA\n";
    else cout << fgrade - mgrade << endl;
    system("pause");
    return 0;
}