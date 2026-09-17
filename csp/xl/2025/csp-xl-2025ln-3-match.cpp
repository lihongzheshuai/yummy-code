/**
 * 题目: 【CSP】CSP-XL 2025辽宁复赛真题-第三题, 小L打比赛（match）
 * 题号: 
 * 归属: CSP-J
 * 博客: https://www.coderli.com/csp-xl-2025ln-3-match/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>

struct Match {
    int start = 0; // 比赛开始时间
    int end = 0;   // 比赛结束时间
};

// 按结束时间升序排序的比较函数
bool cmp(Match a, Match b) { return a.end < b.end; }

// 全局数组，存储所有比赛
struct Match matches[500005];

int main() {
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    int n;
    std::cin >> n;
    // 读入 n 场比赛的起止时间
    for (int i = 0; i < n; i++) {
        std::cin >> matches[i].start >> matches[i].end;
    }
    // 按结束时间升序排序，为贪心选择做准备
    std::sort(matches, matches + n, cmp);
    int count = 1;              // 至少能打一场比赛
    int cur_end = matches[0].end; // 当前所选最后一场的结束时间

    // 贪心选择：每次挑结束时间最早且不与上一场比赛冲突的比赛
    for (int i = 1; i < n; i++) {
        if (matches[i].start > cur_end) { // 无冲突
            count++;
            cur_end = matches[i].end;     // 更新最后结束时间
        }
    }
    std::cout << count << std::endl; // 输出最多能观看的比赛场数
    return 0;
}
