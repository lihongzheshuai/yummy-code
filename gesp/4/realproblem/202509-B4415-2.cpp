/**
 * 题目: 【GESP】C++四级真题 luogu-B4415 [GESP202509 四级] 排兵布阵
 * 题号: B4415
 * 归属: GESP4级 (202509认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-4-luogu-b4415/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 存储地图：1 表示可排兵，0 表示不可排兵
int num_ary[15][15];
// 存储二维前缀和，sum_ary[i][j] 表示从 (1,1) 到 (i,j) 矩形区域内所有元素的和
int sum_ary[15][15];
int main() {
    int n, m;
    std::cin >> n >> m; // 读入行数 n 和列数 m

    // 读入地图数据并同时计算二维前缀和
    // 注意：这里下标从 1 开始，便于前缀和计算
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> num_ary[i][j];
            // 二维前缀和计算公式：当前格 = 上方格 + 左方格 - 左上方格(避免重复) + 当前值
            sum_ary[i][j] = sum_ary[i - 1][j] + sum_ary[i][j - 1] - sum_ary[i - 1][j - 1] + num_ary[i][j];
        }
    }

    int max_count = 0; // 记录最大合法矩形中的网格数

    // 枚举矩形左上角 (i,j)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 枚举矩形右下角 (k,l)，要求 k≥i，l≥j
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    // 利用二维前缀和公式计算子矩阵 (i,j) 到 (k,l) 的元素和
                    // 公式：sum(i,j,k,l) = sum[k][l] - sum[k][j-1] - sum[i-1][l] + sum[i-1][j-1]
                    int temp_sum = sum_ary[k][l] - sum_ary[k][j - 1] - sum_ary[i - 1][l] + sum_ary[i - 1][j - 1];

                    // 矩形面积 = 行数 * 列数 = (k-i+1) * (l-j+1)
                    // 如果元素和等于矩形面积，说明矩形内全为 1（每个格子都是 1）
                    if (temp_sum == (k - i + 1) * (l - j + 1)) {
                        // 更新最大合法矩形的面积
                        max_count = std::max(max_count, temp_sum);
                    }
                }
            }
        }
    }

    std::cout << max_count << std::endl; // 输出最大网格数
    return 0;
}
