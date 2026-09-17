/**
 * 题目: 【GESP】C++二级练习 luogu-P5725 【深基4.习8】求三角形
 * 题号: P5725
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p5725/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义一个整型变量 n
    cin >> n; // 从标准输入读取 n 的值
    for (int i = 0; i < n; i++) { // 外层循环，循环 n 次
        for (int j = 1; j <= n; j++) { // 内层循环，循环 n 次
            printf("%02d", i * n + j); // 打印两位数，不足两位补零
        }
        cout << endl; // 每行结束后换行
    }
    cout << endl; // 打印一个空行
    int cur = 1; // 定义并初始化一个整型变量 cur 为 1
    for (int i = 0; i < n; i++) { // 外层循环，循环 n 次
        for (int j = 1; j <= n; j++) { // 内层循环，循环 n 次
            if (j < n - i) { // 如果 j 小于 n - i
                cout << "  "; // 打印两个空格
            } else { // 否则
                printf("%02d", cur); // 打印两位数，不足两位补零
                cur++; // cur 自增 1
            }
        }
        cout << endl; // 每行结束后换行
    }
    return 0; // 返回 0，表示程序正常结束
}
