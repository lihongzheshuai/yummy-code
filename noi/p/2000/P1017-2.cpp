/**
 * 题目: 【NOIP】2000真题解析 luogu-P1017 进制转换
 * 题号: P1017
 * 归属: 算法练习
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/noip-2000-luogu-p1017/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
#include <algorithm>

// 数字到字符的映射表
const std::string P = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
    // 优化输入输出流
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, r;
    std::cin >> n >> r;
    std::cout << n << "=";

    if (n == 0) {
        std::cout << 0;
    } else {
        std::string ans = "";
        int temp = n; // 保留原值，用临时变量递推

        // 迭代进行短除法计算
        while (temp != 0) {
            int remain = temp % r;
            int quotient = temp / r;

            // 将负数余数转化为正数，同时商进位
            if (remain < 0) {
                remain -= r;
                quotient++;
            }

            // 把每一位余数映射成对应字符并拼接到字符串中
            ans += P[remain];
            temp = quotient;  // 更新商
        }

        // 短除法得到的是反序的，这里将其翻转为正序（高位在前）
        std::reverse(ans.begin(), ans.end());
        // 输出得到的结果
        std::cout << ans;
    }

    // 输出题目要求的基数格式
    std::cout << "(base" << r << ")\n";

    return 0;
}
