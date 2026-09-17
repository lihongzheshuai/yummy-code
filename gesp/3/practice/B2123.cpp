/**
 * 题目: 【GESP】C++三级练习 luogu-B2123 字符串 p 型编码
 * 题号: B2123
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2123/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 用于存储输入的字符串
    std::string str;
    std::cin >> str;

    // 用于存储最终的p型编码结果
    std::string result;

    // 初始化计数器和当前字符
    int cur_count = 1;  // 记录当前字符的连续出现次数
    char cur_char = str[0];  // 记录当前正在统计的字符

    // 从第二个字符开始遍历字符串
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == cur_char) {
            // 如果当前字符与前一个字符相同，计数器加1
            cur_count++;
        } else {
            // 如果遇到不同的字符：
            // 1. 将当前统计结果添加到结果字符串
            // 2. 重置计数器
            // 3. 更新当前字符
            result += std::to_string(cur_count) + cur_char;
            cur_count = 1;
            cur_char = str[i];
        }
    }

    // 处理最后一组字符
    result += std::to_string(cur_count) + cur_char;

    // 输出p型编码结果
    std::cout << result;
    return 0;
}
