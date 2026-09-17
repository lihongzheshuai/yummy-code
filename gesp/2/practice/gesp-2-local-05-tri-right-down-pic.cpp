/**
 * 题目: 【GESP】C++二级练习 图形输出练习05-三角形（右对齐-倒置）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-05-tri-right-down-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 声明变量n用于存储用户输入的三角形行数
    int n;
    // 从标准输入读取n的值
    cin >> n;
    // 外层循环控制行数
    for (int i = 0; i < n; i++) {
        // 内层循环控制每行的字符输出
        for (int j = 0; j < n; j++) {
            // 判断当前位置是否需要打印星号
            // j >= n-i-1 表示从右向左打印星号
            if (j >= n - i - 1) {
                cout << "*";
            } else {
                // 打印空格以实现右对齐
                cout << " ";
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    // 程序结束
    return 0;
}
