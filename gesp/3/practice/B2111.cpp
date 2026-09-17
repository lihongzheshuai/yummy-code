/**
 * 题目: 【GESP】C++三级练习 luogu-B2111 基因相关性
 * 题号: B2111
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2111/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义阈值变量
    double level;
    // 定义两个DNA序列字符串
    std::string str_1, str_2;
    // 输入阈值和两个DNA序列
    std::cin >> level >> str_1 >> str_2;
    // 记录相同碱基对的数量
    int same_count = 0;
    // 遍历DNA序列，统计相同碱基对
    for (int i = 0; i < str_1.size(); i++) {
        if (str_1[i] == str_2[i]) {
            same_count++;
        }
    }
    // 计算相同碱基对的比例，与阈值比较并输出结果
    if ((double)same_count / str_1.size() >= level) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}
