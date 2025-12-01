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
    // pre_a[i] 表示从第 1 个数加到第 i 个数的和
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

    // last_idx 变量的作用：
    // 我们希望找到一个位置 k (k < i)，使得 pre_a[k] 最小。
    // 这样 pre_a[i] - pre_a[k] (即子段和) 就能最大。
    // 这里 last_idx - 1 就代表了这个“最小前缀和”的下标。
    // 初始时 last_idx = 1，即 last_idx - 1 = 0，pre_a[0] = 0。
    int last_idx = 1;

    // 枚举子段的终点 i (从 1 到 n)
    // 注意：i 在这里代表子段的结束位置
    for (int i = 1; i <= n; i++) {
        // 1. 计算以 i 结尾的最大子段和
        //    子段和 = pre_a[i] - pre_a[last_idx - 1]
        //    其中 pre_a[last_idx - 1] 是我们在 i 之前遇到的最小前缀和
        max_sum = std::max(max_sum, pre_a[i] - pre_a[last_idx - 1]);

        // 2. 维护最小前缀和的位置
        //    如果当前的前缀和 pre_a[i] 比我们之前记录的最小前缀和还要小
        //    (或者相等) 那么对于后面 (i+1, i+2...) 的元素来说，减去 pre_a[i]
        //    会得到更大的子段和 所以我们更新 last_idx 为 i + 1 (这样下一次循环
        //    last_idx - 1 就是 i)
        if (pre_a[i] <= pre_a[last_idx - 1]) {
            last_idx = i + 1;
        }
    }

    std::cout << max_sum << std::endl;  // 输出结果
    return 0;
}