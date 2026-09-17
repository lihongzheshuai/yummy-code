/**
 * 题目: 【GESP】C++三级练习 luogu-B2110 找第一个只出现一次的字符
 * 题号: B2110
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2110/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量存储输入
    std::string str;
    std::cin >> str;

    // 定义数组记录每个字母出现次数,初始化为0
    int str_ary[26] = {0};
    char idx = 'a';

    // 第一次遍历:统计每个字母出现次数
    for (int i = 0; i < str.size(); i++) {
        str_ary[str[i] - idx]++;
    }

    // 第二次遍历:找到第一个只出现一次的字母
    for (int i = 0; i < str.size(); i++) {
        if (str_ary[str[i] - idx] == 1) {
            std::cout << (char)str[i] << std::endl;
            return 0;
        }
    }

    // 没有只出现一次的字母,输出no
    std::cout << "no";
    return 0;
}
