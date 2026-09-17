/**
 * 题目: 【GESP】C++二级练习 图形输出练习06-菱形（实心）
 * 题号: 
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-local-06-dia-full-pic/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 声明变量n用于存储用户输入的菱形大小
    int n;
    cin >> n;
    // ans表示每行需要打印的星号数量，初始为1
    int ans = 1;
    // y表示每行前面需要打印的空格数量，初始为菱形的中间位置
    int y = (n + 1) / 2;

    // 打印菱形的上半部分（包括中间行）
    for (int i = 1; i <= (n + 1) / 2; i++) {
        // 打印左侧空格
        for (int j = 1; j <= y - 1; j++) {
            cout << " ";
        }
        // 打印星号
        for (int k = 1; k <= ans; k++) {
            cout << "*";
        }
        // 打印右侧空格
        for (int p = 1; p <= y - 1; p++) {
            cout << " ";
        }
        // 更新下一行的参数：减少空格数，增加星号数
        y--;
        ans += 2;
        cout << endl;
    }

    // 重置参数，准备打印下半部分
    y = 1;
    ans = n - 2;
    // 打印菱形的下半部分
    for (int i = 1; i <= (n + 1) / 2 - 1; i++) {
        // 打印左侧空格
        for (int j = 1; j <= y; j++) {
            cout << " ";
        }
        // 打印星号
        for (int k = 1; k <= ans; k++) {
            cout << "*";
        }
        // 打印右侧空格
        for (int p = 1; p <= y; p++) {
            cout << " ";
        }
        // 更新下一行的参数：增加空格数，减少星号数
        y += 1;
        ans -= 2;
        cout << endl;
    }
    return 0;
}
