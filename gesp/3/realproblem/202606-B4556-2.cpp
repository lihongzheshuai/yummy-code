/**
 * 题目: 【GESP】C++三级真题 luogu-B4556 [GESP202606 三级] 字符转换
 * 题号: B4556
 * 归属: GESP3级 (202606认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4556/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
#include <cctype>

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
        if (isupper(c)) {
            // 大写字母转小写
            std::cout << (char)tolower(c);
        } else if (islower(c)) {
            // 小写字母转大写
            std::cout << (char)toupper(c);
        } else {
            // 数字字符替换为 '*'
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return 0;
}
