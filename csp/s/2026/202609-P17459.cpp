/**
 * 题目: 【GESP真题】GESP七级 / CSP-S 题解：luogu-P17459 [GESP202609 七级] 必经之路
 * 题号: P17459
 * 归属: GESP7级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-7-luogu-p17459-must-pass-node/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17459
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> in_deg(n + 1, 0);
    vector<int> out_deg(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        out_deg[u]++;
        in_deg[v]++;
    }

    vector<int> starts;
    vector<bool> is_end(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0) starts.push_back(i);
        if (out_deg[i] == 0) is_end[i] = true;
    }

    vector<int> must_pass;

    // 逐个检验结点 u 是否为必经点
    for (int u = 1; u <= n; ++u) {
        queue<int> q;
        vector<bool> visited(n + 1, false);

        for (int s : starts) {
            if (s != u) {
                visited[s] = true;
                q.push(s);
            }
        }

        bool can_reach_end = false;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (is_end[curr] && curr != u) {
                can_reach_end = true;
                break;
            }

            for (int nxt : adj[curr]) {
                if (nxt != u && !visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }

        if (!can_reach_end) {
            must_pass.push_back(u);
        }
    }

    cout << must_pass.size() << "\n";
    if (!must_pass.empty()) {
        for (size_t i = 0; i < must_pass.size(); ++i) {
            cout << must_pass[i] << (i + 1 == must_pass.size() ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
