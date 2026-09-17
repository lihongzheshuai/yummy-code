/**
 * 题目: 【GESP】C++一级练习BCQM3031，浮点计算，国庆快乐
 * 题号: 3031
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3031/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%.2lf", n - m * 0.8);
    return 0;
}
