/**
 * 题目: 【GESP】C++三级练习 luogu-B3663 [语言月赛202209] Luogu Academic
 * 题号: B3663
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b3663/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量存储输入
    std::string str;
    // 读取一行输入
    getline(std::cin, str);
    // 计数器，记录"luogu"出现的次数
    int count = 0;
    // 遍历字符串
    for (int i = 0; i < str.length(); ) {
        // 如果从当前位置开始的5个字符是"luogu"
        if (str.substr(i,5) == "luogu") {
            // 计数器加1
            count++;
            // 跳过这5个字符
            i += 5;
        } else {
            // 否则继续检查下一个字符
            i++;
        }
    }
    // 输出结果
    std::cout << count << std::endl;
    return 0;
}
