/**
 * 题目: 【GESP】C++一级练习 luogu-P1425, 小鱼的游泳时间
 * 题号: P1425
 * 归属: GESP1级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-p1425/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d; // 定义四个整数变量，分别表示开始时间的小时（a）和分钟（b），以及结束时间的小时（c）和分钟（d）

    // 从标准输入读取四个整数，表示开始和结束的时间
    scanf("%d%d%d%d", &a, &b, &c, &d);

    // 将开始时间转换为总分钟数
    int start_m = a * 60 + b;
    // 将结束时间转换为总分钟数
    int end_m = c * 60 + d;

    // 计算总共经过的分钟数
    int cost_m = end_m - start_m;
    // 计算经过的小时数
    int cost_time_h = cost_m / 60;
    // 计算经过的分钟数
    int cost_time_m = cost_m % 60;

    // 输出经过的小时和分钟
    printf("%d %d", cost_time_h, cost_time_m);
    return 0; // 程序结束
}
