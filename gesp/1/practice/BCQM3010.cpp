/**
 * 题目: BCQM3010-【例4.1】 交换两个数的位置
 * 题号: BCQM3010
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3010-3012-3019/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int a = 20, b = 22, c = 0;
    c = a;
    a = b;
    b = c;
    printf("a=%d\n", a);
    printf("b=%d", b);
    return 0;
}
