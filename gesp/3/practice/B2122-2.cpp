/**
 * 题目: 【GESP】C++三级练习 luogu-B2122 单词翻转
 * 题号: B2122
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b2122/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <string>
#include <iostream>

int main() {
    // 定义字符串变量存储输入的句子
    std::string str;
    // 读取一整行输入
    std::getline(std::cin, str);
    // 定义字符串变量存储当前处理的单词
    std::string cur_str;
    // 遍历输入的字符串
    for (int i = 0; i < str.length(); i++) {
        // 如果遇到空格，说明一个单词处理完成
        if (str[i] == ' ') {
            // 输出当前已翻转的单词
            std::cout << cur_str << std::endl;
            // 清空当前单词，准备处理下一个
            cur_str = "";
        } else {
            // 将当前字符添加到单词前面，实现翻转效果
            cur_str = str[i] + cur_str;
        }
    }
    // 输出最后一个单词（因为最后一个单词后面没有空格）
    std::cout << cur_str << std::endl;
    return 0;
}
