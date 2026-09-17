/**
 * 题目: BCQM3012-练4.1 阿布拉1
 * 题号: BCQM3012
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3010-3012-3019/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int a = 10, b = 20, c = 0;
    // 交换前
    printf("a=%d ", a);
    printf("b=%d\n", b);
    c = b;
    b = a;
    a = c;
    // 交换后
    printf("a=%d ", a);
    printf("b=%d\n", b);
    return 0;
}
