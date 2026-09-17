/**
 * 题目: 【GESP】C++三级真题 luogu-B4556 [GESP202606 三级] 字符转换
 * 题号: B4556
 * 归属: GESP3级 (202606认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4556/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读入字符个数
    int n;
    std::cin >> n;
    // 读入字符串
    std::string s;
    std::cin >> s;
    // 逐字符判断并转换
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            // 大写字母转小写：ASCII 码加 32
            std::cout << (char)(c + 32);
        } else if (c >= 'a' && c <= 'z') {
            // 小写字母转大写：ASCII 码减 32
            std::cout << (char)(c - 32);
        } else {
            // 数字字符替换为 '*'
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return 0;
}
