/**
 * 题目: 【GESP】C++三级、四级练习 luogu-P2089 烤鸡
 * 题号: P2089
 * 归属: GESP3级
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p2089/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;

int n;
int path[10];           // 记录当前方案的10个配料值
int ans[10000][10];     // 二维数组存储所有方案（最大方案数小于9000）
int total_count = 0;    // 方案计数器

void dfs(int step, int current_sum) {
    if (step == 10) {
        if (current_sum == n) {
            for (int i = 0; i < 10; ++i) {
                ans[total_count][i] = path[i];
            }
            total_count++;
        }
        return;
    }

    // 可行性剪枝
    int rem = 10 - step;
    if (current_sum + rem * 1 > n || current_sum + rem * 3 < n) {
        return;
    }

    for (int w = 1; w <= 3; ++w) {
        path[step] = w; // 覆盖当前位置，无需显式 pop
        dfs(step + 1, current_sum + w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) {
        return 0;
    }

    if (n < 10 || n > 30) {
        cout << 0 << "\n";
        return 0;
    }

    dfs(0, 0);

    cout << total_count << "\n";
    for (int i = 0; i < total_count; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << ans[i][j] << (j == 9 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
