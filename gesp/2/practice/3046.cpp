/**
 * 题目: 【GESP】C++二级练习BCQM3046，简单加密
 * 题号: 3046
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-bcqm3046/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
using namespace std;
int main() {
    char str[5];
    scanf("%s", str);
    for (int i = 0; i < 5; i++) {
        char c = str[i] + 4;
        printf("%c", c);
    }
    return 0;
}
