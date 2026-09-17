/**
 * 题目: 【GESP】C++三级练习 luogu-B2109 统计数字字符个数
 * 题号: B2109
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2109/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串变量存储输入
    std::string str;
    // 读取一整行输入到字符串中
    std::getline(std::cin, str);
    // 定义计数器，用于统计数字字符的个数
    int count = 0;
    // 遍历字符串中的每个字符
    for (int i = 0; i < str.size(); i++) {
        // 判断当前字符是否为数字（ASCII码在'0'到'9'之间）
        if (str[i] >= '0' && str[i] <= '9') {
            // 如果是数字字符，计数器加1
            count++;
        }
    }
    // 输出统计结果
    std::cout << count << std::endl;
    // 程序正常结束
    return 0;
}
