/**
 * 题目: 【GESP】C++三级练习BCQM3091，选择题判定
 * 题号: 3091
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-bcqm3091/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
using namespace std;
int main() {
    char n[5];
    scanf("%s", n);
    int i = 0;
    if ('D' == n[0]) {
        i += 30;
    }
    if ('C' == n[1]) {
        i += 30;
    }
    if ('B' == n[2]) {
        i += 30;
    }
    if ('A' == n[3]) {
        i += 30;
    }
    if ('D' == n[4]) {
        i += 30;
    }
    printf("%d", i);
    return 0;
}
