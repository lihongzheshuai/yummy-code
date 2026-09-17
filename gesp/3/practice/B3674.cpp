/**
 * 题目: 【GESP】C++三级练习 luogu-B3674 [语言月赛202210] 标题修改
 * 题号: B3674
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b3674/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量存储输入
    std::string str;
    // 读取一整行输入，包含空格
    getline(std::cin, str);
    // idx用于记录每个单词中字母的位置（1开始）
    int idx = 1;
    // 遍历整个字符串
    for (int i = 0; i < str.length(); i++) {
        // 如果当前字符不是空格
        if (str[i] != ' ') {
            // 奇数位置字母转大写
            if (idx % 2 == 1) {
                str[i] = toupper(str[i]);
            }
            // 偶数位置字母转小写
            else {
                str[i] = tolower(str[i]);
            }
            // 单词内字母位置加1
            idx++;
        }
        // 遇到空格，重置单词内字母位置计数
        else {
            idx = 1;
        }
    }
    // 输出处理后的字符串
    std::cout << str;
    return 0;
}
