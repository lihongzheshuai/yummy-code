/**
 * 题目: 【GESP】C++二级练习 luogu-B3845, [GESP样题 二级] 勾股数
 * 题号: B3845
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b3845/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 输入的最大值
    cin >> n; // 读取输入的最大值
    int count = 0; // 计数器，用于统计勾股数的数量
    for (int i = 1; i <= n; i++) { // 外层循环，控制i的值
        for (int j = i; j <= n; j++) { // 中层循环，控制j的值
            for (int k = j; k <= n; k++) { // 内层循环，控制k的值
                if (i * i + j * j == k * k) { // 判断是否为勾股数
                    count++; // 如果是，计数器加1
                }
            }
        }
    }
    cout << count; // 输出计数器的值，即勾股数的数量
    return 0;
}
