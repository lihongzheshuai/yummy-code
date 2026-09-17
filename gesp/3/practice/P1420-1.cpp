/**
 * 题目: 【GESP】C++三级练习 luogu-p1420, 最长连号
 * 题号: P1420
 * 归属: GESP3级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-p1420/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n; // 输入的整数
    cin >> n; // 读取输入的整数
    int a[n]; // 定义一个长度为n的数组
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 读取数组元素
    }
    int max_serial_count = 1; // 初始化最大连续数列计数
    for (int i = 0; i < n; i++) {
        int last_num = a[i]; // 初始化上一个数
        int cur_serial_count = 1; // 初始化当前连续数列计数
        for (int j = i + 1; j < n; j++) {
            if (a[j] == last_num + 1) {
                cur_serial_count++; // 如果当前数是上一个数加1，则计数增加

            } else {
                cur_serial_count = 1; // 如果不是，则重置计数

            }
            max_serial_count = max(max_serial_count, cur_serial_count); // 更新最大计数
            last_num = a[j]; // 更新上一个数
        }
    }
    cout << max_serial_count; // 输出最大连续数列计数
    return 0;
}
