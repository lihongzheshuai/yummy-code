/**
 * 题目: 【GESP】C++一级真题练习(202306)luogu-B3838，时间规划
 * 题号: B3838
 * 归属: GESP1级 (202306认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-luogu-b3838/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量存储开始和结束时刻的小时、分钟
    int hour, minute, hour2, minute2;
    // 读入开始时刻和结束时刻
    cin >> hour >> minute >> hour2 >> minute2;

    // 如果结束时刻的分钟数小于开始时刻的分钟数
    // 需要向小时借位,即结束时刻减1小时,分钟数加60
    if (minute2 < minute) {
        hour2 -= 1;     // 小时数减1
        minute2 += 60;  // 分钟数加60
    }

    // 计算小时差
    int i = hour2 - hour;
    // 输出总分钟数 = 小时差×60 + 分钟差
    cout << i * 60 + (minute2 - minute);
    return 0;
}
