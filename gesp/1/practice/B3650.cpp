/**
 * 题目: 【GESP】C++一级练习 luogu-B3650, 求和
 * 题号: B3650
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b3650/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    long long n; // 定义一个长整型变量n，用于存储输入的整数
    cin >> n; // 从输入流中读取n的值
    long long ans = 0; // 定义一个长整型变量ans，用于存储累加的和
    for (int i = 1; i <= n; i++) { // 循环从1到n
        ans += i; // 将当前数i加到ans上
        printf("%lld\n", ans); // 输出当前的累加和
    }
    return 0; // 返回0，表示程序执行成功
}
