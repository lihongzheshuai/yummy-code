/**
 * Problem: luogu-P1068 [NOIP2009 普及组] 分数线划定
 * Algorithm: 结构体多关键字排序与比例截断 (Multi-key Struct Sorting)
 * Standard: C++11 (CCF GESP 四级 / CSP-J 官方规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 选手信息结构体
struct Candidate {
    int id;    // 报名号 (1000 ~ 9999)
    int score; // 笔试成绩 (1 ~ 100)
};

// 自定义多关键字比较函数
// 规则 1：成绩从高到低排序（降序）
// 规则 2：成绩相同时，报名号由小到大排序（升序）
bool cmp(const Candidate& a, const Candidate& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Candidate> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].id >> a[i].score;
    }

    // 执行多关键字排序
    sort(a.begin(), a.end(), cmp);

    // 划定面试基准名次：m * 150% 向下取整
    int target_rank = m * 3 / 2;

    // 面试分数线为基准名次选手的成绩（下标从 0 开始，第 target_rank 名下标为 target_rank - 1）
    int cutoff_score = a[target_rank - 1].score;

    // 统计实际进入面试的人数（包含所有不低于分数线的重分选手）
    int actual_count = 0;
    while (actual_count < n && a[actual_count].score >= cutoff_score) {
        actual_count++;
    }

    // 第一行输出：面试分数线 实际进入面试的选手数
    cout << cutoff_score << " " << actual_count << "\n";

    // 接下来输出所有入围选手的报名号与笔试成绩
    for (int i = 0; i < actual_count; ++i) {
        cout << a[i].id << " " << a[i].score << "\n";
    }

    return 0;
}
