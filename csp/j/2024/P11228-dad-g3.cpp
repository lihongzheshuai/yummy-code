#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 定义方向数组：东、南、西、北
// d=0: 东 (x, y+1) -> dx=0, dy=1
// d=1: 南 (x+1, y) -> dx=1, dy=0
// d=2: 西 (x, y-1) -> dx=0, dy=-1
// d=3: 北 (x-1, y) -> dx=-1, dy=0
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;  // 读取地图大小和操作次数

    int x0, y0, d0;
    cin >> x0 >> y0 >> d0;  // 读取初始位置和朝向

    // 使用 vector 存储地图，方便管理内存
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    // 使用 vector<vector<bool>> 记录访问过的位置
    // 初始化为 false，大小为 n 行 m 列
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // 将输入的 1-based 坐标转换为 0-based 坐标
    int x = x0 - 1;
    int y = y0 - 1;
    int d = d0;

    // 标记起始点为已访问
    visited[x][y] = true;
    int count = 1;  // 经过的位置数量，初始位置算 1 个

    // 模拟 k 步操作
    for (int i = 0; i < k; ++i) {
        // 计算按照当前方向 d 走一步后的新坐标
        int nx = x + dx[d];
        int ny = y + dy[d];

        // 检查新坐标是否在地图范围内，且是否是空地
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.') {
            // 如果满足条件，向前移动
            x = nx;
            y = ny;
            // 如果这个位置之前没来过，计数加 1，并标记为已访问
            if (!visited[x][y]) {
                visited[x][y] = true;
                count++;
            }
        } else {
            // 如果不满足条件（越界或有障碍），向右转
            // (d + 1) % 4 可以实现 0->1, 1->2, 2->3, 3->0 的循环
            d = (d + 1) % 4;
        }
    }

    cout << count << endl;
}

int main() {
    // 加速 C++ 标准流 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {  // 读取测试数据组数
        while (t--) {
            solve();
        }
    }

    return 0;
}
