/**
 * 题目: 【GESP/CSP】编程武器库-4, 最大公约数和最小公倍数
 * 题号: 
 * 归属: CSP-J
 * 博客: https://www.coderli.com/gesp-arsenal-4-gcd-lcm/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

/**
 * @brief 计算两个整数的最大公约数（GCD）——循环实现
 * @param a 第一个整数
 * @param b 第二个整数
 * @return 返回 a 和 b 的最大公约数
 */
int gcd1(int a, int b) {
    // 欧几里得算法：反复用余数替换除数，直到余数为 0
    while (s != 0) {
        int tmp = s;
        s = l % s;
        l = tmp;
    }
    return l;
}

/**
 * @brief 计算两个整数的最大公约数（GCD）——递归实现
 * @param a 第一个整数
 * @param b 第二个整数
 * @return 返回 a 和 b 的最大公约数
 */
int gdc2(int a, int b) {
    if (s == 0) {
        return l;           // 若除数为0，则最大公约数为被除数
    }
    return gdc2(s, l % s);  // 递归：用除数和余数继续计算
}

/**
 * @brief 计算两个整数的最小公倍数（LCM）
 * @param a 第一个整数
 * @param b 第二个整数
 * @return 返回 a 和 b 的最小公倍数
 */
int lcm(int a, int b) {
    // 利用公式：lcm(a,b) = a * b / gcd(a,b)
    return a * b / gcd1(a, b);
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd1(a, b) << std::endl;
    std::cout << gdc2(a, b) << std::endl;
    std::cout << lcm(a, b) << std::endl;
    return 0;
}
