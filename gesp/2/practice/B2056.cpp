/**
 * 题目: 【GESP】C++二级练习 luogu-B2056, 求整数的和与均值
 * 题号: B2056
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2056/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int n; // 定义整数n
    scanf("%d", &n); // 读取n的值
    int a; // 定义整数a
    int ans = 0; // 定义累加结果ans
    for (int i = 0; i < n; i++) { // 循环n次
        scanf("%d", &a); // 读取每个样本数据a
        ans += a; // 累加每个样本数据
    }
    printf("%d %.5f", ans, (double)ans / n); // 输出累加结果和均值
    return 0; // 返回0
}
