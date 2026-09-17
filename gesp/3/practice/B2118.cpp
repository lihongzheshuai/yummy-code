/**
 * 题目: 【GESP】C++三级练习 luogu-B2118 验证子串
 * 题号: B2118
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2118/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
#include <string>

int main() {
    // 声明两个字符串变量用于存储输入
    std::string str1;
    std::string str2;
    // 使用getline读取两行输入，每行一个字符串
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    // 检查str1是否包含str2
    if (str1.find(str2) != std::string::npos) {
        // 如果str2是str1的子串，按格式输出结果
        printf("%s is substring of %s", str2.c_str(), str1.c_str());
    }
    // 检查str2是否包含str1
    else if (str2.find(str1) != std::string::npos) {
        // 如果str1是str2的子串，按格式输出结果
        printf("%s is substring of %s", str1.c_str(), str2.c_str());
    }
    // 如果两个字符串都不是对方的子串
    else {
        std::cout << "No substring";
    }
    return 0;
}
