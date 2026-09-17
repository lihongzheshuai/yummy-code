/**
 * 题目: 【GESP】C++一级练习BCQM3088，收费计算
 * 题号: 3088
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3088/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    double a;
    scanf("%lf", &a);
    if (a <= 20) {
        printf("%.2f", a * 1.68);
    } else {
        printf("%.2f", a * 1.98);
    }
    return 0;
}
