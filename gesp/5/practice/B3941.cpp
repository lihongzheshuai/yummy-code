/**
 * 题目: 【GESP】C++五级练习（初等数论考点） luogu-B3941 [GESP样题 五级] 小杨的锻炼
 * 题号: B3941
 * 归属: GESP5级
 * 博客: https://www.coderli.com/gesp-5-luogu-b3941/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>

// 全局数组：存储每位同学的锻炼周期，最多支持 15 人
int nums[15];

// 计算两个正整数的最大公约数（Greatest Common Divisor）
// 采用欧几里得递归算法
long long gcd(long long a, long long b) {
    if (b == 0) {          // 当余数为 0 时，a 即为 gcd
        return a;
    }
    return gcd(b, a % b); // 递归：gcd(a,b) = gcd(b, a mod b)
}

// 计算两个正整数的最小公倍数（Least Common Multiple）
// 利用公式：lcm(a,b) = a*b / gcd(a,b)
// 先取两数较大/较小者，避免乘法溢出
long long lcm(long long a, long long b) {
    long long l = std::max(a, b); // 较大数
    long long s = std::min(a, b); // 较小数
    return l * s / gcd(l, s);    // 返回最小公倍数
}

int main() {
    int n;                     // 同学数量
    std::cin >> n;             // 读入 n
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];   // 读入每位同学的锻炼周期
    }
    // 初始结果设为第一个同学的周期
    long long result = nums[0];
    // 依次与后面同学的周期求 lcm，得到全员同时锻炼的最小天数
    for (int i = 1; i < n; i++) {
        result = lcm(result, nums[i]);
    }
    std::cout << result << std::endl; // 输出答案
    return 0;
}
