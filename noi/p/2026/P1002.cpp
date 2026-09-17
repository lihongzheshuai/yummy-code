/**
 * 题目: 【GESP/CSP练习】GESP六级 / CSP-J 题解：luogu-P1002 [NOIP2002 普及组] 过河卒
 * 题号: P1002
 * 归属: GESP6级
 * 博客: https://www.coderli.com/gesp-5-luogu-p1002-soldier/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu P1002 [NOIP2002 普及组] 过河卒
 * Algorithm: 网格动态规划 / 递推计数
 * Author: OneCoder
 */

#include <iostream>
#include <vector>

using namespace std;

// 马的跳步偏移量：包含马自身位置 (0, 0) 及 8 个日字跳跃方向
const int dx[9] = {0, 1, 1, 2, 2, -1, -1, -2, -2};
const int dy[9] = {0, 2, -2, 1, -1, 2, -2, 1, -1};

// 棋盘最大坐标 20，数组大小开到 25 避免越界
bool blocked[25][25];
long long dp[25][25]; // 核心：必须使用 long long 防止整数溢出

int main() {
    // 基础流加速
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int bx, by, hx, hy;
    if (!(cin >> bx >> by >> hx >> hy)) {
        return 0;
    }

    // 1. 预处理标记马自身位置及其 8 个跳跃控制点
    for (int i = 0; i < 9; ++i) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        // 只有落在棋盘合法范围内的控制点才进行标记
        if (nx >= 0 && nx <= bx && ny >= 0 && ny <= by) {
            blocked[nx][ny] = true;
        }
    }

    // 2. 特殊情况判断：若起点 (0, 0) 本身被马控制，卒根本无法出发
    if (blocked[0][0]) {
        cout << 0 << "\n";
        return 0;
    }

    // 3. 初始化起点状态
    dp[0][0] = 1;

    // 4. 双重循环按拓扑序进行动态规划递推
    for (int i = 0; i <= bx; ++i) {
        for (int j = 0; j <= by; ++j) {
            // 控制点不可踏足，路径数为 0
            if (blocked[i][j]) {
                continue;
            }

            // 从上方单元格转移
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
            // 从左方单元格转移
            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    // 5. 输出到达终点 B 点的路径方案总数
    cout << dp[bx][by] << "\n";

    return 0;
}
