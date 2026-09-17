/**
 * 题目: BCQM3019-练5.2 阿布拉2
 * 题号: BCQM3019
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3010-3012-3019/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int x, y, c = 0;
    // 读取变量输入值
    scanf("%d%d", &x, &y);
    // 输出交换前变量值
    printf("a=%d ", x);
    printf("b=%d\n", y);
    c = y;
    y = x;
    x = c;
    // 输出交换后变量值
    printf("a=%d ", x);
    printf("b=%d\n", y);
    return 0;
}
