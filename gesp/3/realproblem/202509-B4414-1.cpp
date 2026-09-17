/**
 * 题目: 【GESP】C++三级真题 luogu-B4414 [GESP202509 三级] 日历制作
 * 题号: B4414
 * 归属: GESP3级 (202509认证真题)
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-3-luogu-b4414/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>

int main() {
    int m;
    std::cin >> m;                          // 读入需要输出的月份
    std::cout << "MON TUE WED THU FRI SAT SUN\n";  // 打印星期标题行

    // 针对2025年各月1日对应的星期偏移（已硬编码）
    // 通过 switch 分支直接控制该月日历的排版
    switch (m) {
        case 1:
            // 1月：1号为星期三，前面空2格
            for (int i = 1; i <= 33; i++) { // 33 = 31天 + 2个空位
                if (i <= 2) {
                    printf("    ");         // 占位4空格（含后续分隔）
                } else {
                    printf("% 3d ", i - 2); // 右对齐3位数字 + 1空格
                }
                if (i % 7 == 0) {           // 每7列换行
                    std::cout << "\n";
                }
            }
            break;
        case 2:
            // 2月：1号为星期六，前面空5格
            for (int i = 1; i <= 33; i++) { // 28天 + 5空位
                if (i <= 5) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 5);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 3:
            // 3月：1号为星期六，前面空5格
            for (int i = 1; i <= 36; i++) { // 31天 + 5空位
                if (i <= 5) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 5);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 4:
            // 4月：1号为星期二，前面空1格
            for (int i = 1; i <= 31; i++) { // 30天 + 1空位
                if (i <= 1) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 1);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 5:
            // 5月：1号为星期四，前面空3格
            for (int i = 1; i <= 34; i++) { // 31天 + 3空位
                if (i <= 3) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 3);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 6:
            // 6月：1号为星期日，前面空6格
            for (int i = 1; i <= 36; i++) { // 30天 + 6空位
                if (i <= 6) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 6);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 7:
            // 7月：1号为星期二，前面空1格
            for (int i = 1; i <= 32; i++) { // 31天 + 1空位
                if (i <= 1) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 1);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 8:
            // 8月：1号为星期五，前面空4格
            for (int i = 1; i <= 35; i++) { // 31天 + 4空位
                if (i <= 4) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 4);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 9:
            // 9月：1号为星期一，无偏移
            for (int i = 1; i <= 30; i++) { // 30天
                printf("% 3d ", i);
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 10:
            // 10月：1号为星期三，前面空2格
            for (int i = 1; i <= 33; i++) { // 31天 + 2空位
                if (i <= 2) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 2);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 11:
            // 11月：1号为星期六，前面空5格
            for (int i = 1; i <= 35; i++) { // 30天 + 5空位
                if (i <= 5) {
                    printf("    ");
                } else {
                    printf("% 3d ", i - 5);
                }
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        case 12:
            // 12月：1号为星期一，无偏移
            for (int i = 1; i <= 31; i++) { // 31天
                printf("% 3d ", i);
                if (i % 7 == 0) {
                    std::cout << "\n";
                }
            }
            break;
        default:
            break;
    }
    return 0;
}
