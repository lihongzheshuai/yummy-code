/**
 * 题目: 【GESP真题】GESP一级题解：luogu-B4574 [GESP202609 一级] 棋盘上的奖赏
 * 题号: B4574
 * 归属: GESP1级 (202609认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4574-chessboard-wheat/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;

int main() {
    int n;
    if (cin >> n) {
        // 1LL 表示 64 位 long long 类型的数值 1，左移 n 位即为 2^n
        cout << (1LL << n) - 1 << "\n";
    }
    return 0;
}
