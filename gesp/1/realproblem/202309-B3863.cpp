/**
 * 题目: 【GESP】C++一级真题练习(202309)luogu-B3863，买文具
 * 题号: B3863
 * 归属: GESP1级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b3863/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 定义变量存储签字笔、记事本、直尺的数量和小明的钱数
    int first, second, third, money;

    // 从标准输入读取四个整数
    cin >> first >> second >> third >> money;

    // 计算总花费：签字笔2元/支，记事本5元/本，直尺3元/把
    int total_cost = first * 2 + second * 5 + third * 3;

    // 判断钱是否足够
    if (money >= total_cost) {
        // 如果钱够，输出Yes和剩余金额
        cout << "Yes" << endl;
        cout << money - total_cost;
    } else {
        // 如果钱不够，输出No和缺少的金额
        cout << "No" << endl;
        cout << total_cost - money;
    }

    return 0;
}
