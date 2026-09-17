/**
 * 题目: 【GESP】C++三级练习 luogu-B2156 最长单词 2
 * 题号: B2156
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2156/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量存储输入的句子
    std::string str;
    // 读取一行输入，包含空格
    getline(std::cin, str);
    // 记录最长单词的长度
    int max_count = 0;
    // 记录当前单词的长度
    int count = 0;
    // 存储最长的单词
    std::string max_str;
    // 遍历字符串，注意减1是为了不处理最后的句点
    for (int i = 0; i < str.size() - 1; i++) {
        // 如果不是空格，说明是单词的一部分
        if (str[i] != ' ') {
            count++;
        } else {
            // 遇到空格，判断当前单词是否为最长单词
            if (count > max_count) {
                // 截取最长单词并保存
                max_str = str.substr(i - count, count);
                max_count = count;
            }
            // 重置当前单词长度计数器
            count = 0;
        }
    }
    // 处理最后一个单词（不包含句点）
    if (count > max_count) {
        max_str = str.substr(str.size() - 1 - count, count);
    }
    // 输出最长的单词
    std::cout << max_str << std::endl;
    return 0;
}
