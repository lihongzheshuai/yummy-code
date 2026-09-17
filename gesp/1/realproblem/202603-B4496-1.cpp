/**
 * 题目: 【GESP】C++一级真题 luogu-B4496, [GESP202603 一级] 数字替换
 * 题号: B4496
 * 归属: GESP1级 (202603认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4496/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int A;
    std::cin >> A;

    // 如果输入的本来就是0，里面没有4，直接输出0
    if (A == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 准备一个变量，用来装配替换后的新数字，初始为 0
    int B = 0;

    // 准备一个变量，表示当前的位数（个位是1，十位是10，百位是100）
    int weight = 1;

    // 当 A 还没有被我们剥削干净时，一直循环
    while (A > 0) {
        // 第一步：把 A 当下的个位取出来
        int digit = A % 10;

        // 第二步：判断是不是我们要替换的 4
        if (digit == 4) {
             // 如果是 4，变成了 8（注意这里只改变取出来的值，并未改变原图）
             digit = 8;
        }

        // 第三步：把处理后的数字，根据它原本应该在的位数，拼装给新数字 B
        B = B + digit * weight;

        // 第四步：去掉刚才已经处理完的 A 的个位
        A = A / 10;

        // 第五步：位数权值变大十倍，为下一轮循环处理更高位做准备
        weight = weight * 10;
    }

    // 输出处理好的新数字 B
    std::cout << B << std::endl;

    return 0;
}
