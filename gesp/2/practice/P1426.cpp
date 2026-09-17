/**
 * 题目: 【GESP】C++二级练习 luogu-P1426 小鱼会有危险吗
 * 题号: P1426
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p1426/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    double s, x;  // 定义变量：s为目标距离，x为误差范围
    cin >> s >> x;  // 输入目标距离和误差范围
    double t = 0;  // 定义变量t，表示当前速度
    double ans = 0;  // 定义变量ans，表示当前总距离
    for (int i = 1;; i++) {  // 无限循环，直到满足条件退出
        if (ans >= s - x) {  // 如果当前总距离大于等于目标距离减去误差范围
            if (ans + t * 0.98 > s + x) {  // 如果当前总距离加上减速后的速度大于目标距离加上误差范围
                cout << "n";  // 输出“n”，表示不能到达
                return 0;  // 结束程序
            } else {
                cout << "y";  // 输出“y”，表示可以到达
                return 0;  // 结束程序
            }
        }
        if (i == 1) {  // 如果是第一次循环
            t += 7;  // 初始速度增加7
        } else {
            t *= 0.98;  // 之后每次循环速度乘以0.98，表示减速
        }
        ans += t;  // 更新当前总距离
    }
    return 0;  // 结束程序
}
