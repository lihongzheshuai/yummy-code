/**
 * 题目: 【GESP】C++一级真题练习(202306)luogu-B3839，累计相加
 * 题号: B3839
 * 归属: GESP1级 (202306认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b3839/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;  // 输入正整数n
    int ans = 0;  // 初始化累计相加的结果为0

    // 根据规律：第i个数字在前n项中出现(n-i+1)次
    // 例如n=3时，1出现3次，2出现2次，3出现1次
    for (int i = 1; i <= n; i++) {
        ans += (n - (i - 1)) * i;  // 累加每个数字i乘以它的出现次数
    }

    cout << ans;  // 输出累计相加的结果
    return 0;
}
