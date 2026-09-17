/**
 * 题目: 【GESP】C++二级练习 图形输出练习02-三角形（右对齐）
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-local-02-tri-right-pic/
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
        // 内层循环控制每行字符的打印
        for (int j = 0; j < n; j++) {
            // 当j大于等于n-i-1时打印星号，实现右对齐效果
            if (j >= n - i - 1) {
                cout << "*";
            } else {
                // 否则打印空格
                cout << " ";
            }
        }
        // 每行结束后换行
        cout << endl;
    }
    return 0;
}
