#include <algorithm>
#include <climits>
#include <iostream>

// 定义最大矩阵大小，题目中 N <= 120
int a[125][125];
// col_sum[k] 用于存储压缩后的第 k 列的和
int col_sum[125];

int main() {
    int n;
    std::cin >> n;
    // 读取 N*N 矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
        }
    }

    // 初始化最大和为最小整数，防止全负数情况
    int max_sum = INT_MIN;

    // 枚举矩形的上边界 i
    for (int i = 1; i <= n; i++) {
        // 每次更换上边界时，清空 col_sum 数组
        // 注意：这里需要清空 1 到 n 的范围，所以 fill 的结束迭代器是 col_sum +
        // n + 1
        std::fill(col_sum, col_sum + n + 1, 0);

        // 枚举矩形的下边界 j，从 i 开始向下延伸
        for (int j = i; j <= n; j++) {
            // 将第 j 行的数值累加到 col_sum 中
            // 此时 col_sum[k] 表示第 k 列从第 i 行到第 j 行的元素之和
            // 这一步实现了将二维子矩阵压缩为一维数组
            for (int k = 1; k <= n; k++) {
                col_sum[k] += a[j][k];
            }

            // 对一维数组 col_sum 进行最大子段和计算 (Kadane 算法)
            // cur_sum 记录当前连续子段的和
            int cur_sum = 0;
            for (int k = 1; k <= n; k++) {
                // 如果当前和大于 0，则继续累加，因为对后续有增益
                if (cur_sum > 0) {
                    cur_sum += col_sum[k];
                } else {
                    // 如果当前和小于等于
                    // 0，则丢弃之前的子段，从当前元素重新开始
                    cur_sum = col_sum[k];
                }
                // 更新全局最大和
                max_sum = std::max(max_sum, cur_sum);
            }
        }
    }
    std::cout << max_sum << std::endl;
    return 0;
}