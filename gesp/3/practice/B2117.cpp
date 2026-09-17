/**
 * 题目: 【GESP】C++三级练习 luogu-B2117 整理药名
 * 题号: B2117
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2117/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cctype>
#include <iostream>
#include <string>

int main() {
    // 读入药品名数量
    int n;
    std::cin >> n;
    // 创建数组存储输入的药品名
    std::string str_ary[n];
    // 读入所有药品名
    for (int i = 0; i < n; i++) {
        std::cin >> str_ary[i];
    }
    // 创建数组存储规范化后的药品名
    std::string out_ary[n];
    // 处理每个药品名
    for (int i = 0; i < n; i++) {
        std::string cur_str = str_ary[i];
        // 如果第一个字符是小写字母，转换为大写
        if (std::islower(cur_str[0])) {
            cur_str[0] = std::toupper(cur_str[0]);
        }
        // 将剩余字符转换为小写
        for (int j = 1; j < cur_str.length(); j++) {
            cur_str[j] = std::tolower(cur_str[j]);
        }
        // 保存规范化后的药品名
        out_ary[i] = cur_str;
    }
    // 输出所有规范化后的药品名
    for (int i = 0; i < n; i++) {
        std::cout << out_ary[i] << std::endl;
    }
    return 0;
}
