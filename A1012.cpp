#include <algorithm>
#include <iostream>
using namespace std;

struct stu{
    int id;
    int score[4], rank[4];
}student[10000];
int flag = 0;
bool cmp(stu a, stu b) {
    return a.score[flag] > b.score[flag];
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &student[i].id, &student[i].score[1], &student[i].score[2], &student[i].score[3]);
        student[i].score[0] = (student[i].score[1] + student[i].score[2] + student[i].score[3]) / 3 + 0.5;
    }
    for (int i = 0; i < 4; i++) {
        sort(student, student + n, cmp);
        flag++;
        for (int j = 0; j < n; j++) {
            student[j].rank[i] = j + 1;
            if (j != 0 && student[j].score[i] == student[j - 1].score[i]) {
                student[j].rank[i] = student[j - 1].rank[i];
            }
        }
    }
    int id, ans1, ans2;
    char word[4] = {'A', 'C', 'M', 'E'};
    for (int i = 0; i < m; i++) {
        ans1 = n + 1; 
        scanf("%d", &id);
        for (int j = 0; j < n; j++) {
            if (id == student[j].id) {
                for (int k = 0; k < 4; k++) {
                    if (student[j].rank[k] < ans1) {
                        ans1 = student[j].rank[k];
                        ans2 = k;
                    }
                }
            }
        }
        if (ans1 == n + 1) printf("N/A\n");
        else printf("%d %c\n", ans1, word[ans2]);
    }
    system("pause");
    return 0;
}
