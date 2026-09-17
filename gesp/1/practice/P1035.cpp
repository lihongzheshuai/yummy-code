/**
 * 题目: 【GESP】C++一级练习 luogu-P1035, [NOIP2002 普及组] 级数求和
 * 题号: P1035
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1035/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    // 读取输入的整数k
    int k;
    scanf("%d", &k);
    // 初始化n为0
    int n = 0;
    // 使用for循环来计算n，使得a不超过k
    for (double a = 0; a <= k; a += 1.0 / n) {
        // 每次循环增加n的值
        n++;
    }
    // 输出计算得到的n
    printf("%d", n);
    return 0;
}
