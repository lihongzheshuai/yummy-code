/**
 * 题目: 【GESP】C++三级练习 luogu-B2155 合法 C 标识符
 * 题号: B2155
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2155/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量用于存储输入
    std::string str;
    // 从标准输入读取字符串
    std::cin >> str;

    // 检查首字符是否合法（必须是字母或下划线）
    if (!(str[0] >= 'a' && str[0] <= 'z') &&
        !(str[0] >= 'A' && str[0] <= 'Z') && str[0] != '_') {
        std::cout << "no";
        return 0;
    }

    // 遍历字符串的每个字符
    for (int i = 0; i < str.length(); i++) {
        // 检查每个字符是否为合法字符（数字、字母或下划线）
        if (!(str[i] >= '0' && str[i] <= '9') &&
            !(str[i] >= 'a' && str[i] <= 'z') &&
            !(str[i] >= 'A' && str[i] <= 'Z') && str[i] != '_') {
            std::cout << "no";
            return 0;
        }
    }

    // 所有检查都通过，输出yes
    std::cout << "yes";
    return 0;
}
