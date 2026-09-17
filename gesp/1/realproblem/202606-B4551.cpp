/**
 * 题目: 【GESP】C++一级真题 luogu-B4551 [GESP202606 一级] 去旅行
 * 题号: B4551
 * 归属: GESP1级 (202606认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4551/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 声明变量存储四个价格
    int a, b, c, d;
    // 从标准输入读取四个价格
    // a: A市直飞B市, b: A市高铁到C市, c: C市飞机到B市, d: C市高铁到B市
    std::cin >> a >> b >> c >> d;
    // 计算三种方案的价格
    int plan1 = a;       // 方案1：直飞
    int plan2 = b + c;   // 方案2：高铁转飞机
    int plan3 = b + d;   // 方案3：全程高铁
    // 求三种方案中的最小值
    int minCost = plan1;
    if (plan2 < minCost) {
        minCost = plan2;
    }
    if (plan3 < minCost) {
        minCost = plan3;
    }
    // 输出最便宜的价格
    std::cout << minCost;
    return 0;
}
