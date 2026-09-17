/**
 * 题目: 【NOIP】1998真题解析 luogu-P1010 幂次方 | GESP四、五级以上可练习
 * 题号: P1010
 * 归属: GESP5级
 * 博客: https://www.coderli.com/noi-p-1998-luogu-p1010/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

// 递归函数，将数字 n 表示为 2 的幂次方形式
void solve(int n) {
    bool first = true; // 标志变量，用于控制 '+' 的输出，确保第一项前没有 '+'
    // n <= 20000，2^14 = 16384 是在范围内的最大 2 的幂，因此从 14 遍历到 0
    for (int i = 14; i >= 0; i--) {
        // 利用位运算判断 n 二进制的第 i 位是否为 1
        if ((n >> i) & 1) {
            // 如果不是按位拆分出来的第一项，则需要输出分隔符 '+'
            if (!first) {
                std::cout << "+";
            }
            first = false; // 当前项处理后，将标志位置为 false

            // 按照题目要求格式处理特殊的指数 0 和 1
            if (i == 0) {
                std::cout << "2(0)"; // 2^0 的情况
            } else if (i == 1) {
                std::cout << "2";    // 2^1 的情况直接输出为 2
            } else {
                // 如果指数 i >= 2，则按规定输出 '2('，并对指数 i 继续递归求解
                std::cout << "2(";
                solve(i);
                std::cout << ")";
            }
        }
    }
}

int main() {
    int n;
    std::cin >> n; // 读取输入的正整数 n

    solve(n);      // 启动递归求解
    return 0;
}
