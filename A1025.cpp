#include <algorithm>
#include <iostream>
using namespace std;

struct student{
    long long id;
    int score;
    int local_rank;
    int all_rank;
    int local;
}stu[30010];

bool cmp(student a, student b) {
     return a.score != b.score ? a.score > b.score : a.id < b.id;
}

int main() {
    int n, m, sum = 0;
    scanf("%d", &n);
    for(int x = 0; x < n; x++){
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%lld %d", &stu[sum + i].id, &stu[sum + i].score);
            stu[sum + i].local = x + 1;
        }
        sort(stu + sum, stu + sum + m, cmp);
        for(int i = 0; i < m; i++){
            stu[sum + i].local_rank = i + 1;
            if(i != 0 && stu[sum + i].score == stu[sum + i - 1].score) stu[sum + i].local_rank = stu[sum + i - 1].local_rank;
            }
        sum += m;
    }
    sort(stu, stu + sum, cmp);
    for(int i = 0; i < sum; i++){
        stu[i].all_rank = i + 1;
        if(i != 0 && stu[i].score == stu[i - 1].score) stu[i].all_rank = stu[i - 1].all_rank;
    }
    printf("%d\n", sum);
    for(int i = 0; i < sum; i++){
        printf("%013lld %d %d %d\n", stu[i].id, stu[i].all_rank, stu[i].local, stu[i].local_rank);
    }
    system("pause");
    return 0;
}
