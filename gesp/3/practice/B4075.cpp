/**
 * 题目: 【CSP】CSP-X 2018真题 | 11的倍数 luogu-B4075 （适合GESP三级及以上考生练习）
 * 题号: B4075
 * 归属: GESP3级
 * 博客: https://www.coderli.com/csp-x-2018-b4075/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    while (n--) {
        std::string x;
        std::cin >> x;

        int s1 = 0, s2 = 0;
        int len = x.length();

        // 从末尾（个位）向前遍历每一位数字
        for (int i = len - 1; i >= 0; i--) {
            // 计算当前位从右往左数的位置编号（个位为第0位）
            int pos = len - 1 - i;
            // 将字符转换为对应的数字
            int digit = x[i] - '0';

            if (pos % 2 == 0) {
                // 偶数位（个位、百位、万位……）累加到 s1
                s1 += digit;
            } else {
                // 奇数位（十位、千位、十万位……）累加到 s2
                s2 += digit;
            }
        }

        // 判断 s1 和 s2 对 11 取模是否相等
        if (s1 % 11 == s2 % 11) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
