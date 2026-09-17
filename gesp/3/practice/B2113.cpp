/**
 * 题目: 【GESP】C++三级练习 luogu-B2113 输出亲朋字符串
 * 题号: B2113
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2113/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量str用于存储输入
    std::string str;
    // 读取一行输入到str
    std::getline(std::cin, str);
    // 创建结果字符串r_str，初始化大小与输入字符串相同，用'\0'填充
    std::string r_str = std::string(str.size(), '\0');
    // 遍历字符串，计算亲朋字符
    for (int i = 0; i < str.size(); i++) {
        if (i == str.size() - 1) {
            // 最后一个字符特殊处理：最后一个字符ASCII值加上第一个字符ASCII值
            r_str[i] = str[str.size() - 1] + str[0];
        } else {
            // 其他位置：当前字符ASCII值加上下一个字符ASCII值
            r_str[i] = str[i] + str[i + 1];
        }
    }
    // 输出结果字符串
    std::cout << r_str;
    return 0;
}
