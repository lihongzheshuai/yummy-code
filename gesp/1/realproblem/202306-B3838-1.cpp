/**
 * 题目: 【GESP】C++一级真题练习(202306)luogu-B3838，时间规划
 * 题号: B3838
 * 归属: GESP1级 (202306认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b3838/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量存储开始时刻和结束时刻的小时、分钟
    int hour, minute, hour2, minute2;

    // 依次读入开始时刻的小时、分钟，结束时刻的小时、分钟
    cin >> hour >> minute >> hour2 >> minute2;

    // 计算时间差：将两个时刻都转换为分钟数，然后相减
    // 开始时刻总分钟数 = hour * 60 + minute
    // 结束时刻总分钟数 = hour2 * 60 + minute2
    // 时间差 = 结束时刻总分钟数 - 开始时刻总分钟数
    cout << (hour2 * 60 + minute2) - (hour * 60 + minute);

    return 0;
}
