/**
 * 题目: 【GESP/CSP练习】GESP七级 / CSP-S 题解：luogu-P3366 【模板】最小生成树
 * 题号: P3366
 * 归属: GESP七级 / CSP-S / 洛谷经典图论模板
 * 博客: https://www.coderli.com/gesp-7-luogu-p3366/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大顶点数与最大边数常量
// 题目给定 N <= 5000, M <= 200000
const int MAXN = 5005;
const int MAXM = 200005;

// 无向边结构体定义
struct Edge {
    int u; // 起始顶点编号
    int v; // 目标顶点编号
    int w; // 边权值
};

// 全局静态边集存储数组
Edge edges[MAXM];

// 并查集父节点索引数组
int fa[MAXN];

// 边的自定义排序规则比较函数：按边权由小到大升序排序
bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

// 并查集查找根节点函数（采用路径压缩优化）
int find_root(int x) {
    if (fa[x] == x) {
        return x;
    }
    // 递归查找根节点并将沿途所有节点的父节点直接指向根节点
    return fa[x] = find_root(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    // 读入 m 条无向边的信息
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // 初始化并查集：每个顶点初始各自为一个独立的连通集合
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
    }

    // 将所有无向边按边权升序进行快速排序
    sort(edges, edges + m, cmp);

    long long total_weight = 0; // 记录最小生成树的所有边权累加和
    int edge_count = 0;         // 记录成功加入最小生成树的边数

    // Kruskal 算法核心贪心避圈选择过程
    for (int i = 0; i < m; ++i) {
        int root_u = find_root(edges[i].u);
        int root_v = find_root(edges[i].v);

        // 若当前边连接的两个顶点不在同一连通块内，则选取该边
        if (root_u != root_v) {
            fa[root_u] = root_v;        // 合并两个连通分量
            total_weight += edges[i].w; // 累加边权
            edge_count++;               // 树边计数自增

            // 当选取的边数恰好达到 n - 1 条时，最小生成树构建完成，提前退出
            if (edge_count == n - 1) {
                break;
            }
        }
    }

    // 若成功选取的边数达到 n - 1 条，则图连通并输出总边权
    // 对于单点图 (n = 1)，所需边数为 0，同样符合条件
    if (edge_count == n - 1) {
        cout << total_weight << endl;
    } else {
        // 否则说明图不连通，按题目要求输出 orz
        cout << "orz" << endl;
    }

    return 0;
}
