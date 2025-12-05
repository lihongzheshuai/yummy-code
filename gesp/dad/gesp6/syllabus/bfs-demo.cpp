#include <iostream>
#include <queue>  // BFS 核心数据结构：队列
#include <vector>

const int MAX_N = 1005;  // 最大节点数，根据题目范围设定
bool visited[MAX_N];     // 访问标记数组：visited[i] = true 表示节点 i 已被访问
std::vector<int> adj[MAX_N];  // 邻接表：adj[u] 保存节点 u 的所有直接邻居

// 宽度优先搜索函数
void bfs(int start) {
    std::queue<int> q;      // 1. 创建队列
    q.push(start);          // 2. 起点入队
    visited[start] = true;  // 3. 标记起点已访问

    // 4. 当队列不为空时，循环执行
    while (!q.empty()) {
        int u = q.front();  // 5. 取出队首元素（当前要访问的节点）
        q.pop();            // 6. 队首元素出队

        std::cout << u << " ";
        // 在此处进行节点处理逻辑（例如输出、计数、记录路径等）

        // 7. 遍历当前节点 u 的所有相邻节点 v
        for (int v : adj[u]) {
            // 8. 关键判断：只有未被访问过的邻居才入队
            if (!visited[v]) {
                visited[v] = true;  // 9. 标记邻居已访问
                q.push(v);          // 10. 邻居入队，等待后续访问
            }
        }
    }
}

int main() {
    // 构造示例图数据
    // 示例图结构：
    //      1
    //    /   \
    //   2     3
    //  / \     \
    // 4   5 --- 6

    // 添加边 (无向图)
    auto add_edge = [](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 4);
    add_edge(2, 5);
    add_edge(3, 6);
    add_edge(5, 6);  // 添加一条边使图不仅仅是树

    std::cout << "BFS Traversal starting from node 1: ";
    bfs(1);
    std::cout << std::endl;

    return 0;
}