/**
 * 题目: 【GESP/CSP练习】GESP七级 / CSP-S 题解：luogu-P1113 [USACO02FEB] 杂务
 * 题号: P1113
 * 归属: GESP七级 / CSP-S / USACO 经典题库
 * 博客: https://www.coderli.com/gesp-7-luogu-p1113/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 最大杂务数量常数，题目给定 n <= 10000
const int MAXN = 10005;

// f[i] 表示完成第 i 项杂务所需的最早完工时间
// 全局数组自动零初始化
int f[MAXN];

int main() {
    int n;
    cin >> n;

    int ans = 0; // 记录全场所有任务中最大的完工时间，即总工程最短总耗时

    // 依次读入每项杂务的详细说明
    // 题目性质保证：第 k 项杂务的准备工作编号必定属于 [1, k - 1]
    // 因此输入的 1 到 n 顺序天然构成了 DAG 的合法拓扑排序，支持在线单向状态转移
    for (int i = 1; i <= n; ++i) {
        int id, len;
        cin >> id >> len;

        int max_prev_time = 0; // 记录所有前置准备工作中，最晚完工的那一项的时刻
        int prereq;

        // 读入当前杂务的所有前置准备工作，以数字 0 作为结束哨兵
        while (cin >> prereq && prereq != 0) {
            max_prev_time = max(max_prev_time, f[prereq]);
        }

        // 当前杂务的最早完工时间 = 最晚前置完工时刻 + 当前任务自身所需时长
        f[id] = max_prev_time + len;

        // 维护全局所有杂务完工时刻的最大值
        ans = max(ans, f[id]);
    }

    // 输出完成全部杂务所需的最短总时间
    cout << ans << endl;

    return 0;
}
