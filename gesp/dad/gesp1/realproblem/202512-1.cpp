#include <cstdio>
#include <iostream>

/**
 * GESP 2025年12月 一级编程题 T1: 小杨的爱心快递
 *
 * 题目核心：
 * 1. 体积计费：运费 = 0.5 * 体积 V
 * 2. 重量计费：
 *    - 重量 G < 300 克，运费为 M
 *    - 重量 G >= 300 克，运费为 N
 * 3. 最终运费：取以上两种计费方式中价格较低的一个
 */

int main() {
    double v, g, m, n;

    // 输入四行，分别是 V, G, M, N
    std::cin >> v >> g >> m >> n;
    // 计算按体积计费的费用
    double price_v = v * 0.5;

    // 计算按重量计费的费用
    double price_g;
    if (g < 300.0) {
        price_g = m;
    } else {
        price_g = n;
    }

    // 最终运费取两者中的最小值
    double result = (price_v < price_g) ? price_v : price_g;

    // 输出结果，保留一位小数
    printf("%.1f\n", result);

    return 0;
}