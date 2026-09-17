/**
 * 题目: 【GESP】C++一级练习 luogu-B2059, 奇数求和
 * 题号: B2059
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2059/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int m, n; // 定义变量m和n，用于存储输入的两个整数
    cin >> m >> n; // 从输入流中读取m和n的值
    int ans = 0; // 初始化变量ans，用于存储奇数的和
    for (int i = m; i <= n; i++) { // 从m到n的循环
        if (i % 2 != 0) { // 检查i是否为奇数
            ans += i; // 如果i为奇数，则将其累加到ans中
        }
    }
    cout << ans; // 输出ans的值，即m到n之间所有奇数的和
    return 0; // 返回0，表示程序执行成功
}
