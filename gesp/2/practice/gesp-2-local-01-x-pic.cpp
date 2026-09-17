/**
 * 题目: 【GESP】C++二级练习 图形输出练习01-X图形
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-01-x-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量n用于存储输入的大小
    int n;
    // 从标准输入读取n的值
    cin >> n;
    // 外层循环控制行数
    for (int i = 0; i < n; i++) {
        // 内层循环控制每行的字符输出
        for (int j = 0; j < n; j++) {
            // 当j等于i或者j等于n-i-1时，输出星号
            // 这样可以在对角线位置打印星号，形成X形状
            if (j == i || j == n - i - 1) {
                cout << "*";
            } else {
                // 其他位置输出空格
                cout << " ";
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    // 程序结束
    return 0;
}
