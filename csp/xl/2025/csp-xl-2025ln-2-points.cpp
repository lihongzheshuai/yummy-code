/**
 * 题目: 【CSP】CSP-XL 2025辽宁复赛真题-第二题, 积分（points）
 * 题号: 
 * 归属: CSP-J
 * 博客: https://www.coderli.com/csp-xl-2025ln-2-points/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <climits>
#include <iostream>

long long a_array[1005][1005];     // 存放原始二维数组，行列下标从1开始
long long pre_sum[1005][1005];    // 二维前缀和数组，pre_sum[i][j]表示(1,1)到(i,j)子矩阵的和
int main() {
    freopen("points.in", "r", stdin);   // 复赛标准输入文件
    freopen("points.out", "w", stdout); // 复赛标准输出文件
    int n, m, x, y;                     // n行m列，x×x与y×y两种尺寸的正方形区域
    std::cin >> n >> m >> x >> y;
    // 读入原始矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cin >> a_array[i][j];
        }
    }

    // 计算二维前缀和
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] -
                            pre_sum[i - 1][j - 1] + a_array[i][j];
        }
    }

    // 枚举所有x×x正方形区域，求最大积分
    long long max_x_points = LLONG_MIN; // 初始化为最小值
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + x - 1 <= n && j + x - 1 <= m) {
                long long cur_points =
                    pre_sum[i + x - 1][j + x - 1] - pre_sum[i - 1][j + x - 1] -
                    pre_sum[i + x - 1][j - 1] + pre_sum[i - 1][j - 1];
                max_x_points = std::max(max_x_points, cur_points);
            } else {
                break; // 当前行剩余位置无法满足x×x区域，直接跳出内层循环
            }
        }
    }

    // 枚举所有y×y正方形区域，求最大积分
    long long max_y_points = LLONG_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + y - 1 <= n && j + y - 1 <= m) {
                long long cur_points =
                    pre_sum[i + y - 1][j + y - 1] - pre_sum[i - 1][j + y - 1] -
                    pre_sum[i + y - 1][j - 1] + pre_sum[i - 1][j - 1];
                max_y_points = std::max(max_y_points, cur_points);
            } else {
                break; // 同理，提前结束本行后续枚举
            }
        }
    }

    // 输出两种尺寸中的最大积分
    long long max_points = std::max(max_x_points, max_y_points);
    std::cout << max_points << std::endl;
    return 0;
}
