/**
 * 题目: 【GESP】C++三级练习 luogu-B2121 最长最短单词
 * 题号: B2121
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2121/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义输入字符串变量
    std::string str;
    // 读取一整行输入，包含空格
    std::getline(std::cin, str);
    // 获取字符串长度
    int length = str.length();
    // 初始化最大长度和最小长度
    int max_length = 0;
    int min_length = 100;
    // 存储最长和最短单词
    std::string str_max, str_min;
    // 当前单词字符计数
    int count = 0;
    // 遍历字符串的每个字符
    for (int i = 0; i < length; i++) {
        // 遇到分隔符（空格、逗号、句号）时处理当前单词
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.') {
            // 跳过连续的分隔符
            if (count == 0) {
                continue;
            }
            // 更新最长单词
            if (count > max_length) {
                max_length = count;
                str_max = str.substr(i - count, count);
            }
            // 更新最短单词
            if (count < min_length) {
                min_length = count;
                str_min = str.substr(i - count, count);
            }
            // 重置计数器
            count = 0;
        }
        // 处理最后一个字符
        else if (i == length - 1) {
            count++;
            // 更新最长单词
            if (count > max_length) {
                max_length = count;
                str_max = str.substr(i - count + 1, count);
            }
            // 更新最短单词
            if (count < min_length) {
                min_length = count;
                str_min = str.substr(i - count + 1, count);
            }
        }
        // 累加字母计数
        else {
            count++;
        }
    }
    // 输出结果
    std::cout << str_max << std::endl;
    std::cout << str_min << std::endl;
    return 0;
}
