/**
 * 题目: 【GESP】C++一级练习luogu-B3846，闰年求和
 * 题号: B3846
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b3846/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    for (int i = a + 1; i < b; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            ans += i;
        }
    }
    printf("%d", ans);
    return 0;
}
