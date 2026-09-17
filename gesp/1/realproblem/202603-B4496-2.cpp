/**
 * 题目: 【GESP】C++一级真题 luogu-B4496, [GESP202603 一级] 数字替换
 * 题号: B4496
 * 归属: GESP1级 (202603认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b4496/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
// 引入 string 头文件，以便使用字符串（三级考纲知识点）
#include <string>

int main() {
    // 声明一个字符串变量用来接收输入
    std::string str;
    std::cin >> str;

    // 利用 for 循环，遍历字符串里的每一个字符。
    // str.length() 函数用来获取字符串一共有多少个字
    for (int i = 0; i < str.length(); ++i) {
        // 如果发现第 i 个位置存放的是字符 '4' (注意单引号)
        if (str[i] == '4') {
            // 直接覆盖为字符 '8'
            str[i] = '8';
        }
    }

    // 重新把字符串输出即可
    std::cout << str << std::endl;

    return 0;
}
