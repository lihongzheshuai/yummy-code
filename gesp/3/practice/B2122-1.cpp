/**
 * 题目: 【GESP】C++三级练习 luogu-B2122 单词翻转
 * 题号: B2122
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b2122/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>
#include <sstream>

int main() {
    // 定义字符串变量存储输入的句子
    std::string str;
    // 读取一整行输入
    std::getline(std::cin, str);
    // 创建字符串流，用于分割单词
    std::stringstream ss(str);
    // 定义字符串变量存储每个单词
    std::string token;
    // 使用getline按空格分割字符串流中的单词
    while (std::getline(ss, token, ' ')) {
        // 将每个单词翻转
        reverse(token.begin(), token.end());
        // 输出翻转后的单词
        std::cout << token << std::endl;
    }
    return 0;
}
