/**
 * 题目: 【GESP】C++三级练习 luogu-B2089 数组逆序重存放
 * 题号: B2089
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2089/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

// 定义一个数组用于存储输入的整数，大小为105以确保足够存储100个元素
int a[105];

int main() {
    // 定义变量n用于存储数组长度
    int n;
    // 输入数组长度
    cin >> n;

    // 循环输入n个整数到数组中
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 从数组末尾开始向前遍历，实现逆序输出
    for (int i = n; i >= 1; i--) {
        cout << a[i] << " ";
    }
}
