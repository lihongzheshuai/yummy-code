/**
 * 题目: 【GESP】C++二级真题 luogu-B4357 [GESP202506 二级] 幂和数
 * 题号: B4357
 * 归属: GESP2级 (202506认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4357/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

int main() {
    // 定义输入的范围边界
    int l,r;
    // 从标准输入读取 l, r
    std::cin >> l >> r;
    // 计数器，记录幂和数的个数
    int count = 0;
    // 外层循环遍历第一个2的幂次数，最大不超过31（2^31已经超过10^4）
    for (int i = 0; i<=31; i++) {
        // 内层循环从i开始遍历第二个2的幂次数，避免重复计数
        for (int j = i; j<=31; j++) {
            // 计算当前两个2的幂之和
            int num = std::pow(2,i) + std::pow(2,j);
            // 判断和是否在给定范围内
            if (num >= l && num <= r) {
                // 如果在范围内，计数器加1
                count++;
            }
        }
    }
    // 输出结果
    std::cout << count << std::endl;
    return 0;
}
