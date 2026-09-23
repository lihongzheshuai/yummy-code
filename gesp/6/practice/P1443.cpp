/**
 * 题目: 【GESP/CSP练习】GESP六级 / CSP-J 题解：luogu-P1443 马的遍历
 * 题号: P1443
 * 归属: GESP六级 / CSP-J
 * 博客: https://www.coderli.com/gesp-6-luogu-p1443-knight-traversal/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 棋盘最大规模为 400 x 400，预留边界裕量
const int MAXN = 405;

// 马在棋盘上的 8 个移动方向（日字形跳跃）
// 组合分别为：(±2, ±1) 以及 (±1, ±2)
const int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

// 存储马到达棋盘各点的最少步数
// 全局初始化为 -1，兼具“距离存储”与“是否已访问判定”双重功能
int dist[MAXN][MAXN];

// 定义结构体表示棋盘上的坐标点
struct Point {
    int x; // 行坐标 (1 到 n)
    int y; // 列坐标 (1 到 m)
};

int main() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;

    // 初始化整个棋盘的所有格子步数为 -1（表示未访问或不可达）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dist[i][j] = -1;
        }
    }

    // 声明广度优先搜索队列，管理待拓展的棋盘状态
    queue<Point> q;

    // 起点步数设为 0，并将起点坐标推入队列
    dist[sx][sy] = 0;
    Point start;
    start.x = sx;
    start.y = sy;
    q.push(start);

    // 开始 BFS 层次遍历
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 尝试向 8 个日字形方向跳跃拓展
        for (int i = 0; i < 8; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 1. 越界检查：确保新坐标处于 n x m 棋盘内部
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                // 2. 访问检查：若 dist 仍为 -1，说明此前从未被水波纹触及
                if (dist[nx][ny] == -1) {
                    // 记录到达新点的最少步数（当前点步数 + 1）
                    dist[nx][ny] = dist[cur.x][cur.y] + 1;
                    // 将新点加入队列，等待后续继续向外层拓展
                    Point next_point;
                    next_point.x = nx;
                    next_point.y = ny;
                    q.push(next_point);
                }
            }
        }
    }

    // 按照题目要求输出 n x m 的矩阵
    // 每个整数代表马到达该位置的最少步数（无法到达自然输出 -1）
    // 每行数字以空格分隔
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << dist[i][j] << (j == m ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
