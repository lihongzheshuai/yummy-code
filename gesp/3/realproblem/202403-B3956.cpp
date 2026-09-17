/**
 * 题目: 【GESP】C++三级真题 luogu-B3956 [GESP202403 三级] 字母求和
 * 题号: B3956
 * 归属: GESP3级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b3956/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

int main() {
    // 定义字符串长度变量n
    int n;
    std::cin >> n;

    // 定义密码字符串变量
    std::string pwd;
    std::cin >> pwd;

    // 定义结果变量，用于累加各字符对应的数值
    int result = 0;

    // 遍历密码字符串的每个字符
    for (int i = 0; i < pwd.length(); i++) {
        // 如果是小写字母，加上字母顺序对应的正整数(a=1,b=2,...)
        if (std::islower(pwd[i])) {
            result += pwd[i] - 'a' + 1;
        }
        // 如果是大写字母，加上ASCII码的负值
        else {
            result -= pwd[i];
        }
    }

    // 输出最终结果
    std::cout << result;
    return 0;
}
