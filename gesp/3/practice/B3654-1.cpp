/**
 * 题目: 【GESP】C++三级练习 luogu-B3654 [语言月赛202208] 影子字符串
 * 题号: B3654
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b3654/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 当前读入的字符串
    std::string cur_str;
    // 存储非影子字符串的数组
    std::string str_ary[500];
    // 最终结果字符串
    std::string result_str;
    // 当前数组索引
    int cur_idx = 0;

    // 循环读入字符串直到遇到"0"
    while (true) {
        std::cin >> cur_str;
        // 遇到"0"时退出循环
        if (cur_str == "0") {
            break;
        }

        // 标记当前字符串是否已存在
        bool is_exist = false;
        // 遍历已存储的字符串检查是否重复
        for (int i = 0; i < cur_idx; i++) {
            if (str_ary[i] == cur_str) {
                is_exist = true;
                break;
                ;
            }
        }

        // 如果是非影子字符串则存储
        if (!is_exist) {
            str_ary[cur_idx] = cur_str;
            cur_idx++;
        }
    }

    // 按顺序输出所有非影子字符串
    for (int i = 0; i < cur_idx; i++) {
        std::cout << str_ary[i];
    }
    return 0;
}
