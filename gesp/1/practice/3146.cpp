/**
 * 题目: 【GESP】C++一级练习BCQM3146，老狼老狼
 * 题号: 3146
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3146/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
int main() {
    int k = 0;
    for (int i = 1; i < 13; i++) {
        k += 1;
        printf("老狼老狼几点钟？%d点钟。\n", k);
    }
    printf("狼来了，快跑！");
    return 0;
}
