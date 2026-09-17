/**
 * 题目: 【NOIP】2008真题解析 luogu-P1125 笨小猴
 * 题号: P1125
 * 归属: 算法练习
 * 博客: https://www.coderli.com/noip-2008-luogu-p1125/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <algorithm>
#include <iostream>
#include <string>

// 质数判定函数
bool is_prime(int n) {
    if (n < 2) {
        return false; // 0 和 1 不是质数，直接返回
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; // 能被整除则不是质数
        }
    }
    return true;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int counts[26] = {0}; // 长度为 26 的计数数组（桶），初始化为 0
    for (char c : s) {
        counts[c - 'a']++; // 统计每个字母的出现次数
    }

    int maxn = 0;   // 出现次数的最大值
    int minn = 105; // 出现次数的最小值（初值设为大于单词最大长度 100）

    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) { // 只考虑出现过的字母
            maxn = std::max(maxn, counts[i]);
            minn = std::min(minn, counts[i]);
        }
    }

    int diff = maxn - minn;

    // 根据质数判定结果，输出对应内容
    if (is_prime(diff)) {
        std::cout << "Lucky Word" << "\n" << diff << "\n";
    } else {
        std::cout << "No Answer" << "\n" << 0 << "\n";
    }

    return 0;
}
