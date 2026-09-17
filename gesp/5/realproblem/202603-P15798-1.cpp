/**
 * 题目: 【GESP】C++五级真题 luogu-P15798, [GESP202603 五级] 有限不循环小数
 * 题号: P15798
 * 归属: GESP5级 (202603认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p15798/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 判断一个数是否为"终止数"
// 核心逻辑：不断除以 2 和 5，看最终能否除尽变成 1
bool isTerminating(int a) {
    // 先把所有的因子 2 除干净
    while (a % 2 == 0) {
        a /= 2;
    }
    // 再把所有的因子 5 除干净
    while (a % 5 == 0) {
        a /= 5;
    }
    // 如果剩下的是 1，说明 a 的质因数只有 2 和 5
    return a == 1;
}

int main() {
    int L, R;
    std::cin >> L >> R;

    int ans = 0; // 用于统计符合要求的"终止数"的个数

    // 从 L 到 R，逐个检验每个数是否为终止数
    for (int i = L; i <= R; i++) {
        if (isTerminating(i)) {
            ans++;
        }
    }

    // 输出最终结果
    std::cout << ans << std::endl;

    return 0;
}
