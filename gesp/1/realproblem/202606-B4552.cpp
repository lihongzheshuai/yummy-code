/**
 * 题目: 【GESP】C++一级真题 luogu-B4552 [GESP202606 一级] 交税
 * 题号: B4552
 * 归属: GESP1级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4552/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>

int main() {
    // 用于累加12个月的个税总和
    double total = 0.0;
    // 循环读取12个月的劳务报酬
    for (int i = 0; i < 12; i++) {
        double salary;
        // 从标准输入读取当月劳务报酬
        scanf("%lf", &salary);
        // 如果报酬超过800，对超出部分按20%计算个税并累加
        if (salary > 800.0) {
            total += (salary - 800.0) * 0.2;
        }
    }
    // 输出12个月应预交个税总和，保留两位小数
    printf("%.2f\n", total);
    return 0;
}
