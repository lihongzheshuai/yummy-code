/**
 * 题目: 【GESP】C++二级练习 图形输出练习09-菱形（中心点）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-09-dia-one/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 输入菱形大小n
    int n;
    cin >> n;
    // 计算中心点位置
    int mid_idx = (n + 1) / 2;
    // 外层循环控制行数
    for (int i = 1; i <= n; i++) {
        // 内层循环控制列数
        for (int j = 1; j <= n; j++) {
            // 处理中心点位置
            if (i == mid_idx && j == mid_idx) {
                cout << "*";
            }
            // 处理上半部分菱形
            else if (i < mid_idx) {
                // 根据对称性计算菱形边界位置
                if (j == mid_idx - i + 1 || j == mid_idx + i - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            // 处理下半部分菱形
            else {
                // 根据对称性计算菱形边界位置
                if (j == i -mid_idx + 1 || j == n - i + mid_idx) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        // 每行结束换行
        cout << endl;
    }
    return 0;
}
