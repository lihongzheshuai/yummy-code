/**
 * 题目: 【GESP真题】GESP六级 / CSP-J 题解：luogu-P17458 [GESP202609 六级] 分树规划
 * 题号: P17458
 * 归属: GESP6级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-6-luogu-p17458-tree-partition/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-P17458
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 20005;
vector<int> adj[MAXN];
int sz_arr[MAXN];
int n;
int min_diff = 1e9;

// DFS 自底向上统计子树大小
void dfs(int u, int p) {
    sz_arr[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sz_arr[u] += sz_arr[v];
        }
    }
    if (u != 1) {
        int diff = abs(2 * sz_arr[u] - n);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) {
        return 0;
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << min_diff << "\n";

    return 0;
}
