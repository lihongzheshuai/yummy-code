/**
 * 题目: 【GESP】C++三级练习 luogu-B3640 T3 句子反转
 * 题号: B3640
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b3640/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // 用于存储当前读入的单词
    std::string str;
    // 用于存储最终结果字符串
    std::string result;
    // 循环读取输入的单词，直到输入结束
    while(std::cin >> str) {
        // 如果是小写字母开头的单词，将整个单词转换为大写
        if (islower(str[0])) {
            transform(str.begin(), str.end(), str.begin(), ::toupper);
        }
        // 如果是大写字母开头的单词，将整个单词转换为小写
        else if (isupper(str[0])) {
            transform(str.begin(), str.end(), str.begin(), ::tolower);
        }
        // 如果是数字，将数字字符串反转
        else {
            reverse(str.begin(), str.end());
        }
        // 将处理后的单词添加到结果字符串的前面
        result = str + result;
        // 在每个单词前添加空格
        result = " " + result;
    }
    // 输出结果，去掉第一个空格
    std::cout << result.substr(1) << std::endl;
    return 0;
}
