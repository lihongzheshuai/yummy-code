/**
 * 题目: 【GESP/CSP练习】GESP七级 / CSP-S 题解：luogu-P1352 [NOIP2008 提高组] 没有上司的舞会
 * 题号: P1352
 * 归属: GESP七级 / CSP-S / 树形动态规划经典题
 * 博客: https://www.coderli.com/gesp-7-luogu-p1352/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大职员数常量定义，题目中 n <= 6000
const int MAXN = 6005;

// r 数组存储每位职员的快乐指数
int r[MAXN];

// 邻接表存储树形从属关系：tree_edges[k] 存储直接上司 k 的所有直接下属 l
vector<int> tree_edges[MAXN];

// has_parent 标记职员是否有直接上司，用于寻找整棵树的根节点（校长）
bool has_parent[MAXN];

// dp[u][0]: 职员 u 不参加舞会时，以 u 为根的子树所能获得的最大快乐指数
// dp[u][1]: 职员 u 参加舞会时，以 u 为根的子树所能获得的最大快乐指数
int dp[MAXN][2];

/**
 * 深度优先搜索（DFS）后序遍历实现树形动态规划
 * 自底向上：先递归处理所有子节点，再根据子节点的最优状态计算父节点的最优状态
 * @param u 当前访问的节点编号
 */
void dfs(int u) {
    // 基础状态初始化：
    // 若 u 不参加，初始快乐指数为 0
    dp[u][0] = 0;
    // 若 u 参加，初始快乐指数为职员自身的快乐值 r[u]
    dp[u][1] = r[u];

    // 遍历当前节点 u 的所有直接下属 v
    for (int v : tree_edges[u]) {
        // 递归求解子树 v 的最优解
        dfs(v);

        // 状态转移 1：如果直接上司 u 不参加舞会，
        // 则直接下属 v 既可以参加也可以不参加，二者取较大值进行累加
        dp[u][0] += max(dp[v][0], dp[v][1]);

        // 状态转移 2：如果直接上司 u 参加舞会，
        // 则直接下属 v 无论如何都不能参加，只能选择 dp[v][0] 进行累加
        dp[u][1] += dp[v][0];
    }
}

int main() {
    int n;
    cin >> n;

    // 读入每位职员的快乐指数（1 号至 n 号）
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }

    // 读入 n - 1 条从属从属关系边
    // 题目给出每行 l, k，表示 k 是 l 的直接上司，即 k 为父节点，l 为子节点
    for (int i = 1; i < n; ++i) {
        int l, k;
        cin >> l >> k;
        tree_edges[k].push_back(l);
        has_parent[l] = true;
    }

    // 寻找整棵从属树的根节点（校长）
    // 根节点没有直接上司，因此 has_parent[root] 为 false
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (!has_parent[i]) {
            root = i;
            break;
        }
    }

    // 从根节点出发执行树形 DP
    dfs(root);

    // 全局最优解为校长参加与不参加两种情况下的较大值
    cout << max(dp[root][0], dp[root][1]) << endl;

    return 0;
}
