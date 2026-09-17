/**
 * 题目: 【GESP】C++一级练习BCQM3092，双面打印
 * 题号: 3092
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3092/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int i = n / 2;
    if (n % 2 != 0) {
        i += 1;
    }
    printf("%d", i);
    return 0;
}
