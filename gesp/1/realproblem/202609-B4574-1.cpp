/**
 * 题目: 【GESP真题】GESP一级题解：luogu-B4574 [GESP202609 一级] 棋盘上的奖赏
 * 题号: B4574
 * 归属: GESP1级 (202609认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4574-chessboard-wheat/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4574 [GESP202609 一级] 棋盘上的奖赏
 * Standard: C++11 (CCF GESP 官方大纲推荐标准)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

int main() {
    // 快速输入输出加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    // total 存储前 n 格麦粒的总数，current 存储当前格的麦粒数
    // 均选用 64 位有符号整型 long long 防范数值溢出
    long long total = 0;
    long long current = 1; // 第 1 格放入 1 粒麦子

    // 单层循环：依次模拟计算第 1 格到第 n 格
    for (int i = 1; i <= n; ++i) {
        total += current;  // 将当前格麦粒累加至总和
        current *= 2;      // 之后每一格都放前一格两倍的麦子
    }

    // 输出总麦粒数
    cout << total << "\n";

    return 0;
}
