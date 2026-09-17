/**
 * 题目: 【GESP】C++二级练习 luogu-p2669, [NOIP2015 普及组] 金币
 * 题号: P2669
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-p2669/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int k; // 输入的整数
    cin >> k;
    int count = 0; // 计数器
    int days = 1; // 当前天数
    int now_coins = 1; // 当前天数收到的金币数
    for (int i = 1; i <= k; i++) { // 从1到k天的循环
        count += now_coins; // 计数器累加当前天数的金币数
        days--; // 天数减1
        if (days == 0) { // 如果天数减到0
            now_coins++; // 当前天数收到的金币数增加1
            days = now_coins; // 重置天数为当前天数收到的金币数
        }
    }
    cout << count; // 输出计数器的值
    return 0;
}
