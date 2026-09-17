/**
 * 题目: 【GESP】C++三级真题 luogu-B3957 [GESP202403 三级] 完全平方数
 * 题号: B3957
 * 归属: GESP3级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3957/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

int main() {
    // 读取序列长度
    int n;
    std::cin >> n;

    // 创建数组并读入序列
    int ary[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }

    // 计数器，用于统计满足条件的下标对数量
    int count = 0;

    // 双重循环遍历所有可能的下标对
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 计算两数之和的平方根
            int sqr_i = std::sqrt(ary[i] + ary[j]);
            // 判断两数之和是否为完全平方数
            if (sqr_i * sqr_i == ary[i] + ary[j]) {
                count++;
            }
        }
    }

    // 输出结果
    std::cout << count;
    return 0;
}
