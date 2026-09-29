/**
 * 题目: 【GESP真题】GESP八级 / CSP-S 题解：luogu-P17461 [GESP202609 八级] 生成树计数
 * 题号: P17461
 * 归属: GESP8级 (202609认证真题)
 * 考点: 仙人掌图性质、DFS 搜索树返祖边环检测、乘法原理
 * 博客: https://www.coderli.com/gesp-8-luogu-p17461-cactus-spanning-tree/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>

using namespace std;

// 常量定义：顶点与边数最大上限 10^5，题目指定的模数 998244353
const int MAXN = 100005;
const int MOD = 998244353;

// 邻接表存图：adj[u] 存储与顶点 u 相邻的所有顶点编号
vector<int> adj[MAXN];

// depth_arr[u] 记录节点 u 在 DFS 搜索树中的深度（根节点深度设为 1）
int depth_arr[MAXN];

// visited[u] 标记节点 u 在深度优先遍历中是否已被访问过
bool visited[MAXN];

// ans 存储生成树总方案数，初始化为 1（若原图无环则答案为 1）
long long ans = 1;

/**
 * 深度优先搜索（DFS）遍历无向图，检测简单环并统计方案数
 * @param u 当前正在访问的节点编号
 * @param p 当前节点在 DFS 搜索树中的直接父节点编号（避免双向边走回头路）
 * @param d 当前节点在 DFS 树中的深度
 */
void dfs(int u, int p, int d) {
    depth_arr[u] = d;     // 记录当前节点的搜索深度
    visited[u] = true;    // 标记当前节点已访问

    // 遍历当前节点 u 的所有相邻邻接点
    for (int v : adj[u]) {
        // 如果邻接点是搜索树上的父节点，说明是同一条无向树边的反向边，直接跳过
        if (v == p) continue;

        if (visited[v]) {
            // 如果邻接点 v 已经被访问过，说明遇到了一条返祖边（Back-edge）
            // 在无向图的 DFS 搜索树中，返祖边一定连接着当前节点与其祖先节点
            // 为避免一条无向边被两端各扫描一次导致重复计算，只在较深的一端（depth[v] < depth[u]）计算环长
            if (depth_arr[v] < depth_arr[u]) {
                // 环上的边数（即环长）等于两端点的深度差加 1
                int cycle_len = depth_arr[u] - depth_arr[v] + 1;
                // 根据乘法原理，消除该环必须且仅能删去环上 1 条边，有 cycle_len 种选择
                ans = (ans * cycle_len) % MOD;
            }
        } else {
            // 邻接点未被访问过，说明 (u, v) 是一条树边，沿着该边继续深入递归
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    int n, m;
    // 读入顶点数 n 和边数 m
    cin >> n >> m;

    // 读入 m 条无向边并构建邻接表
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 从 1 号顶点作为根节点启动 DFS，父节点记为 0，初始深度从 1 开始
    dfs(1, 0, 1);

    // 输出不同生成树的数量对 998244353 取模后的结果
    cout << ans << endl;

    return 0;
}
