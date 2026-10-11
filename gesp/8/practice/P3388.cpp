/**
 * 题目: 【GESP/CSP练习】GESP八级 / CSP-S 题解：luogu-P3388 【模板】割点（顶）
 * 题号: P3388
 * 归属: GESP八级 / CSP-S / 高级图论·Tarjan算法求无向图割点
 * 博客: https://www.coderli.com/gesp-8-luogu-p3388/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大顶点数常量定义
const int MAXN = 20005;

// 无向图邻接表
vector<int> adj[MAXN];

// dfn[u]: 记录节点 u 在 DFS 深度优先搜索遍历中的访问时间戳
int dfn[MAXN];

// low[u]: 记录节点 u 及其子树节点通过至多一条返祖边所能追溯到的最小时间戳
int low[MAXN];

// 全局逻辑时间戳递增计数器
int timer = 0;

// is_cut[u]: 标记节点 u 是否为割点，避免同一割点因满足多个子树条件而被重复统计
bool is_cut[MAXN];

/**
 * Tarjan 深度优先遍历算法求无向图割点
 * 
 * @param u 当前正在访问的图节点编号
 * @param fa 当前节点在 DFS 搜索树中的父节点编号（根节点的父节点传入 0）
 */
void tarjan(int u, int fa) {
    // 1. 初始化当前节点的访问时间戳和初始追溯值
    dfn[u] = low[u] = ++timer;
    int children = 0; // 记录节点 u 在 DFS 搜索树中的直接子树分支数量

    // 2. 遍历节点 u 的所有邻接边
    for (size_t i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];

        // 忽略直接通往父节点的反向边
        if (v == fa) {
            continue;
        }

        if (!dfn[v]) {
            // 情况 A: 邻接节点 v 尚未被访问，(u, v) 为 DFS 搜索树上的树边 (Tree Edge)
            children++;
            tarjan(v, u);

            // 回溯时，利用子节点 v 的追溯能力更新当前节点 u 的追溯值
            low[u] = min(low[u], low[v]);

            // 判断非根节点是否为割点:
            // 若子节点 v 无法跨越 u 回溯到 u 的更早祖先 (low[v] >= dfn[u])，
            // 则切断 u 后，以 v 为根的子树将无法与外界联通，故 u 是割点
            if (fa != 0 && low[v] >= dfn[u]) {
                is_cut[u] = true;
            }
        } else {
            // 情况 B: 邻接节点 v 已经被访问过，(u, v) 为返祖边 (Back Edge)
            // 更新当前节点能追溯到的最早祖先时间戳
            low[u] = min(low[u], dfn[v]);
        }
    }

    // 判断 DFS 搜索树的根节点是否为割点:
    // 根节点没有祖先节点，当且仅当其在 DFS 树中拥有至少 2 个独立的子树分支时，
    // 移除根节点才会使这些子树分支相互孤立，故当 children >= 2 时根节点为割点
    if (fa == 0 && children >= 2) {
        is_cut[u] = true;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // 读入 m 条无向边并构建邻接表
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 遍历所有节点：图可能由多个不相连的连通分量组成（森林）
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            // 以节点 i 为该连通分量 DFS 树的根节点，父节点设为 0
            tarjan(i, 0);
        }
    }

    // 统计割点总数
    int cut_count = 0;
    for (int i = 1; i <= n; ++i) {
        if (is_cut[i]) {
            cut_count++;
        }
    }

    // 输出第一行：割点总数
    cout << cut_count << "\n";

    // 输出第二行：按节点编号从小到大输出所有割点，用空格分隔
    bool first = true;
    for (int i = 1; i <= n; ++i) {
        if (is_cut[i]) {
            if (!first) {
                cout << " ";
            }
            cout << i;
            first = false;
        }
    }
    if (cut_count > 0) {
        cout << "\n";
    }

    return 0;
}
