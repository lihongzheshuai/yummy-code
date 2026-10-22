/**
 * Problem: luogu-P1162 填涂颜色
 * Algorithm: 广度优先搜索与外围洪水填充 (Breadth-First Search & Outer Boundary Flood Fill)
 * Standard: C++11 (CCF GESP 六级 / CSP-J 官方规范)
 * Blog: https://www.coderli.com/gesp-6-luogu-p1162/
 * Author: OneCoder
 */

#include <iostream>
#include <queue>

using namespace std;

// 方阵规模最大为 30 x 30，开到 35 以便留出一圈 (0 和 n+1) 虚拟外围边框
const int MAXN = 35;

int n;
int grid[MAXN][MAXN]; // 存储方阵数字：0 表示未确定空间，1 表示闭合圈边界
bool vis[MAXN][MAXN]; // vis[x][y] = true 表示坐标 (x, y) 属于闭合圈外部且已被洪水淹没

// 定义结构体表示二维坐标点
struct Point {
    int x;
    int y;
};

// 上、下、左、右四个移动方向的坐标偏移量
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

/**
 * 从虚拟外框起点 (sx, sy) 出发，利用广度优先搜索 (BFS) 标记所有与边界连通的外部 0
 */
void bfs(int sx, int sy) {
    queue<Point> q;

    // 将外围起点标记为已访问并推入队列
    vis[sx][sy] = true;
    Point start;
    start.x = sx;
    start.y = sy;
    q.push(start);

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 向四个方向扩散“洪水”
        for (int i = 0; i < 4; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 1. 边界检查：允许在 [0, n + 1] 的带外框范围内自由流动
            if (nx < 0 || nx > n + 1 || ny < 0 || ny > n + 1) {
                continue;
            }
            // 2. 阻挡与去重检查：遇到闭合圈墙体 (grid == 1) 或已被淹没的格子则跳过
            if (grid[nx][ny] == 1 || vis[nx][ny]) {
                continue;
            }

            // 标记该外部 0 已被洪水触达，并加入队列继续向外扩散
            vis[nx][ny] = true;
            Point next_pt;
            next_pt.x = nx;
            next_pt.y = ny;
            q.push(next_pt);
        }
    }
}

int main() {
    // 读取方阵大小 n
    cin >> n;

    // 读取 n x n 的原始方阵数据（使用 1 到 n 的下标，四周的第 0 行/列和第 n+1 行/列天然保持为 0）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }

    // 逆向思维：从左外侧虚拟起点 (0, 0) 注入洪水，一次性搜遍所有能到达边界的外部 0
    bfs(0, 0);

    // 遍历原方阵 [1, n] x [1, n] 输出涂色后的结果
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 如果原本是 0 且没有被外围洪水淹没 (!vis[i][j])，说明它被锁在闭合圈内部，填涂为 2
            if (grid[i][j] == 0 && !vis[i][j]) {
                cout << 2;
            } else {
                cout << grid[i][j];
            }
            // 同行数字之间用空格分隔，行末直接换行
            if (j < n) {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
