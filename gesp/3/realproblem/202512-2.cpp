#include <algorithm>
#include <iostream>
#include <vector>

/**
 * GESP 2025年12月 三级编程题 T2: 小杨的智慧购物
 *
 * 题目核心：
 * 1. 小杨需要购买 M 种文具。
 * 2. 商店里共有 N 件文具，每件都有种类 K 和价格 P。
 * 3. 策略：对于每种文具，只购买最便宜的那一件。
 * 4. 目标：计算买齐这 M 种文具需要的最小总花费。
 *
 * 算法思路：
 * 1. 使用一个数组（或 vector） min_prices 来记录每种文具当前发现的最低价格。
 *    数组大小设为 M +
 * 1，初始值设为一个很大的数（无穷大），表示尚未找到该类文具。
 * 2. 遍历输入的 N 件文具：
 *    - 读取当前文具的种类 k 和价格 p。
 *    - 尝试更新第 k 种文具的最低价格：min_prices[k] = min(min_prices[k], p)。
 * 3. 遍历完所有文具后，将 1 到 M 种文具的最低价格累加，即为结果。
 */

const int INF = 1000000000;  // 定义无穷大

int main() {
    int m, n;
    // 读取种类数 M 和总文具数 N
    std::cin >> m >> n;

    // 创建 min_prices 数组，大小为 M + 1，初始化为 INF
    // 下标 1 代表第 1 种文具，依此类推
    std::vector<int> min_prices(m + 1, INF);

    for (int i = 0; i < n; i++) {
        int k, p;
        // 读取每件文具的种类和价格
        std::cin >> k >> p;

        // 如果当前这件文具的价格比之前记录的第 k 种文具的最低价还低，则更新
        if (p < min_prices[k]) {
            min_prices[k] = p;
        }
    }

    int total_cost = 0;
    // 累加所有种类文具的最低价格
    for (int i = 1; i <= m; i++) {
        total_cost += min_prices[i];
    }

    // 输出总花费
    std::cout << total_cost << std::endl;

    return 0;
}
