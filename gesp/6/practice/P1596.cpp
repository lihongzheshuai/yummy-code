/**
 * Problem: luogu-P1596 [USACO10OCT] Lake Counting S
 * Algorithm: 八方向广度优先搜索与连通块计数 (8-Directional BFS & Connected Components Flood Fill)
 * Standard: C++11 (CCF GESP 六级 / CSP-J 官方规范)
 * Blog: https://www.coderli.com/gesp-6-luogu-p1596/
 * Author: OneCoder
 */

#include <iostream>
#include <queue>

using namespace std;

// 田地规模最大为 100 x 100，开到 105 留出安全余量
const int MAXN = 105;

int n, m;
char grid[MAXN][MAXN]; // 存储田地字符：'W' 表示积水，'.' 表示干地

// 定义结构体表示二维网格坐标
struct Point {
    int x;
    int y;
};

// 八个相邻方向（上、下、左、右、左上、右上、左下、右下）的行、列偏移量
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

/**
 * 从积水点 (sx, sy) 出发，利用广度优先搜索 (BFS) 将同一水塘的所有连通 'W' 抽干为 '.'
 */
void bfs(int sx, int sy) {
    queue<Point> q;

    // 原地修改：在起点入队时立即将 'W' 改为 '.'，兼具“标记已访问”与“防止重复入队”的双重作用
    grid[sx][sy] = '.';
    Point start;
    start.x = sx;
    start.y = sy;
    q.push(start);

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 向周围全部 8 个相邻方向扩展搜索
        for (int i = 0; i < 8; ++i) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            // 1. 边界合法性检查：坐标必须落在 [1, n] x [1, m] 范围内
            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            // 2. 状态检查：仅对尚未处理的积水方格 ('W') 进行扩展
            if (grid[nx][ny] != 'W') {
                continue;
            }

            // 关键：在推入队列前立刻将积水方格原地置为 '.'，杜绝周围其他邻居重复将其入队
            grid[nx][ny] = '.';
            Point next_pt;
            next_pt.x = nx;
            next_pt.y = ny;
            q.push(next_pt);
        }
    }
}

int main() {
    // 读取田地的行数 n 和列数 m
    cin >> n >> m;

    // 逐字符读取 n x m 的田地示意图（cin >> char 会自动跳过换行符与空白符）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }

    int pond_count = 0; // 记录水塘（八连通块）的总数

    // 扫描整片田地：每发现一个未被抽干的 'W'，就找到了一个新的水塘
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] == 'W') {
                pond_count++; // 水塘数量加 1
                bfs(i, j);    // 发起洪水填充，将与 (i, j) 八连通的所有 'W' 全部原地抽干为 '.'
            }
        }
    }

    // 输出水塘总数
    cout << pond_count << "\n";

    return 0;
}
