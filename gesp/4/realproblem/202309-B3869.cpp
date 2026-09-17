/**
 * 题目: 【GESP】C++四级真题 luogu-B3869 [GESP202309 四级] 进制转换
 * 题号: B3869
 * 归属: GESP4级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-4-luogu-b3869/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>
#include <cmath>

/**
 * 将K进制字符串转换为十进制数
 * @param s K进制字符串，仅包含数字0-9和大写字母A-F
 * @param k 进制基数，范围2-16
 * @return 转换后的十进制数
 */
long long trans_to_decimal(const std::string& s, const int k) {
    // 存储转换后的十进制结果
    long long decimal = 0;

    // 从右向左遍历字符串的每一位
    for (int i = s.length() - 1; i >= 0; i--) {
        // 如果当前字符是数字
        if (s[i] >= '0' && s[i] <= '9') {
            // 将数字字符转换为对应的数值并乘以权重
            decimal += (s[i] - '0') * std::pow(k, s.length() - i - 1);
        } else {
            // 如果是字母(A-F)，将其转换为对应的数值(10-15)并乘以权重
            decimal += (s[i] - 'A' + 10) * pow(k, s.length() - i - 1);
        }
    }
    return decimal;
}

int main() {
    // 读取需要转换的数字个数
    int n;
    std::cin >> n;

    // 处理每个输入的K进制数
    for (int i = 0; i < n; i++) {
        int k;          // 进制基数
        std::string s;  // K进制字符串
        std::cin >> k >> s;
        // 输出转换后的十进制结果
        std::cout << trans_to_decimal(s, k) << "\n";
    }
    return 0;
}
