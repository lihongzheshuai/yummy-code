/**
 * 题目: 【GESP】C++二级真题 luogu-b3865, [GESP202309 二级] 小杨的 X 字矩阵
 * 题号: B3865
 * 归属: GESP2级 (202309认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3865/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 读取输入的n
    int result = n; // 初始化result为n
    for (int i = 1; i <= n; i++) { // 遍历从1到n的所有数
        for (int j = n; j >= 1; j--) { // 遍历从n到1的所有数
            if (j == i || j == n - i + 1) { // 如果j等于i或j等于n-i+1
                cout << "+"; // 输出"+"
            } else {
                cout << "-"; // 否则输出"-"
            }
        }
        cout << endl; // 换行
    }
}
