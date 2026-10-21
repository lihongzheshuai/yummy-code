/**
 * Problem: luogu-P1605 迷宫
 * Algorithm: 深度优先搜索与状态回溯 (Depth-First Search & Backtracking on Grid)
 * Standard: C++11 (CCF GESP 五级 / CSP-J 官方规范)
 * Blog: https://www.coderli.com/gesp-5-luogu-p1605/
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

// 迷宫长宽最大为 5，开到 10 预留充足边界
const int MAXN = 10;

int n, m, t;          // 迷宫的行数 n、列数 m、障碍总数 t
int sx, sy, fx, fy;   // 起点坐标 (sx, sy) 与终点坐标 (fx, fy)
int ans = 0;          // 统计从起点到终点的合法方案总数

bool obs[MAXN][MAXN]; // obs[x][y] = true 表示坐标 (x, y) 处有障碍物
bool vis[MAXN][MAXN]; // vis[x][y] = true 表示坐标 (x, y) 在当前路径中已被经过

// 方向偏移量数组：分别对应向上、向下、向左、向右移动一个方格
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/**
 * 深度优先搜索 (DFS) 枚举所有从当前位置 (x, y) 出发到达终点的简单路径
 * @param x 当前所在的行坐标
 * @param y 当前所在的列坐标
 */
void dfs(int x, int y) {
    // 递归终止条件：如果成功到达终点 (fx, fy)，说明找到了一条合法路径
    if (x == fx && y == fy) {
        ans++; // 方案总数加 1
        return;
    }

    // 尝试向上、下、左、右四个相邻方向移动
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 1. 越界检查：新坐标必须在 [1, n] x [1, m] 的迷宫范围内
        if (nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }
        // 2. 合法性检查：新方格不能是障碍物，且在当前路径中未被经过
        if (obs[nx][ny] || vis[nx][ny]) {
            continue;
        }

        // 做出选择：标记新方格 (nx, ny) 为已访问
        vis[nx][ny] = true;

        // 递归深入：从 (nx, ny) 继续向下搜索
        dfs(nx, ny);

        // 状态回溯（撤销选择）：从 (nx, ny) 退回当前格时，恢复其未访问状态，
        // 以便后续其他分支路径可以重新经过该方格
        vis[nx][ny] = false;
    }
}

int main() {
    // 读取迷宫的长 n、宽 m 和障碍总数 t
    cin >> n >> m >> t;

    // 读取起点坐标 (sx, sy) 和终点坐标 (fx, fy)
    cin >> sx >> sy >> fx >> fy;

    // 读取 t 处障碍点的坐标并标记
    for (int i = 1; i <= t; ++i) {
        int ox, oy;
        cin >> ox >> oy;
        obs[ox][oy] = true;
    }

    // 边界防御：如果终点本身就有障碍物，则不可能到达，直接输出 0
    if (obs[fx][fy]) {
        cout << 0 << "\n";
        return 0;
    }

    // 核心初始化（极其重要）：出发前必须先将起点 (sx, sy) 标记为已访问！
    // 否则搜索过程中会走“回头路”再次回到起点，导致路径重复统计（考场常见 70 分陷阱）
    vis[sx][sy] = true;

    // 从起点 (sx, sy) 开始深度优先搜索
    dfs(sx, sy);

    // 输出从起点到终点的方案总数
    cout << ans << "\n";

    return 0;
}
