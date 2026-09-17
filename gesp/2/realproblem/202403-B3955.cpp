/**
 * 题目: 【GESP】C++二级真题 luogu-b3955, [GESP202403 二级] 小杨的日字矩阵
 * 题号: B3955
 * 归属: GESP2级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3955/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义整数变量n，用于存储矩阵的大小
    cin >> n; // 从输入流读取整数到n
    for (int i = 1; i <= n; i++) { // 从1到n进行循环，模拟每一行的输出
        cout << "|"; // 输出竖线，表示矩阵的边界
        for (int j = 1; j <= n - 2; j++) { // 从1到n-2进行循环，模拟每一行中间部分的输出
            if (i == 1 || i == n || i == (n + 1) / 2) { // 判断当前行是否是第一行、最后一行或中间行
                cout << "-"; // 如果是，则输出横线，形成矩阵的中间横线
            } else {
                cout << "x"; // 否则，输出小写字母x，形成矩阵的上下边界和内部
            }
        }
        cout << "|" << endl; // 输出竖线，表示矩阵的边界，并换行
    }
}
