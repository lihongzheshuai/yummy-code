/**
 * 题目: 【GESP】C++一级真题 luogu-B4035[GESP202409 一级] 美丽数字
 * 题号: B4035
 * 归属: GESP1级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4035/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 从输入流中读取n的值
    int k = 0; // 定义变量k并初始化为0
    int a; // 定义变量a
    for (int i = 1; i <= n; i++) { // 循环n次
        cin >> a; // 从输入流中读取a的值
        if (a % 8 != 0 && a % 9 == 0) { // 如果a既不是8的倍数又是9的倍数
            k += 1; // k加1
        }
    }
    cout << k; // 输出k的值
    return 0; // 返回0，表示程序执行成功
}
