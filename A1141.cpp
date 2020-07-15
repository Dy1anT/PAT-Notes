#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
string lower(string s) {
    for (int i = 0; i < s.size(); i++) 
        s[i] = tolower(s[i]);
    return s;
}
struct node {
    string school;
    int score;
    int cnt;
};
bool cmp(node a, node b) {
    if(a.score != b.score) return a.score > b.score;
    else if (a.cnt != b.cnt) return a.cnt < b.cnt;
    else return a.school < b.school;
    }
int main() {
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    int n;
    double score;
    string school, id;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> score >> school;
        school = lower(school);
        if (id[0] == 'T') score *= 1.5;
        else if (id[0] == 'B') score /= 1.5;
        cnt[school]++;
        sum[school] += score;
    }
    vector<node> rank;
    for (auto it: cnt) {
        rank.push_back({it.first, (int)sum[it.first], it.second});
    }
    printf("%d\n", rank.size());
    sort(rank.begin(), rank.end(), cmp);
    int rk = 1, prerk = 0;
    for (int i = 0; i < rank.size(); i++) {
        rk = i + 1;
        if (i != 0 && rank[i].score == rank[i - 1].score) rk = prerk;
        printf("%d %s %d %d\n", rk, rank[i].school.c_str(), rank[i].score, rank[i].cnt);
        prerk = rk;
    }
    system("pause");
    return 0;
}