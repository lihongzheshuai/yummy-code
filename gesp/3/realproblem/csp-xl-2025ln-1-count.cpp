/**
 * 题目: 【CSP】CSP-XL 2025辽宁复赛真题-第一题, 字符串数数（count）（字符串考点，相当于GESP三级）
 * 题号: 
 * 归属: GESP3级
 * 博客: https://www.coderli.com/csp-xl-2025ln-1-count/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int count_ary[26] = {};          // 初始化26个字母的计数数组，全部置0
int main() {
    freopen("count.in", "r", stdin);   // 重定向标准输入，从文件count.in读取数据
    freopen("count.out", "w", stdout); // 重定向标准输出，结果写入count.out
    std::string str;                   // 存储输入的字符串
    std::cin >> str;                   // 读取字符串
    // 遍历字符串，统计每个小写字母出现次数
    for (int i = 0; i < str.length(); i++) {
        count_ary[str[i] - 'a']++;     // 将字符映射到0~25，对应计数器加1
    }
    // 按字母顺序输出26个计数，每行一个
    for (int i = 0; i < 26; i++) {
        std::cout << count_ary[i] << "\n";
    }
    return 0;                          // 程序正常结束
}
