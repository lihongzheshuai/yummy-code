#include <iostream>
#include <vector>

const int MAX_N = 1005;  // 最大节点数，根据题目范围设定
bool visited[MAX_N];     // 访问标记数组：visited[i] = true 表示节点 i 已被访问
std::vector<int> adj[MAX_N];  // 邻接表：adj[u] 保存节点 u 的所有直接邻居

// 深度优先搜索函数
void dfs(int u) {
    visited[u] = true;  // 1. 标记当前节点已访问，防止重复访问导致死循环
    std::cout << u << " ";  // 在此处进行节点处理逻辑（例如输出、计数等）

    // 2. 遍历节点 u 的所有相邻节点 v
    // (这里使用了 C++11 的范围 for 循环，等价于遍历 adj[u] 这个向量)
    for (int v : adj[u]) {
        // 3. 关键判断：只有未被访问过的邻居才去访问
        if (!visited[v]) {
            dfs(v);  // 4. 递归调用：这是 DFS 的核心，深入下一层
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

    std::cout << "DFS Traversal starting from node 1: ";
    dfs(1);
    std::cout << std::endl;

    return 0;
}