#include <climits>
#include <iostream>

// 定义最大矩阵大小，题目中 N <= 120
int a[125][125];
// pre_a[i][j] 表示从 (1,1) 到 (i,j) 的子矩阵元素之和（二维前缀和）
int pre_a[125][125];

int main() {
    int n;
    std::cin >> n;
    // 读取矩阵并计算二维前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> a[i][j];
            // 二维前缀和公式：当前元素 + 上方区域 + 左方区域 - 左上重叠区域
            pre_a[i][j] = a[i][j] + pre_a[i - 1][j] + pre_a[i][j - 1] -
                          pre_a[i - 1][j - 1];
        }
    }

    // 初始化最大和为最小整数
    int max_sum = INT_MIN;

    // 暴力枚举所有可能的子矩阵
    // (i, j) 为子矩阵的左上角坐标
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // (k, l) 为子矩阵的右下角坐标
            for (int k = i; k <= n; k++) {
                // 注意：这里原代码是 l < n，会导致漏掉最后一列，已修正为 l <= n
                for (int l = j; l <= n; l++) {
                    // 利用容斥原理计算子矩阵 (i,j) 到 (k,l) 的和
                    // Sum = pre_a[k][l] - 上方多余 - 左方多余 +
                    // 左上重复减去的部分
                    int cur_sum = pre_a[k][l] - pre_a[i - 1][l] -
                                  pre_a[k][j - 1] + pre_a[i - 1][j - 1];
                    max_sum = std::max(max_sum, cur_sum);
                }
            }
        }
    }
    std::cout << max_sum << std::endl;
    return 0;
}