/**
 * 题目: 【GESP真题】GESP八级 / CSP-S 题解：luogu-P17461 [GESP202609 八级] 生成树计数
 * 题号: P17461
 * 归属: GESP8级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-8-luogu-p17461-cactus-spanning-tree/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17461
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int MOD = 998244353;

vector<int> adj[MAXN];
int depth_arr[MAXN];
bool visited[MAXN];
long long ans = 1;

void dfs(int u, int p, int d) {
    depth_arr[u] = d;
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (visited[v]) {
            if (depth_arr[v] < depth_arr[u]) {
                // 返祖边：找到一个简单环
                int cycle_len = depth_arr[u] - depth_arr[v] + 1;
                ans = (ans * cycle_len) % MOD;
            }
        } else {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1);

    cout << ans << "\n";

    return 0;
}
