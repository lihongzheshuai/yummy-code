/**
 * 题目: 【GESP】C++三级练习 luogu-B2116 加密的病历单
 * 题号: B2116
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2116/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cctype>    // 包含字符处理相关函数，如islower、isupper等
#include <iostream>  // 包含输入输出流
#include <string>    // 包含字符串类
#include <algorithm> // 包含算法库，使用reverse函数

int main() {
    // 声明字符串变量用于存储输入
    std::string input;
    // 从标准输入读取加密字符串
    std::cin >> input;

    // 第一步：大小写反转
    // 遍历字符串中的每个字符
    for (int i = 0; i < input.length(); i++) {
        // 如果是小写字母，转换为大写
        if (std::islower(input[i])) {
            input[i] = std::toupper(input[i]);
        }
        // 如果是大写字母，转换为小写
        else if (std::isupper(input[i])) {
            input[i] = std::tolower(input[i]);
        }
    }

    // 第二步：字符串逆序
    // 使用algorithm库中的reverse函数将字符串整体反转
    std::reverse(input.begin(), input.end());

    // 第三步：字母表循环左移三位解密
    // 遍历字符串中的每个字符
    for (int i = 0; i < input.length(); i++) {
        // 处理特殊情况：x、y、z需要循环到a、b、c
        if (input[i] == 'x') {
            input[i] = 'a';
        } else if (input[i] == 'y') {
            input[i] = 'b';
        } else if (input[i] == 'z') {
            input[i] = 'c';
        }
        // 处理特殊情况：X、Y、Z需要循环到A、B、C
        else if (input[i] == 'X') {
            input[i] = 'A';
        } else if (input[i] == 'Y') {
            input[i] = 'B';
        } else if (input[i] == 'Z') {
            input[i] = 'C';
        } else {
            // 其他字母向后移动3位
            // ASCII码值加3实现字母表右移三位
            input[i] = input[i] + 3;
        }
    }

    // 输出解密后的结果
    std::cout << input;
    return 0;
}
