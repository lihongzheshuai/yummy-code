/**
 * 题目: 【GESP】C++三级练习 luogu-B2124 判断字符串是否为回文
 * 题号: B2124
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2124/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量用于存储输入
    std::string input;
    // 从标准输入读取字符串
    std::cin >> input;
    // 定义两个指针，分别指向字符串的开始和结束
    int begin = 0;
    int end = input.length() - 1;
    // 从两端向中间遍历比较字符
    while (begin < end) {
        // 如果对应位置的字符不相等，说明不是回文
        if (input[begin] != input[end]) {
            std::cout << "no";
            return 0;
        } else {
            // 字符相等，继续向中间移动
            begin++;
            end--;
        }
    }
    // 所有字符都比较完且相等，是回文
    std::cout << "yes";
    return 0;
}
