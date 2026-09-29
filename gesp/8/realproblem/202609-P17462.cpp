/**
 * 题目: 洛谷 P17462 [GESP202609 八级] 末班车
 * 考点: 高级图论 / 逆向Dijkstra / 瓶颈最晚出发时间 / 离线预处理
 * 标准: C++11 (严格遵循 CCF GESP / CSP 规范)
 * 复杂度: 预处理 O(n * m log n)，单次查询 O(1)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 反向图边结构体
// 原图中有向边为 u -> v，反向图中我们记录在 v 的邻接表中，指向起点 u
struct RevEdge {
    int u;          // 原图中的出发站点编号（反向图中的到达站点）
    long long l;    // 该线路原图中的最晚发车时刻
    long long t;    // 该线路行驶所需耗时（分钟）
};

// 定义无穷大常量，表示到达终点自身时无时间上限约束
const long long INF = 2e18;

// max_depart[x][y] 表示从站点 x 出发，能够顺利抵达终点 y 的【最晚允许发车时刻】
// 若无法到达则保持为 -1
long long max_depart[505][505];

int main() {
    // 优化输入输出流性能，应对 50 万次高频查询
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    // rev_adj[v] 存储所有以站点 v 为原图终点的反向边
    vector<vector<RevEdge>> rev_adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long l, t;
        cin >> u >> v >> l >> t;
        // 建立反向边：由终点 v 指向起点 u，携带原始末班时刻 l 和耗时 t
        rev_adj[v].push_back({u, l, t});
    }

    // 初始化全源最晚出发时刻矩阵，初始值全为 -1（表示不可达）
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            max_depart[i][j] = -1;
        }
    }

    // 核心算法：以每个车站 y 为终点，在反向图上分别跑一次【最大化 Dijkstra】
    for (int y = 1; y <= n; ++y) {
        // 优先队列（大根堆）：按最晚允许时刻从大到小贪心拓展
        // pair<时刻, 站点编号>
        priority_queue<pair<long long, int>> pq;

        // 终点到达自身的时刻没有任何限制，置为正无穷 INF
        max_depart[y][y] = INF;
        pq.push({INF, y});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long cur_d = top.first;  // 当前到达站点 v 允许的最晚截止时刻
            int v = top.second;           // 当前中转站点

            // 堆中取出的时刻若劣于已记录的最优解，则跳过无效状态
            if (cur_d < max_depart[v][y]) continue;

            // 遍历所有在原图中进入站点 v 的线路（反向图中的出边）
            for (const auto& edge : rev_adj[v]) {
                int u = edge.u; // 原图线路的始发站

                // 核心松弛逻辑：
                // 要想乘这班车到达 v 且时刻不超过 cur_d：
                // 1. 离开 u 的时刻不能晚于该车末班车：x <= edge.l
                // 2. 离开 u 的时刻加上行驶耗时不能晚于 cur_d：x + edge.t <= cur_d  ==>  x <= cur_d - edge.t
                // 综上，从 u 乘坐该线路出发的最晚合法时刻为两者的最小值
                long long nxt_d = min(edge.l, cur_d - edge.t);

                // 发车时刻必须是非负整数（>= 0），且若算出的时刻比已知的 u 到 y 的最晚时刻更优，则更新松弛
                if (nxt_d >= 0 && nxt_d > max_depart[u][y]) {
                    max_depart[u][y] = nxt_d;
                    pq.push({nxt_d, u});
                }
            }
        }
    }

    // 处理 q 组询问：基于预处理表 O(1) 直接比对
    for (int i = 0; i < q; ++i) {
        int x, y;
        long long s;
        cin >> x >> y >> s;

        // 如果给定的出发时刻 s 小于等于从 x 到 y 的最晚允许发车时刻，则必定可达
        if (s <= max_depart[x][y]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
