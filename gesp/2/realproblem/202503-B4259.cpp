/**
 * 题目: 【GESP】C++二级真题 luogu-B4259 [GESP202503 二级] 等差矩阵
 * 题号: B4259
 * 归属: GESP2级 (202503认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4259/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    // 定义行数n和列数m
    int n, m;
    // 从控制台读入n和m
    cin >> n >> m;
    // 外层循环控制行数
    for (int i = 1; i <= n; i++) {
        // 内层循环控制列数
        for (int j = 1; j <= m; j++) {
            // 输出第i行第j列的数值，即i*j，数字间用空格分隔
            cout << i * j << " ";
        }
        // 每行结束后换行
        cout << endl;
    }
    // 程序结束
    return 0;
}
