/**
 * 题目: 【GESP】C++三级模拟题 luogu-B3848 [GESP样题 三级] 逛商场
 * 题号: B3848
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b3848/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    // 读取物品数量
    int n;
    std::cin >> n;

    // 创建数组存储物品价格
    int ary[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ary[i];
    }

    // 读取初始零花钱金额
    int money;
    std::cin >> money;

    // 统计可以购买的物品数量
    int count = 0;
    for (int i = 0; i < n; i++) {
        // 如果当前金额足够购买物品
        if (money >= ary[i]) {
            count++;  // 购买数量加1
            money -= ary[i];  // 扣除物品价格
        }
    }

    // 输出购买的物品总数
    std::cout << count;
    return 0;
}
