/**
 * 题目: BCQM3013-练4.2 列朋波骨
 * 题号: BCQM3013
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3013-3014/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int a = 0;
    for (int i = 1; i <= 5; i++) {
        // 从第一天开始，每天刻痕数+1
        a += 1;
    }
    printf("%d", a);
    return 0;
}
