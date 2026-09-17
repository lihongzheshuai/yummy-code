/**
 * 题目: 【GESP】C++一级练习 luogu-P1424, 小鱼的航程（改进版）
 * 题号: P1424
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1424/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int a, b; // a: 从周几开始，b: 经过的天数
    cin >> a >> b; // 读取输入的周几和天数
    int max = 0; // 初始化累计游泳距离为0

    // 循环遍历经过的天数
    for (int i = 0; i < b; i++) {
        // 如果当前是工作日（不是周六或周日），则累计游泳距离
        if (a != 6 && a != 7) {
            max += 250; // 每个工作日游泳250公里
        }
        // 如果当前是周日，重置为周一
        if (a >= 7) {
            a = 1; // 重置为周一
        } else {
            a += 1; // 否则，进入下一天
        }
    }
    cout << max; // 输出累计游泳距离
    return 0; // 程序结束
}
