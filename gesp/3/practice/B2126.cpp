/**
 * 题目: 【GESP】C++三级练习 luogu-B2126 连续出现的字符
 * 题号: B2126
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2126/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 读取连续出现次数的阈值k
    int k;
    std::cin >> k;

    // 读取待检查的字符串
    std::string str;
    std::cin >> str;

    // 初始化计数器和当前字符
    int count = 1;  // 当前字符的连续出现次数
    char cur_c = str[0];  // 当前正在检查的字符

    // 遍历字符串中的每个字符（从第二个字符开始）
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == cur_c) {
            // 如果当前字符与前一个字符相同，计数器加1
            count++;
        } else {
            // 如果当前字符与前一个字符不同，重置计数器并更新当前字符
            cur_c = str[i];
            count = 1;
        }

        // 检查是否找到符合条件的字符
        if (count >= k) {
            // 找到连续出现k次及以上的字符，输出并结束程序
            std::cout << cur_c << std::endl;
            return 0;
        }
    }

    // 未找到符合条件的字符，输出"No"
    std::cout << "No";
    return 0;
}
