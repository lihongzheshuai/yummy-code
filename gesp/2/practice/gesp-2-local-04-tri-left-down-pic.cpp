/**
 * 题目: 【GESP】C++二级练习 图形输出练习04-三角形（左对齐-倒置）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-04-tri-left-down-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量n用于存储用户输入的三角形行数
    int n;
    // 从标准输入读取n的值
    cin >> n;
    // 外层循环控制行数
    for (int i = 0; i < n; i++) {
        // 内层循环控制每行字符的打印
        for (int j = 0; j < n; j++) {
            // 如果当前位置应该打印星号
            if (j < n - i) {
                cout << "*";
            }
            // 否则打印空格
            else {
                cout << " ";
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    // 程序结束
    return 0;
}
