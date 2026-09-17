#include <iostream>
#include <string>

/**
 * GESP 2025年12月 三级编程题 T1: 密码强度
 * 
 * 题目核心：
 * 判断一个密码字符串是否同时满足以下三个条件：
 * 1. 长度至少包含 8 个字符。
 * 2. 至少包含一个大写字母 (A-Z)。
 * 3. 至少包含一个数字 (0-9)。
 * 
 * 如果都满足输出 'Y'，否则输出 'N'。
 */

int main() {
    int t;
    std::cin >> t; // 读取测试数据组数

    while (t--) {
        std::string s;
        std::cin >> s; // 读取密码字符串

        // 条件 1: 长度检查
        if (s.length() < 8) {
            std::cout << "N" << std::endl;
            continue; // 如果长度不够，直接输出 N 并处理下一组
        }

        bool has_upper = false; // 是否有大写字母
        bool has_digit = false; // 是否有数字

        // 遍历字符串检查字符类型
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                has_upper = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                has_digit = true;
            }
        }

        // 条件 2 & 3: 必须同时包含大写字母和数字
        if (has_upper && has_digit) {
            std::cout << "Y" << std::endl;
        } else {
            std::cout << "N" << std::endl;
        }
    }

    return 0;
}