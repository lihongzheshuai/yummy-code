/**
 * 题目: 【GESP/CSP练习】GESP七级 / CSP-S 题解：luogu-P3379 【模板】最近公共祖先（LCA）
 * 题号: P3379
 * 归属: GESP七级 / CSP-S / 树论与树上倍增模板题
 * 博客: https://www.coderli.com/gesp-7-luogu-p3379/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 最大节点数量与倍增最大幂次（2^20 > 500000）
const int MAXN = 500005;
const int MAXLOG = 21;

// 邻接表存储树的双向边
vector<int> adj[MAXN];

// depth[i] 记录节点 i 在树中的深度（根节点深度设为 1）
int depth[MAXN];

// parent_node[i][k] 记录节点 i 向上跳 2^k 步所到达的祖先节点编号
int parent_node[MAXN][MAXLOG];

/**
 * 广度优先搜索（BFS）层序遍历预处理深度与倍增祖先表
 * 工程优势：彻底规避极端退化链状树在递归深搜（DFS）下的调用栈溢出（Stack Overflow）风险
 * @param root 树根节点编号
 */
void bfs_init(int root) {
    queue<int> q;
    depth[root] = 1;
    parent_node[root][0] = 0; // 根节点的父节点为 0（虚拟边界）
    q.push(root);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            // 跳过通往直接父节点的反向边
            if (v == parent_node[u][0]) {
                continue;
            }

            depth[v] = depth[u] + 1;
            parent_node[v][0] = u; // v 向上跳 2^0 = 1 步即为直接父节点 u

            // 状态转移递推：跳 2^k 步 = 先跳 2^(k-1) 步，再从该中转点跳 2^(k-1) 步
            for (int k = 1; k < MAXLOG; ++k) {
                parent_node[v][k] = parent_node[parent_node[v][k - 1]][k - 1];
            }

            q.push(v);
        }
    }
}

/**
 * 树上倍增法查询任意两点 u 和 v 的最近公共祖先（LCA）
 * @param u 查询节点编号 1
 * @param v 查询节点编号 2
 * @return 节点 u 与 v 的最近公共祖先节点编号
 */
int query_lca(int u, int v) {
    // 规范化：确保 u 始终为深度更深（或相等）的节点
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    // 第一阶段：深度对齐
    // 利用二进制拆分，从大步长向小步长尝试跳跃，使 u 向上提升至与 v 处于同一深度
    for (int k = MAXLOG - 1; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = parent_node[u][k];
        }
    }

    // 特判边界：若深度对齐后 u 与 v 重合，说明 v 本身就是 u 的祖先
    if (u == v) {
        return u;
    }

    // 第二阶段：同步倍增逼近
    // 从大到小尝试让 u 与 v 同时向上跳跃 2^k 步
    // 若跳跃后的目标节点不相等，说明尚未到达公共祖先或尚未越过 LCA，同步向上跳
    for (int k = MAXLOG - 1; k >= 0; --k) {
        if (parent_node[u][k] != parent_node[v][k]) {
            u = parent_node[u][k];
            v = parent_node[v][k];
        }
    }

    // 循环结束后，u 与 v 恰好停在 LCA 的正下方直接子节点
    // 其直接父节点 parent_node[u][0] 即为所求的最近公共祖先
    return parent_node[u][0];
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    // 读入 n - 1 条无向树边构建邻接表
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 从根节点 s 开始层序遍历初始化
    bfs_init(s);

    // 处理 m 次 LCA 查询
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        cout << query_lca(a, b) << "\n";
    }

    return 0;
}
