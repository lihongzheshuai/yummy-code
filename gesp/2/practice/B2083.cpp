/**
 * 题目: 【GESP】C++二级练习 luogu-B2083, 画矩形
 * 题号: B2083
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2083/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a, b, f; // 定义整数变量a、b和f
    char c; // 定义字符变量c
    cin >> a >> b >> c >> f; // 从输入流中读取a、b、c和f的值
    for (int i = 0; i < a; i++) { // 外层循环，控制行数
        for (int j = 0; j < b; j++) { // 内层循环，控制列数
            if (i == 0 || i == a - 1 || j == 0 || j == b - 1) { // 如果当前位置在边界上
                cout << c; // 输出字符c
            } else {
                if (f == 1) { // 如果f为1
                    cout << c; // 输出字符c
                } else {
                    cout << " "; // 否则输出空格
                }
            }
        }
        cout << endl; // 换行，结束当前行的输出
    }
    return 0;
}
