/**
 * 题目: 【GESP】C++五级真题（数论-素数思想考点） luogu-P10720 [GESP202406 五级] 小杨的幸运数字
 * 题号: P10720
 * 归属: GESP5级 (202406认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p10720/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;                       // 读入待检测的正整数个数

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;                   // 读入当前待检测的正整数
        int count = 0;                   // 记录不同质因子的个数
        // 试除法枚举可能的质因子，只需到 sqrt(a)
        for (int j = 2; j <= sqrt(a); j++) {
            if (a % j == 0) {            // j 是 a 的一个质因子
                count++;                 // 发现新的质因子
            }
            // 将 a 中所有 j 因子全部除掉，避免重复计数
            while (a % j == 0) {
                a /= j;
            }
            // 提前退出：已经超过两种质因子，必定不是幸运数字
            if (count > 2) {
                break;
            }
        }
        // 若剩余 a>1，则剩下的 a 本身也是一个质因子
        if (a > 1) {
            count++;
        }
        // 恰好两种不同质因子则输出 1，否则输出 0
        std::cout << (count == 2 ? 1 : 0) << std::endl;
    }

    return 0;
}
