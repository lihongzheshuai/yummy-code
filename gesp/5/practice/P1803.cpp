/**
 * Problem: luogu-P1803 凌乱的yyy / 线段覆盖
 * Algorithm: 贪心算法·活动安排与右端点排序 (Activity Selection & Right-Endpoint Greedy)
 * Standard: C++11 (CCF GESP 五级 / CSP-J 官方规范)
 * Blog: https://www.coderli.com/gesp-5-luogu-p1803/
 * Author: OneCoder
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 比赛总数 n 最大可达 10^6，大数组必须声明在全局静态存储区（BSS 段），避免 main 函数栈溢出
const int MAXN = 1000005;

// 定义结构体存储每场比赛的开始时间与结束时间
struct Contest {
    int l; // 比赛开始时间 a_i
    int r; // 比赛结束时间 b_i
};

Contest c[MAXN];

/**
 * 自定义比较函数：按比赛结束时间 r 从小到大升序排序
 * 若结束时间相同，则按开始时间 l 从小到大排序
 * 严格遵循 C++ STL 严格弱序 (Strict Weak Ordering) 规范，绝不使用 <=
 */
bool cmp(const Contest& x, const Contest& y) {
    if (x.r != y.r) {
        return x.r < y.r;
    }
    return x.l < y.l;
}

int main() {
    int n;
    // 读取比赛总数 n
    cin >> n;

    // 依次读取 n 场比赛的开始时间和结束时间（下标从 1 到 n）
    for (int i = 1; i <= n; ++i) {
        cin >> c[i].l >> c[i].r;
    }

    // 第一步：将所有比赛按照结束时间从早到晚升序排序
    sort(c + 1, c + n + 1, cmp);

    // 第二步：线性扫描，贪心选择每一个不冲突且最早结束的比赛
    int ans = 0;        // 统计最多能参加的比赛数目
    int last_end = -1;  // 记录上一场已选比赛的结束时间，因 0 <= a_i，初始设为 -1

    for (int i = 1; i <= n; ++i) {
        // 如果当前第 i 场比赛的开始时间不早于上一场已选比赛的结束时间（端点重合如 [0,2] 与 [2,4] 互不冲突）
        if (c[i].l >= last_end) {
            ans++;              // 决定参加这场最早结束的合法比赛
            last_end = c[i].r;  // 更新时间轴的占用右边界为当前比赛的结束时间
        }
    }

    // 输出最多能参加的比赛数目
    cout << ans << "\n";

    return 0;
}
