/**
 * 题目: 【GESP】C++二级真题 luogu-B4037 [GESP202409 二级] 小杨的 N 字矩阵
 * 题号: B4037
 * 归属: GESP2级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4037/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 读取输入的正整数
    cin >> n; // 从输入流中读取n的值
    for (int i = 1; i <= n; i++) { // 遍历从1到n的所有整数
        cout << "+"; // 输出矩阵的上边界
        for (int j = 1; j <= n - 2; j++) { // 遍历矩阵的中间部分
            if (i == 1 || i == n) { // 如果当前行是第一行或最后一行
                cout << "-"; // 输出边界
            } else {
                if (j == i - 1) { // 如果当前列是对角线
                    cout << "+"; // 输出对角线
                } else {
                    cout << "-"; // 输出非对角线部分
                }
            }
        }
        cout << "+" << endl; // 输出矩阵的下边界并换行
    }
    return 0; // 程序返回0，表示执行成功
}
