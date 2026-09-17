/**
 * 题目: 【GESP】C++五级真题 luogu-P17011 [GESP202606 五级] 晚宴
 * 题号: P17011
 * 归属: GESP5级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-5-luogu-p17011/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <algorithm>

// 辗转相除法（欧几里得算法）求最大公约数
// 原理：gcd(a, b) = gcd(b, a % b)，当 b 为 0 时，gcd 即为 a
// 例如：gcd(35, 3) -> gcd(3, 35%3) -> gcd(3, 2) -> gcd(2, 3%2) -> gcd(2, 1) -> gcd(1, 2%1) -> gcd(1, 0) -> 返回 1
int gcd(int a, int b) {
    while (b != 0) {   // 当 b 不为 0 时，持续迭代
        int t = a % b; // 保存 a 除以 b 的余数
        a = b;         // 用 b 覆盖 a
        b = t;         // 用余数覆盖 b，进入下一轮迭代
    }
    return a; // 当 b 为 0 时，a 就是最大公约数
}

int main() {
    int n;
    std::cin >> n; // 读入菜肴的个数

    int v[1005]; // 存储每道菜肴的美味度，数组开大一点防止越界
    for (int i = 0; i < n; i++) {
        std::cin >> v[i]; // 依次读入每道菜肴的美味度
    }

    int ans = 0; // 用于记录满足互质条件的菜肴对中美味度之和的最大值
    // 双重循环枚举所有不同的菜肴对 (i, j)
    // 内层循环 j 从 i+1 开始，保证每对只枚举一次，避免重复
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 调用 gcd 函数判断两道菜肴的美味度是否互质
            // 互质的定义：两数的最大公约数等于 1
            if (gcd(v[i], v[j]) == 1) {
                // 若互质，用两道菜肴的美味度之和与当前最大值比较，取较大者
                ans = std::max(ans, v[i] + v[j]);
            }
        }
    }

    std::cout << ans << std::endl; // 输出互质菜肴对美味度之和的最大值
    return 0;
}
