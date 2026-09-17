/**
 * 题目: 【GESP】C++三级练习 luogu-B2119 删除单词后缀
 * 题号: B2119
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2119/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量用于存储输入的单词
    std::string str;
    // 从标准输入读取单词
    std::cin >> str;
    // 判断单词是否以"er"或"ly"结尾
    if (str.substr(str.length() - 2, str.length()) == "er" ||
        str.substr(str.length() - 2, str.length()) == "ly") {
        // 如果是，删除最后两个字符并输出
        std::cout << str.substr(0, str.length() - 2) << std::endl;
    }
    // 判断单词是否以"ing"结尾
    else if (str.substr(str.length() - 3, str.length()) == "ing") {
        // 如果是，删除最后三个字符并输出
        std::cout << str.substr(0, str.length() - 3) << std::endl;
    }
    // 如果不是以上任何后缀结尾
    else {
        // 直接输出原单词
        std::cout << str;
    }
    return 0;
}
