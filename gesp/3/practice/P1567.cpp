/**
 * 题目: 【GESP】C++三级练习 luogu-p1567, 统计天数
 * 题号: P1567
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1567/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int a[1000001];
int main() {
    int n; // 定义一个整型变量n，用于存储输入的天数
    cin >> n; // 从标准输入流中读取n的值
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // 读取并存储每天的最高气温
    }
    int total_max = 1; // 初始化一个整型变量total_max，用于存储最高气温一直上升的最长连续天数，初始值为1
    if (n == 1) { // 如果输入的天数为1
        cout << total_max; // 直接输出1，因为只有1天，最高气温一直上升的最长连续天数为1
        return 0; // 程序结束
    }
    int last_num = a[0]; // 初始化一个整型变量last_num，用于存储上一天的最高气温，初始值为第一天的最高气温
    int cur_max = 1; // 初始化一个整型变量cur_max，用于存储当前最高气温一直上升的连续天数，初始值为1
    for (int i = 1; i < n; i++) { // 从第二天开始遍历
        if (a[i] > last_num) { // 如果当前天的最高气温大于上一天的最高气温
            cur_max++; // 当前最高气温一直上升的连续天数加1
        } else { // 如果当前天的最高气温不大于上一天的最高气温
            total_max = max(total_max, cur_max); // 更新最高气温一直上升的最长连续天数
            cur_max = 1; // 重置当前最高气温一直上升的连续天数为1
        }
        last_num = a[i]; // 更新上一天的最高气温为当前天的最高气温
    }
    total_max = max(total_max, cur_max); // 遍历完毕后，更新最高气温一直上升的最长连续天数
    cout << total_max; // 输出最高气温一直上升的最长连续天数
    return 0; // 程序结束
}
