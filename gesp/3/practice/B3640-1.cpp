/**
 * 题目: 【GESP】C++三级练习 luogu-B3640 T3 句子反转
 * 题号: B3640
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b3640/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 用于存储当前读入的单词
    std::string str;
    // 用于存储最终结果
    std::string result;
    // 循环读取输入的单词，直到输入结束
    while(std::cin >> str) {
        // 如果是小写字母开头的单词
        if (str[0] >= 'a' && str[0] <= 'z') {
            // 将小写字母转换为大写字母
            for (int i = 0; i < str.length(); i++) {
                str[i] = str[i] - 'a' + 'A';
            }
            // 将转换后的单词添加到结果字符串的前面
            result = str + result;
        }
        // 如果是大写字母开头的单词
        else if (str[0] >= 'A' && str[0] <= 'Z') {
            // 将大写字母转换为小写字母
            for (int i = 0; i < str.length(); i++) {
                str[i] = str[i] - 'A' + 'a';
            }
            // 将转换后的单词添加到结果字符串的前面
            result = str + result;
        }
        // 如果是数字开头的单词
        else if (str[0] >= '0' && str[0] <= '9') {
            // 将数字字符串反转
            for (int i = 0; i < str.length(); i++) {
                result = str[i] + result;
            }
        }
        // 在每个单词前添加空格
        result = " " + result;
    }
    // 输出结果，去掉第一个空格
    std::cout << result.substr(1) << std::endl;
    return 0;
}
