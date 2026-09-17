/**
 * 题目: 【GESP】C++三级练习 luogu-B3654 [语言月赛202208] 影子字符串
 * 题号: B3654
 * 归属: GESP3级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b3654/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串数组用于存储输入的字符串
    std::string str_ary[501];
    // 当前数组索引，初始化为-1
    int cur_idx = -1;
    while (true) {
        // 移动到下一个位置
        cur_idx++;
        // 读入当前字符串
        std::cin >> str_ary[cur_idx];
        // 如果读入"0"，表示输入结束
        if (str_ary[cur_idx] == "0") {
            break;
        }
        // 标记当前字符串是否为影子字符串
        bool is_exist = false;
        // 遍历之前的所有字符串，检查是否存在重复
        for (int i = 0; i < cur_idx; i++) {
            if (str_ary[i] == str_ary[cur_idx]) {
                is_exist = true;
                break;
            }
        }
        // 如果不是影子字符串，直接输出
        if (!is_exist) {
            std::cout << str_ary[cur_idx];
        }
    }
    return 0;
}
