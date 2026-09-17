/**
 * 题目: 【GESP真题】GESP三级 / CSP-J 题解：luogu-B4577 [GESP202609 三级] 公共二进制位
 * 题号: B4577
 * 归属: GESP3级 (202609认证真题)
 * 博客: https://www.coderli.com/gesp-3-luogu-b4577-common-binary-bits/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

/**
 * Problem: luogu-B4577
 * Standard: C++11 (CCF GESP 官方大纲规范)
 * Author: OneCoder
 */

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    long long common_bits;
    cin >> common_bits;

    // 顺序与后续所有数做按位与
    for (int i = 1; i < n; ++i) {
        long long a;
        cin >> a;
        common_bits &= a;
    }

    // 统计公共位中 1 的数量
    int count = 0;
    while (common_bits > 0) {
        if (common_bits & 1) {
            count++;
        }
        common_bits >>= 1;
    }

    cout << count << "\n";

    return 0;
}
