/**
 * 题目: 【GESP】C++三级练习 luogu-B2120 单词的长度
 * 题号: B2120
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2120/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量用于存储输入的单词序列
    std::string str;
    // 使用getline读取一整行输入，包含空格
    std::getline(std::cin, str);
    // 获取字符串长度
    int length = str.length();
    // flag用于标记是否是第一个输出的数字
    bool flag = true;
    // count用于统计当前单词的长度
    int count = 0;
    // 遍历字符串的每个字符
    for (int i = 0; i < length; i++) {
        // 如果当前字符是空格
        if (str[i] == ' ') {
            // 如果count为0说明是连续空格，直接跳过
            if (count == 0) {
                continue;
            } else {
                // 如果是第一个数字，直接输出
                if (flag) {
                    std::cout << count;
                    flag = false;
                } else {
                    // 如果不是第一个数字，需要先输出逗号
                    std::cout << "," << count;
                }
                // 重置单词长度计数器
                count = 0;
            }

        } else {
            // 如果不是空格，单词长度加1
            count++;
        }
    }
    // 输出最后一个单词的长度
    std::cout << "," << count;
    return 0;
}
