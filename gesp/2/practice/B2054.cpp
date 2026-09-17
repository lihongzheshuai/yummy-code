/**
 * 题目: 【GESP】C++二级练习 luogu-B2054, 求平均年龄
 * 题号: B2054
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2054/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
using namespace std;
int main() {
    // 读取学生总数
    int n;
    scanf("%d", &n);
    // 初始化平均年龄
    int ans = 0;
    // 用于存储每个学生的年龄
    int a;
    // 循环读取每个学生的年龄
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        // 累加每个学生的年龄
        ans += a;
    }
    // 计算平均年龄并保留到小数点后两位
    printf("%.2f", (double) ans / n);
    return 0;
}
