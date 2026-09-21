/**
 * 题目: 【GESP真题】GESP六级 / CSP-J 题解：luogu-P17458 [GESP202609 六级] 分树规划
 * 题号: P17458
 * 归属: GESP6级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p17458-tree-partition/
 * 算法: 树形结构深度优先搜索 (DFS) / 子树大小统计与极值优化
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 * 作者: OneCoder
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 树的结点最大数量为 20000，数组大小开为 20005 预留空间
const int MAXN = 20005;

// 邻接表存储树的无向边，adj[u] 存储与结点 u 相连的所有邻接结点
vector<int> adj[MAXN];

// sz_arr[u] 存储以结点 u 为根的子树所包含的结点总数（包含 u 本身）
int sz_arr[MAXN];

// 树中结点的总数
int n;

// 记录两个连通块大小之差绝对值的全局最小值
// 初始化为一个极大值（结点数最大为 20000，差值上限不超过 20000）
int min_diff = 1e9;

/**
 * DFS 递归遍历树：自底向上统计每个子树的大小，并更新删边后的最小差值
 * @param u 当前访问的结点编号
 * @param p 当前结点的父结点编号（防止在无向图中反向走回父结点，避免无限循环）
 */
void dfs(int u, int p) {
    // 初始时，以 u 为根的子树至少包含自身这 1 个结点
    sz_arr[u] = 1;

    // 遍历结点 u 的所有邻接邻居
    for (int v : adj[u]) {
        // 若邻居结点不是父结点，则说明 v 是 u 在树中的子结点
        if (v != p) {
            // 递归遍历子结点 v
            dfs(v, u);
            // 递归返回后，子树 v 的大小已统计完毕，自底向上累加至父结点 u
            sz_arr[u] += sz_arr[v];
        }
    }

    // 任意删去一条树边 (u, parent[u])：
    // 整棵树将被分割为两个连通块：以 u 为根的子树（大小为 sz_arr[u]）和其余部分（大小为 n - sz_arr[u]）
    // 注意：根结点 1 没有向上连接的父边，因此排除 u == 1 的情况
    if (u != 1) {
        // 两连通块结点数之差的绝对值为 |sz_arr[u] - (n - sz_arr[u])| = |2 * sz_arr[u] - n|
        int diff = abs(2 * sz_arr[u] - n);
        // 更新全局最小差值
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
}

int main() {
    // 读入结点总数 n
    cin >> n;

    // 树包含 n - 1 条无向边，循环读入每一条边
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // 无向树：两端点互相加入邻接表
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 以结点 1 作为整棵树的根，父结点标记为 0（虚拟根，表示无父结点）
    // 从根结点出发进行一次整树 DFS 遍历
    dfs(1, 0);

    // 输出将树划分为两个连通块时，结点数之差绝对值的最小值
    cout << min_diff << endl;

    return 0;
}
