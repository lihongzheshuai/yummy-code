/**
 * 题目: 【GESP】C++二级练习 luogu-p2669, [NOIP2015 普及组] 金币
 * 题号: P2669
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-p2669/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int k; // 输入的整数
    cin >> k;
    int count = 0; // 计数器
    int days = 1; // 天数
    int temp_count = 0; // 临时计数器
    for (int i = 1; i <= k; ) { // 主循环
        for (int j = 1; j <= days && i <= k; j++) { // 内循环
            count += days; // 计数器累加
            i++; // 主循环计数器递增
        }
        days++; // 天数递增
    }
    cout << count; // 输出计数器的值
    return 0;
}
