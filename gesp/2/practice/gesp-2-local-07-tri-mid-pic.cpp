/**
 * 题目: 【GESP】C++二级练习 图形输出练习07-三角形（等腰）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-07-tri-mid-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 声明变量n用于存储输入的行数
    int n;
    // 从标准输入读取行数
    cin >> n;
    // 计算中间位置索引
    int mid_idx = n;

    // 外层循环控制行数
    for (int i = 1; i <= n; i++) {
        // 内层循环控制每行的字符输出
        for (int j = 1; j <= 2 * n - 1; j++) {
            // 判断当前位置是否需要打印星号
            // j >= mid_idx - i + 1：左边界条件
            // j <= mid_idx + i - 1：右边界条件
            if (j >= mid_idx - i + 1 && j <= mid_idx + i - 1) {
                cout << "*";  // 在范围内打印星号
            } else {
                cout << " ";  // 在范围外打印空格
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    return 0;
}
