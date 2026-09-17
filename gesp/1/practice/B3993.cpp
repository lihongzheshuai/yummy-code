/**
 * 题目: 【GESP】C++一级模拟luogu-B3993，明日复明日
 * 题号: B3993
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b3993/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int month, day; // 定义月份和日期变量
    cin >> month >> day; // 从输入流中读取月份和日期

    // 处理2月28日的情况
    if (month == 2 && day == 28) {
        month += 1; // 进入下一个月
        day = 0; // 日期重置为1
    }
    // 处理1、3、5、7、8、10月31日的情况
    if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
         month == 10) &&
        day == 31) {
        month += 1; // 进入下一个月
        day = 0; // 日期重置为1
    }
    // 处理12月31日的情况
    if (month == 12 && day == 31) {
        month = 1; // 进入下一年的1月
        day = 0; // 日期重置为1
    }
    // 处理4、6、9、11月30日的情况
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
        month += 1; // 进入下一个月
        day = 1; // 日期设置为1
    } else {
        day += 1; // 其他情况下，日期加1
    }
    cout << month << " " << day; // 输出结果
    return 0;
}
