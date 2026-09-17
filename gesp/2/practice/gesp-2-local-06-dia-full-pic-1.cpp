/**
 * 题目: 【GESP】C++二级练习 图形输出练习06-菱形（实心）
 * 题号: 
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-local-06-dia-full-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 声明变量n用于存储用户输入的菱形大小
    int n;
    // 从标准输入读取菱形大小
    cin >> n;
    // 计算菱形的中间行索引
    int mid_idx = (n + 1) / 2;
    // 外层循环控制行数
    for (int i =1; i <= n; i++) {
        // 内层循环控制每行的字符输出
        for (int j = 1; j <= n; j++) {
            // 处理中间行的情况（全部打印星号）
            if (i == mid_idx) {
                cout << "*";
            }
            // 处理中间行以上的部分
            else if (i < mid_idx){
                // 根据当前位置判断是否打印星号
                // mid_idx - i + 1 到 mid_idx + i - 1 的范围内打印星号
                if (j >= mid_idx - i + 1 && j <= mid_idx + i - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
            // 处理中间行以下的部分
            else {
                // 根据当前位置判断是否打印星号
                // i - mid_idx 到 n - (i - mid_idx) 的范围内打印星号
                if (j > i - mid_idx && j <= n - (i - mid_idx) ) {
                    cout << "*";
                } else {
                    cout << " ";
                }
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    return 0;
}
