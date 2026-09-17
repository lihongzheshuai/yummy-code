/**
 * 题目: 【GESP】C++二级练习 luogu-T259140, 三角形
 * 题号: T259140
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-t259140/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int a; // 定义变量a
    cin >> a; // 输入a
    int b = 1; // 定义变量b并初始化为1
    for (int i = a; i > 0; i--) { // 外层循环，控制行数
        for (int j = 1; j <= i; j++) { // 内层循环，控制每行的数字个数
            if (b / 10 == 0) { // 如果b是一位数
                printf("%.02d", b); // 输出b，保留两位小数
            } else { // 如果b是两位数
                printf("%d", b); // 直接输出b
            }
            b++; // b自增
        }
        cout << endl; // 换行
    }
    return 0; // 返回0，表示程序正常结束
}
