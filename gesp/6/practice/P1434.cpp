/**
 * 题目: 【GESP/CSP练习】GESP六级 / CSP-J 题解：luogu-P1434 [SHOI2002] 滑雪
 * 题号: P1434
 * 归属: GESP六级 / CSP-J
 * 博客: https://www.coderli.com/gesp-6-luogu-p1434-skiing-memo/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

using namespace std;

// 网格最大规模为 100 x 100，预留边界安全裕量
const int MAXN = 105;

// 网格规模：R 行 C 列
int R, C;

// 存储每个网格点的高度数值
int h[MAXN][MAXN];

// 记忆化数组：f[x][y] 表示从坐标 (x, y) 出发能够滑行的最长滑坡长度
// 全局初始化为 0，表示该格点的最长长度尚未被计算
int f[MAXN][MAXN];

// 四联通方向增量数组：上、下、左、右
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

/**
 * 记忆化搜索核心函数 dfs(x, y)
 * 计算并返回以坐标 (x, y) 为起点的最长滑行长度
 */
int dfs(int x, int y) {
    // 1. 记忆化剪枝：如果当前坐标已经计算过最优解，O(1) 直接返回缓存值
    if (f[x][y] > 0) {
        return f[x][y];
    }

    // 2. 基础状态：任何一个点即使无法向外滑行，其自身的滑坡长度也至少为 1
    f[x][y] = 1;

    // 3. 遍历上、下、左、右四个相邻方向
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 边界安全检查：保证相邻坐标位于网格内部 [1, R] 与 [1, C]
        if (nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
            // 物理滑行规则：只能从高处向低处滑行（高度严格单调递减）
            if (h[nx][ny] < h[x][y]) {
                // 状态转移：当前最长路径 = max(当前长度, 1 + 从较低相邻点出发的最长路径)
                f[x][y] = max(f[x][y], 1 + dfs(nx, ny));
            }
        }
    }

    // 4. 返回计算好的最长路径长度
    return f[x][y];
}

int main() {
    // 读取区域行数 R 与列数 C
    cin >> R >> C;

    // 读入二维高度矩阵
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> h[i][j];
            f[i][j] = 0; // 初始化记忆化数组为 0
        }
    }

    int ans = 0;

    // 遍历整个网格中的每一个格子，分别以其作为起点求解最长滑坡，取全局最大值
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            ans = max(ans, dfs(i, j));
        }
    }

    // 输出整个区域中最长滑坡的长度
    cout << ans << "\n";

    return 0;
}
