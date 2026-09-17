/**
 * 题目: 【GESP】C++五级真题（贪心思想考点） luogu-B4051 [GESP202409 五级] 小杨的武器
 * 题号: B4051
 * 归属: GESP5级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-b4051/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int n_c[100005];   // 存储 n 种武器的初始熟练度
int m_a[100005];   // 存储 m 场战斗后武器熟练度的变化值
int main() {
    int n, m;
    std::cin >> n >> m;    // 读入武器种类数 n 和战斗场数 m
    for (int i = 0; i < n; i++) {
        std::cin >> n_c[i]; // 读入每种武器的初始熟练度
    }
    for (int i = 0; i < m; i++) {
        std::cin >> m_a[i]; // 读入每场战斗的熟练度变化值
    }
    int ans = n_c[0]; // 初始假设最大熟练度为第一种武器
    if (n == 1) {
        // 只有一把武器时，所有战斗只能加在这把武器上
        for (int i = 0; i < m; i++) {
            ans += m_a[i];
        }
    } else {
        // 多把武器时，先找出初始熟练度最大的武器
        for (int i = 1; i < n; i++) {
            ans = std::max(ans, n_c[i]);
        }
        // 贪心：把所有正的变化值都加给当前最大熟练度的武器
        for (int i = 0; i < m; i++) {
            if (m_a[i] > 0) {
                ans += m_a[i];
            }
        }
    }
    std::cout << ans; // 输出最终最大熟练度
    return 0;
}
