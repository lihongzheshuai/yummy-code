/**
 * 题目: 【CSP】CSP-J 2021真题 | 分糖果 luogu-P7909 （适合GESP三级及以上考生练习）
 * 题号: P7909
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/csp-j-2021-p7909/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n, L, R;
    std::cin >> n >> L >> R;

    // 步骤 1：判断区间 [L, R] 内部是否有横跨 n 的整倍数的分界点
    // 通过对比最小值和最大值对应 n 的商是否相同即可判断
    if (L / n != R / n) {
        // 如果不一致，说明中间一定有一个时刻余数能够积累到最大值 (n - 1)
        std::cout << n - 1 << std::endl;
    } else {
        // 如果一致，说明整个获取糖果选项都在没跨过分界线的同一周期内
        // 这个周期内获取糖果越多，剩下的自然余数也就越多
        // 所以我们直接取可能范围内最大的值 R，此时对应的余数也是最大
        std::cout << R % n << std::endl;
    }

    return 0;
}
