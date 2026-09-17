/**
 * 题目: 【GESP】C++三级真题 luogu-B4414 [GESP202509 三级] 日历制作
 * 题号: B4414
 * 归属: GESP3级 (202509认证真题)
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4414/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>

// 2025年各月天数，0号元素占位，1~12月分别对应实际天数
int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int m;
    std::cin >> m;                          // 读入需要输出的月份
    std::cout << "MON TUE WED THU FRI SAT SUN\n";  // 打印星期标题行

    int start_day = 1;  // 2025年9月1日为星期一，作为基准
    int total_days = 0; // 累计从基准月到目标月之间的总天数

    if (m == 9) {
        // 目标月就是9月，无需累加，直接已知start_day=1
        start_day = 1;
    } else if (m < 9) {
        // 目标月在9月之前，从m月累加到8月
        for (int i = m; i < 9; i++) {
            total_days += month_days[i];
        }
        // 计算相对于基准的星期偏移：往前推total_days天
        // 往前推 total_days 天，计算新的星期偏移
        // 7 代表星期日，公式保证结果落在 1~7 之间
        start_day = 7 - (total_days - 1) % 7;
    } else {
        // 目标月在9月之后，从9月累加到m-1月
        for (int i = 9; i < m; i++) {
            total_days += month_days[i];
        }
        // 往后推total_days天
        start_day += total_days % 7;
    }

    // 打印该月日历：循环总格数 = 月初偏移 + 该月天数
    for (int i = 1; i <= month_days[m] + start_day - 1; i++) {
        if (i < start_day) {
            std::cout << "   " << " ";  // 月初前的空白天
        } else {
            printf("% 3d ", i - start_day + 1);  // 右对齐输出日期
        }
        if (i % 7 == 0) {
            std::cout << "\n";  // 每7列换行
        }
    }
    return 0;
}
