/**
 * 题目: 【GESP】C++一级真题练习(202303)luogu-B3835，每月天数
 * 题号: B3835
 * 归属: GESP1级 (202303认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b3835/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 定义年份和月份变量
    int year, month;

    // 从标准输入读取年份和月份
    cin >> year >> month;

    // 判断月份天数
    // 31天的月份：1,3,5,7,8,10,12月
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
        month == 10 || month == 12) {
        cout << 31;
    }
    // 30天的月份：4,6,9,11月
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        cout << 30;
    }
    // 2月特殊处理：需要判断是否闰年
    else if (month == 2) {
        // 闰年判断：能被4整除但不能被100整除，或者能被400整除
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            cout << 29;  // 闰年2月29天
        } else {
            cout << 28;  // 平年2月28天
        }
    }
    return 0;
}
