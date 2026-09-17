/**
 * 题目: 【GESP】C++二级真题 luogu-B4412 [GESP202509 二级] 菱形
 * 题号: B4412
 * 归属: GESP2级 (202509认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4412/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;                    // 读入菱形边长（奇数）
    int mid = (n + 1) / 2;              // 计算中心行/列位置
    for (int i = 1; i <= n; i++) {    // 逐行绘制
        for (int j = 1; j <= n; j++) { // 逐列绘制
            if (i == 1 || i == n) {    // 首行或末行：仅中心位置输出 #
                if (j == mid) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            } else if (i < mid) {      // 上半部分：对称的两条斜线
                // 上半部分：左斜线列号 = 中心列 - 当前行 + 1，右斜线列号 = 中心列 + 当前行 - 1
                if (j == mid - i + 1 || j == mid + i - 1) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            } else {                   // 下半部分：对称的两条斜线
                // 左斜线列号 = 当前行 - 中心行 + 1，右斜线列号 = 总列数 - 当前行 + 中心行
                if (j == i - mid + 1 || j == n - i + mid) {
                    std::cout << "#";
                } else {
                    std::cout << ".";
                }
            }
        }
        std::cout << "\n";             // 换行进入下一行
    }
    return 0;
}
