/**
 * 题目: 【GESP】C++二级练习 图形输出练习03-三角形（左对齐）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-03-tri-left-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量n用于存储输入的行数
    int n;
    // 从标准输入读取行数
    cin >> n;
    // 外层循环控制行数
    for (int i = 0; i < n; i++) {
        // 内层循环控制每行字符的打印
        for (int j = 0; j < n; j++) {
            // 如果当前位置小于等于行号，打印星号
            if (j <= i) {
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
