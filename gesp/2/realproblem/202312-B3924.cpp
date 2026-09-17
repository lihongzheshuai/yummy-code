/**
 * 题目: 【GESP】C++二级真题 luogu-b3924, [GESP202312 二级] 小杨的H字矩阵
 * 题号: B3924
 * 归属: GESP2级 (202312认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3924/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std; // 使用标准命名空间
int main() {
    int n; // 定义整数变量n
    cin >> n; // 从输入流读取整数到n
    for (int i = 1; i <= n; i++) { // 循环从1到n
        cout << "|"; // 输出竖线
        for (int j = 1; j <= n - 2; j++) { // 循环从1到n-2
            if (i == (n + 1) / 2) { // 如果当前行数i等于n的中间行
                cout << "-"; // 输出横线
            } else {
                cout << "a"; // 否则输出字符'a'
            }
        }
        cout << "|"; // 输出竖线
        cout << endl; // 换行
    }

    return 0; // 返回0，表示程序执行成功
}
