/**
 * 题目: 【NOIP】2000真题解析 luogu-P1017 进制转换
 * 题号: P1017
 * 归属: 算法练习
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/noip-2000-luogu-p1017/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

// 数字到字符的映射表，最大处理至36进制 (问题中|R|<=20，这里给全足够)
const std::string P = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// 递归进行进制转换输出
void transform(int n, int r) {
    if (n == 0) {
        return; // 除到商为0，结束递归
    }

    int remain = n % r; // 计算余数
    int quotient = n / r; // 计算商

    // 如果余数小于0，修正为正整数范围 [0, |r|-1]
    if (remain < 0) {
        remain -= r;    // 相当于加上进制数r的绝对值
        quotient++;     // 为了保持等式成立，商加1
    }

    // 递归处理之后的商 (不断往高位递归)
    transform(quotient, r);

    // 递归回溯阶段打出对应位上的字符，巧妙实现倒序输出
    std::cout << P[remain];
}

int main() {
    // 优化输入输出流
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, r;
    // 读取十进制数 n 和负进制数的基数 r
    std::cin >> n >> r;
    std::cout << n << "="; // 输出原始值及等号

    // 特判，如果数字一开始就是 0，结果为 0
    if (n == 0) {
        std::cout << 0;
    } else {
        // 调用递归函数输出进制转换结果
        transform(n, r);
    }

    // 按题目要求的后缀格式输出基数
    std::cout << "(base" << r << ")\n";

    return 0;
}
