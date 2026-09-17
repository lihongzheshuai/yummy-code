/**
 * 题目: 【GESP】C++三级真题 luogu-B4499, [GESP202603 三级] 二进制回文串
 * 题号: B4499
 * 归属: GESP3级 (202603认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4499/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int count = 0; // 用于统计回文数的数量

    // 从 1 到 n 挨个检查
    for (int i = 1; i <= n; i++) {
        int x = i;
        int bin[40]; // 准备一个数组用来存放数字的二进制位，10^5 足够用了
        int len = 0; // 记录二进制的位数

        // 不断地进行除 2 取余，将生成的二进制位存入数组
        while (x > 0) {
            bin[len] = x % 2;
            x = x / 2;
            len++;
        }

        // 双指针进行回文判断
        bool is_palindrome = true;
        // j 从 0 开始往后走，k 从末尾往前走，直到两者相遇或者错过
        for (int j = 0, k = len - 1; j < k; j++, k--) {
            if (bin[j] != bin[k]) {
                // 只要有一对不同，这就绝不可能是回文串
                is_palindrome = false;
                break;
            }
        }

        // 如果经受住了所有比对，那就是回文串
        if (is_palindrome) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
