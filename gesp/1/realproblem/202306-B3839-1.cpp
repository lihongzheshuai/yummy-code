/**
 * 题目: 【GESP】C++一级真题练习(202306)luogu-B3839，累计相加
 * 题号: B3839
 * 归属: GESP1级 (202306认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b3839/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;  // 输入正整数n
    int ans = 1;  // 初始化结果为1，因为第一项就是1

    // 从第2项开始循环到第n项
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            // 第i项的值是1+2+3+...+i，使用等差数列求和公式：(首项+末项)*项数/2
            ans += (1 + i) * i / 2;
        }
    }

    cout << ans;  // 输出累计相加的结果
    return 0;
}
