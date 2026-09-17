/**
 * 题目: 【GESP】C++三级练习 luogu-B2087, 与指定数字相同的数的个数
 * 题号: B2087
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2087/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义一个整数变量n，用于存储整数序列的长度
    cin >> n; // 从输入流中读取n的值
    int a; // 定义一个整数变量a，用于临时存储输入的整数
    int ans = 0; // 定义一个整数变量ans，用于存储与指定数字相同的数的个数
    int m; // 定义一个整数变量m，用于存储指定的整数
    int* count = new int[n]; // 动态分配一个长度为n的整数数组，用于存储输入的整数序列
    for (int i = 1; i <= n; i++) {
        cin >> count[i - 1]; // 从输入流中读取整数序列，并存储到count数组中
    }
    cin >> m; // 从输入流中读取指定的整数m
    for (int e = 1; e <= n; e++) {
        if (m == count[e - 1]) {
            ans += 1; // 如果当前数等于m，则ans加1
        }
    }
    cout << ans; // 输出ans的值，即与m相同的数的个数
    return 0; // 返回0，表示程序执行成功
}
