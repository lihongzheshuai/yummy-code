/**
 * 题目: 【GESP】C++二级真题 luogu-B4497, [GESP202603 二级] 数数
 * 题号: B4497
 * 归属: GESP2级 (202603认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b4497/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <string>

// 写一个函数专门用来判断一个数字是不是”美丽“的
bool isBeautiful(int num) {
    // 将数字转换成文字（字符串）
    std::string str = std::to_string(num);
    int count2 = 0;

    // 遍历这串文字的每一个字符
    for (int i = 0; i < str.length(); i++) {
        // 如果遇到了字符 '2'
        if (str[i] == '2') {
            count2++;
        }
    }

    // 如果字符 '2' 恰巧出现了 3 次，返回 true，否则返回 false
    return count2 == 3;
}

int main() {
    int L, R;
    std::cin >> L >> R;

    int ans = 0;
    for (int i = L; i <= R; i++) {
        // 调用我们自定义的函数进行判定
        if (isBeautiful(i)) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
