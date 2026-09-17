/**
 * 题目: 【GESP】C++四级真题 luogu-B4264 [GESP202503 四级] 二阶矩阵
 * 题号: B4264
 * 归属: GESP4级 (202503认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b4264/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 定义二维数组存储矩阵元素，最大支持500x500的矩阵
int num_ary[505][505];

int main() {
    // 定义矩阵的行数n和列数m
    int n, m;
    // 读入矩阵的行数和列数
    std::cin >> n >> m;

    // 读入矩阵的所有元素
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> num_ary[i][j];
        }
    }

    // 计数器，用于统计满足条件的2x2子矩阵的个数
    int count = 0;

    // 遍历所有可能的2x2子矩阵左上角位置
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            // 判断当前2x2子矩阵是否满足条件：主对角线元素乘积等于副对角线元素乘积
            if (num_ary[i][j] * num_ary[i+1][j+1] == num_ary[i][j+1] * num_ary[i+1][j]) {
                count++;
            }
        }
    }

    // 输出结果
    std::cout << count;
    return 0;
}
