/**
 * 题目: 【GESP】C++一级真题 luogu-B4409 [GESP202509 一级] 商店折扣
 * 题号: B4409
 * 归属: GESP1级 (202509认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4409/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cstdio>

int main() {
    int x, y, n, p;
    std::cin >> x >> y >> n >> p;          // 读入四个正整数：满减门槛x、减免金额y、折扣n、总价p
    int plan_one = p >= x ? p - y : p;     // 方案一：若满x元则减y元，否则原价
    double plan_two = p / 10.0 * n;        // 方案二：直接打n折，即总价乘以n/10
    double result = plan_one > plan_two ? plan_two : plan_one; // 取两种方案中更便宜的一个
    printf("%.2f", result);               // 保留两位小数输出最少需支付的金额
    return 0;
}
