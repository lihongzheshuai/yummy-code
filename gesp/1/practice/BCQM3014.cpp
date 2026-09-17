/**
 * 题目: BCQM3014-练4.3 3个连续数
 * 题号: BCQM3014
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3013-3014/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    // 初始100开始
    int a = 100;
    // 循环3次，数3个数
    for (int i = 0; i < 3; i++) {
        printf("%d\n", a);
        a += 1;
    }
    return 0;
}
