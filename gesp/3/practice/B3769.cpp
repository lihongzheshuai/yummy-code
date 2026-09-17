/**
 * 题目: 【GESP】C++三级练习 luogu-B3769 [语言月赛202305] 制糊串
 * 题号: B3769
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b3769/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 声明两个字符串变量s和t用于存储输入的字符串
    std::string s, t;
    // 声明整型变量q用于存储查询次数
    int q;
    // 读取输入的两个字符串和查询次数
    std::cin >> s >> t >> q;

    // 循环处理q次查询
    for (int i = 0; i < q; i++) {
        // 声明四个整型变量用于存储查询的起止位置
        int l1, r1, l2, r2;
        // 读取每次查询的四个位置参数
        std::cin >> l1 >> r1 >> l2 >> r2;

        // 从字符串s中截取子串，注意下标从0开始，所以要减1
        std::string s_sub = s.substr(l1 - 1, r1 - l1 + 1);
        // 从字符串t中截取子串
        std::string t_sub = t.substr(l2 - 1, r2 - l2 + 1);

        // 比较两个子串的字典序
        if (s_sub < t_sub) {
            // s的子串字典序更小
            std::cout << "yifusuyi" << std::endl;
        } else if (s_sub > t_sub) {
            // t的子串字典序更小
            std::cout << "erfusuer" << std::endl;
        } else {
            // 两个子串字典序相等
            std::cout << "ovo" << std::endl;
        }
    }
    return 0;
}
