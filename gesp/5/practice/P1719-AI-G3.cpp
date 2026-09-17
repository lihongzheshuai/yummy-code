#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * P1719 最大加权矩形
 *
 * 题目描述：
 * 给定一个 N x N 的矩阵，矩阵中的每个元素都有一个整数权值（可能为负）。
 * 需要找到一个子矩形，使得该子矩形内所有元素的和最大。
 *
 * 算法思路：
 * 这是一个经典的二维最大子段和问题。
 * 我们可以将二维问题转化为一维问题来求解。
 *
 * 1. 枚举矩形的上边界 i 和下边界 j (0 <= i <= j < N)。
 * 2. 对于确定的上边界 i 和下边界 j，我们可以将每一列在 [i, j]
 * 行范围内的元素相加， 得到一个一维数组 col_sum。 col_sum[k] 表示第 k 列从第 i
 * 行到第 j 行的元素之和。
 * 3. 此时问题转化为：在 col_sum 数组中找到一个连续子数组，使得其和最大。
 *    这正是经典的一维“最大子段和”问题，可以使用动态规划（Kadane算法）在 O(N)
 * 时间内解决。
 *
 * 总体时间复杂度：
 * 枚举 i 和 j 需要 O(N^2) 的时间。
 * 计算 col_sum 并求解一维最大子段和需要 O(N) 的时间。
 * 总时间复杂度为 O(N^3)。
 *
 * 数据范围：N <= 120，O(N^3) 约为 1.7 * 10^6，完全可以在 1 秒内通过。
 */

// 定义最大 N，稍微大一点以防万一
const int MAXN = 125;
int matrix[MAXN][MAXN];
// 用于存储压缩后的一维数组
int col_sum[MAXN];

int main() {
    // 优化输入输出效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // 读取矩阵数据
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int max_rect_sum = INT_MIN;

    // 枚举上边界 i
    for (int i = 0; i < n; ++i) {
        // 每次更换上边界时，清空 col_sum 数组
        // col_sum[k] 将存储从第 i 行到第 j 行，第 k 列的元素和
        fill(col_sum, col_sum + n, 0);

        // 枚举下边界 j，从 i 开始向下延伸
        for (int j = i; j < n; ++j) {
            // 将第 j 行的元素累加到 col_sum 中
            // 这样 col_sum[k] 就代表了 matrix[i...j][k] 的和
            for (int k = 0; k < n; ++k) {
                col_sum[k] += matrix[j][k];
            }

            // 在当前的一维数组 col_sum 中寻找最大子段和 (Kadane 算法)
            int current_sum = 0;
            int max_sub_sum = INT_MIN;

            for (int k = 0; k < n; ++k) {
                // 如果当前累加和小于
                // 0，则重新开始计算，因为负数只会拉低后面的和
                // 注意：如果全为负数，Kadane算法的标准形式可能返回0或最大负数，
                // 这里我们希望至少选一个数，所以稍微调整一下逻辑
                if (current_sum < 0) {
                    current_sum = col_sum[k];
                } else {
                    current_sum += col_sum[k];
                }

                if (current_sum > max_sub_sum) {
                    max_sub_sum = current_sum;
                }
            }

            // 更新全局最大矩形和
            if (max_sub_sum > max_rect_sum) {
                max_rect_sum = max_sub_sum;
            }
        }
    }

    cout << max_rect_sum << endl;

    return 0;
}
// -AI-G3
