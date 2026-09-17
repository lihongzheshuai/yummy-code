/**
 * 题目: 【GESP真题】GESP八级 / CSP-S 题解：luogu-P17462 [GESP202609 八级] 末班车
 * 题号: P17462
 * 归属: GESP8级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-8-luogu-p17462-last-subway/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17462
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct RevEdge {
    int u;
    long long l;
    long long t;
};

const long long INF = 2e18;
long long max_depart[505][505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    if (!(cin >> n >> m >> q)) return 0;

    vector<vector<RevEdge>> rev_adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long l, t;
        cin >> u >> v >> l >> t;
        rev_adj[v].push_back({u, l, t});
    }

    // 初始化全源可达最晚时刻表
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            max_depart[i][j] = -1;
        }
    }

    // 对每个终点 y 跑反向最大化 Dijkstra
    for (int y = 1; y <= n; ++y) {
        priority_queue<pair<long long, int>> pq;
        max_depart[y][y] = INF;
        pq.push({INF, y});

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            long long cur_d = top.first;
            int v = top.second;

            if (cur_d < max_depart[v][y]) continue;

            for (const auto& edge : rev_adj[v]) {
                int u = edge.u;
                long long nxt_d = min(edge.l, cur_d - edge.t);
                if (nxt_d >= 0 && nxt_d > max_depart[u][y]) {
                    max_depart[u][y] = nxt_d;
                    pq.push({nxt_d, u});
                }
            }
        }
    }

    // O(1) 快速回答每个询问
    for (int i = 0; i < q; ++i) {
        int x, y;
        long long s;
        cin >> x >> y >> s;
        if (s <= max_depart[x][y]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
