/**
 * 题目: 【CSP】CSP-J 2023真题 | 公路 luogu-P9749 （适合GESP四级及以上考生练习）
 * 题号: P9749
 * 归属: GESP4级
 * 博客: https://www.coderli.com/csp-j-2023-p9749-road/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // 优化输入输出流性能
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long d;
    std::cin >> n >> d;

    // v[i] 表示第 i 个站点与第 i + 1 个站点之间的距离
    std::vector<long long> v(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> v[i];
    }

    // a[i] 表示第 i 个站点的油价
    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    long long ans = 0;             // 累计总花费
    long long leftover_dist = 0;   // 剩余油量可行驶的距离
    long long cur_min_price = a[1]; // 当前遇到的最低油价

    for (int i = 1; i < n; ++i) {
        // 如果剩余的油不够行驶到下一个站点，则在最低价站点加油
        if (leftover_dist < v[i]) {
            long long needed_dist = v[i] - leftover_dist;
            // 计算需要购买的整升油量（向上取整）
            long long liters = (needed_dist + d - 1) / d;
            ans += liters * cur_min_price;
            leftover_dist += liters * d;
        }
        // 减去走到下一个站点消耗的距离
        leftover_dist -= v[i];
        // 更新到达下一个站点后的最低油价
        cur_min_price = std::min(cur_min_price, a[i + 1]);
    }

    std::cout << ans << "\n";

    return 0;
}
