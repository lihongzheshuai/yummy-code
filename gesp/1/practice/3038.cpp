/**
 * 题目: 【GESP】C++一级练习BCQM3038，计算分数的浮点数值
 * 题号: 3038
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3038/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int a, b;                // 定义分子 a 和分母 b
    scanf("%d%d", &a, &b);   // 读取用户输入的两个整数
    printf("%.9f", (double) a / b); // 将 a 强制转为 double 后做除法，保留 9 位小数输出
    return 0;                // 程序正常结束
}
