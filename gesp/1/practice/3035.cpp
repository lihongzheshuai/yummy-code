/**
 * 题目: 【GESP】C++一级练习BCQM3035，实数计算，国庆七天乐
 * 题号: 3035
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3035/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    double v = 0;
    double r;
    scanf("%lf", &r);
    v = 4.0 / 3.0 * 3.14 * r * r * r;
    printf("%.2f", v);
    return 0;
}
