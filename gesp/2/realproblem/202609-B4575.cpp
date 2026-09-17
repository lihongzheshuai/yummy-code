/**
 * 题目: 【GESP真题】GESP二级题解：luogu-B4575 [GESP202609 二级] 直角三角形
 * 题号: B4575
 * 归属: GESP2级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4575-right-triangle/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4575
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // 快速输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double a, b, limit;
    if (!(cin >> a >> b >> limit)) {
        return 0;
    }

    // 特判前两项已超出上限的情况
    if (a > limit) {
        cout << 1 << "\n";
        return 0;
    }
    if (b > limit) {
        cout << 2 << "\n";
        return 0;
    }

    int step = 2;
    double prev2 = a; // 前两项中的较早一项 a_{i-2}
    double prev1 = b; // 前一项 a_{i-1}

    // 循环模拟生成后续项
    while (prev1 <= limit) {
        double next_val = sqrt(prev2 * prev2 + prev1 * prev1);
        step++;
        if (next_val > limit) {
            cout << step << "\n";
            return 0;
        }
        prev2 = prev1;
        prev1 = next_val;
    }

    cout << step << "\n";
    return 0;
}
