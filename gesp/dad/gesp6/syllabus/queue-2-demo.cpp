#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int x, y, step;
};

int bfs(vector<vector<int>>& maze) {
    int n = maze.size();     // 行数
    int m = maze[0].size();  // 列数
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<Node> q;
    q.push({0, 0, 0});  // 起点 (0,0) 步数 0
    visited[0][0] = true;

    // 方向数组：右、左、下、上
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        // 到达终点 (右下角)
        if (curr.x == n - 1 && curr.y == m - 1) return curr.step;

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            // 越界与障碍检查
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 &&
                !visited[nx][ny]) {
                visited[nx][ny] = true;           // 标记已访问
                q.push({nx, ny, curr.step + 1});  // 入队，步数+1
            }
        }
    }
    return -1;
}

int main() {
    // 0: 通路, 1: 墙
    vector<vector<int>> maze = {{0, 1, 0, 0, 0},
                                {0, 1, 0, 1, 0},
                                {0, 0, 0, 0, 0},
                                {0, 1, 1, 1, 0},
                                {0, 0, 0, 1, 0}};

    cout << "Min Steps: " << bfs(maze) << endl;  // Output: 8
    return 0;
}