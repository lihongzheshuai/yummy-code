/**
 * 题目: 【GESP】C++三级练习 luogu-P1597 语句解析-系列题目1
 * 题号: P1597
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1597-1/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

// 引入输入输出流库，用于控制台输入输出
#include <iostream>
// 引入string库，用于字符串处理
#include <string>
// 引入字符处理库，用于isdigit等字符判断函数
#include <cctype>

int main() {
    // 定义输入字符串变量
    std::string str;
    std::cin >> str;

    // 初始化三个变量a,b,c的值为0
    int a = 0, b = 0, c = 0;
    // 用于存储当前正在处理的变量名
    std::string v_name = "";

    // 遍历输入字符串的每个字符
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '=') {  // 遇到等号，开始处理赋值操作
            if (isdigit(str[i + 1])) {  // 如果等号后是数字
                // 根据变量名将数字赋值给对应变量
                if (v_name == "a") {
                    a = str[i + 1] - '0';  // 将数字赋值给变量a
                } else if (v_name == "b") {
                    b = str[i + 1] - '0';  // 将数字赋值给变量b
                } else {
                    c = str[i + 1] - '0';  // 将数字赋值给变量c
                }
            } else {  // 如果等号后是变量
                // 处理变量间的赋值
                if (str[i + 1] == 'a') {  // 将a的值赋给其他变量
                    if (v_name == "b") {
                        b = a;  // 将变量a的值赋给变量b
                    }
                    if (v_name == "c") {
                        c = a;  // 将变量a的值赋给变量c
                    }
                } else if (str[i + 1] == 'b') {  // 将b的值赋给其他变量
                    if (v_name == "a") {
                        a = b;  // 将变量b的值赋给变量a
                    }
                    if (v_name == "c") {
                        c = b;  // 将变量b的值赋给变量c
                    }
                } else {  // 将c的值赋给其他变量
                    if (v_name == "b") {
                        b = c;  // 将变量c的值赋给变量b
                    }
                    if (v_name == "a") {
                        a = c;  // 将变量c的值赋给变量a
                    }
                }
            }
            i += 2;  // 跳过等号和赋值内容
        } else {
            // 记录当前处理的变量名
            if (str[i] != ':') {
                v_name = str[i];  // 存储变量名（a、b或c）
            } else {
                continue;  // 跳过冒号
            }
        }
    }

    // 按要求格式输出三个变量的最终值
    std::cout << a << " " << b << " " << c;
    return 0;
}
