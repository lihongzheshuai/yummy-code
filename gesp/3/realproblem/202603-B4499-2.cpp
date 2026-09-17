/**
 * 题目: 【GESP】C++三级真题 luogu-B4499, [GESP202603 三级] 二进制回文串
 * 题号: B4499
 * 归属: GESP3级 (202603认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4499/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

bool isBinaryPalindromeBitwise(int x) {
    int original = x;  // 记录下它原本的值，等下用来最终比较
    int reversed = 0;  // 用来一点一点组装倒排序后的数字

    while (x > 0) {
        // reversed << 1 表示把已组装的数字整体左移（类似于十进制乘 10）
        // x & 1 取出最低位对应的二进制位（0 或 1，等同于 % 2）
        // | (按位或) 也就是把那一位“拼接”在最低位空白处
        reversed = (reversed << 1) | (x & 1);

        // x >>= 1 表示被取光的最末位可以丢弃了（类似于十进制除 10）
        x >>= 1;
    }

    // 翻转重建后的数如果和原数相等，那就是天然的回文数啦！
    return original == reversed;
}

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (isBinaryPalindromeBitwise(i)) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
