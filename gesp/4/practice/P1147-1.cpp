/**
 * 题目: 【GESP】C++五级/四级练习（双指针/数学） luogu-P1147 连续自然数和
 * 题号: P1147
 * 归属: GESP4级
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-5-luogu-p1147/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int m;
    std::cin >> m;

    // 双指针初始化
    // l: 区间左端点
    // r: 区间右端点
    // sum: 当前区间 [l, r] 的和
    int l = 1, r = 2;
    long long sum = 3; // 1 + 2 = 3

    // 循环条件：左端点小于中点即可，因为至少两个数
    // 实际上 l < r 也可以作为条件
    while (l <= m / 2) {
        if (sum == m) {
            // 找到一组解，输出
            std::cout << l << " " << r << std::endl;
            // 寻找下一组解，左端点右移
            sum -= l;
            l++;
        } else if (sum < m) {
            // 和太小，右端点右移，增加 sum
            r++;
            sum += r;
        } else {
            // 和太大，左端点右移，减少 sum
            sum -= l;
            l++;
        }
    }

    return 0;
}
