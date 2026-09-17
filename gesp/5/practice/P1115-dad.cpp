#include <climits>
#include <cmath>
#include <iostream>

// 定义数组用于存储输入数据和前缀和
// 大小设为 200005，满足题目 N <= 200000 的要求
int ary[200005];
int pre_a[200005];

int main() {
    int n;
    std::cin >> n;  // 输入序列长度

    // 输入数据并计算前缀和
    for (int i = 1; i <= n; i++) {
        std::cin >> ary[i];
        if (i == 1) {
            pre_a[i] = ary[i];  // 第一个元素的前缀和就是它本身
        } else {
            pre_a[i] = pre_a[i - 1] +
                       ary[i];  // 后续元素的前缀和 = 前一个前缀和 + 当前元素
        }
    }

    int max_sum = INT_MIN;  // 初始化最大和为最小整数

    // 枚举子段的起点 i
    for (int i = 1; i <= n; i++) {
        // 剪枝优化：
        // 子段和 calculation: sum(i, j) = pre_a[j] - pre_a[i-1]
        // 如果 pre_a[i-1] > 0，那么 pre_a[j] - pre_a[i-1] < pre_a[j] - 0
        // 这意味着以 i 为起点的子段和肯定不如以 1
        // 为起点的子段和（或者其他起点）大 所以如果 pre_a[i-1] > 0，可以跳过以
        // i 为起点的枚举
        if (pre_a[i - 1] > 0) {
            continue;
        }

        // 枚举子段的终点 j
        // 注意：虽然有剪枝，但在最坏情况下（如全负数），时间复杂度仍为
        // O(N^2)，对于 2*10^5 的数据会超时
        for (int j = i; j <= n; j++) {
            int sum = pre_a[j] - pre_a[i - 1];  // 利用前缀和计算子段和
            max_sum = std::max(max_sum, sum);   // 更新最大值
        }
    }

    std::cout << max_sum << std::endl;  // 输出结果
    return 0;
}