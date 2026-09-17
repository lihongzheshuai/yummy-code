/**
 * 题目: 【GESP】C++二级真题 luogu-B4498, [GESP202603 二级] 画画
 * 题号: B4498
 * 归属: GESP2级 (202603认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4498/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    // 外层循环控制行，i 从 1 到 n
    for (int i = 1; i <= n; i++) {
        // 内层循环控制列，j 从 1 到 n
        for (int j = 1; j <= n; j++) {

            // 规则 1：判断是否是四个顶点
            // 行是第1行或第n行，同时列是第1列或第n列
            if ((i == 1 || i == n) && (j == 1 || j == n)) {
                std::cout << "+";
            }
            // 规则 2：判断是否是上下边缘（排除顶点后）
            // 如果是第1行或者第n行，打印 '-'
            else if (i == 1 || i == n) {
                std::cout << "-";
            }
            // 规则 3：判断是否是左右边缘（排除顶点后）
            // 如果是第1列或者第n列，打印 '|'
            else if (j == 1 || j == n) {
                std::cout << "|";
            }
            // 规则 4：正方形内部区域
            // 其他所有情况，打印 '*'
            else {
                std::cout << "*";
            }

        } // 结束当前行的打印

        // 这一行的内容全部横向打印完毕，输出换行符，准备打印下一行
        std::cout << std::endl;
    }

    return 0;
}
