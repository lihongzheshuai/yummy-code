/**
 * 题目: 【GESP真题】GESP四级 / CSP-J 题解：luogu-B4580 [GESP202609 四级] 有序网格
 * 题号: B4580
 * 归属: GESP4级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4580-ordered-grid/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4580
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    int grid[15][15];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    // 1. 对每一行按升序排序
    for (int i = 0; i < n; ++i) {
        sort(grid[i], grid[i] + m);
    }

    // 2. 对每一列按升序排序
    for (int j = 0; j < m; ++j) {
        vector<int> col(n);
        for (int i = 0; i < n; ++i) {
            col[i] = grid[i][j];
        }
        sort(col.begin(), col.end());
        for (int i = 0; i < n; ++i) {
            grid[i][j] = col[i];
        }
    }

    // 3. 规整输出排序结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << grid[i][j] << (j + 1 == m ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
