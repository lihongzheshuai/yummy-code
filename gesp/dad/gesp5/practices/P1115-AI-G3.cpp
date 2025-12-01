#include <algorithm>
#include <iostream>
#include <vector>

int a[200005];

int main() {
    int n;
    std::cin >> n;  // 输入序列长度

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 动态规划思想 (Kadane算法)
    // current_sum 相当于 dp[i]，表示以当前元素结尾的最大子段和
    // max_sum 记录全局最大的子段和

    long long current_sum = a[0];
    long long max_sum = a[0];

    for (int i = 1; i < n; ++i) {
        // 核心代码注释：
        // 如果之前的子段和 current_sum >
        // 0，说明它对当前元素有增益，因此将当前元素加入该子段。
        // 否则（current_sum <=
        // 0），之前的子段和对当前元素无增益甚至有负面影响，
        // 所以抛弃之前的子段，从当前元素 a[i] 重新开始计算子段。
        if (current_sum > 0) {
            current_sum += a[i];
        } else {
            current_sum = a[i];
        }

        // 每次更新完 current_sum 后，尝试更新全局最大值 max_sum
        max_sum = std::max(max_sum, current_sum);
    }

    std::cout << max_sum << std::endl;

    return 0;
}
