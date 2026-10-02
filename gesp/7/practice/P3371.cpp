/**
 * 题目: 【GESP/CSP练习】GESP七级 / CSP-S 题解：luogu-P3371 【模板】单源最短路径（弱化版）
 * 题号: P3371
 * 归属: GESP七级 / CSP-S / 洛谷经典图论模板
 * 博客: https://www.coderli.com/gesp-7-luogu-p3371/
 * 标准: C++11 (严格遵循 CCF GESP 官方规范)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 题目定义：若不能到达则输出 2^31 - 1
const int INF = 2147483647;

// 最大顶点数量常数，题目给定 n <= 10000
const int MAXN = 10005;

// 有向边结构体
struct Edge {
    int to;     // 目标顶点编号
    int weight; // 边权
};

// 邻接表：adj[u] 存储从顶点 u 出发的所有有向边
vector<Edge> adj[MAXN];

// dist[i] 记录从出发点 s 到顶点 i 的当前最短距离
int dist[MAXN];

// visited[i] 标记顶点 i 的最短路径是否已被最终锁定并出队
bool visited[MAXN];

// 优先队列堆元素定义：pair<当前距离, 顶点编号>
// C++ 的 pair 默认先按 first 比较，若 first 相等再按 second 比较
typedef pair<int, int> PII;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    // 读入 m 条有向边并构建邻接表
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // 初始化所有顶点到源点的距离为无穷大 INF (2^31 - 1)
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }

    // 起点到自身的距离初始化为 0
    dist[s] = 0;

    // 定义小根堆优先队列：距离较小的顶点优先出队
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, s});

    // Dijkstra 核心贪心松弛循环
    while (!pq.empty()) {
        PII cur = pq.top();
        pq.pop();

        int u = cur.second;

        // 若当前顶点已被锁定处理过，跳过冗余的历史入堆记录
        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        // 遍历从当前顶点 u 出发的所有出边进行松弛
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].to;
            int w = adj[u][i].weight;

            // 防溢出松弛判断：若经由 u 前往 v 的路径更短
            // 采用 (long long) 防止 dist[u] + w 超过 32 位整型上限
            if (!visited[v] && (long long)dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // 按题意要求输出从 s 出发到达 1..n 各顶点的最短距离，不能到达输出 2^31 - 1
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}
