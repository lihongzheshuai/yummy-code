/**
 * 题目: 【GESP】C++三级练习 luogu-B2093 查找特定的值
 * 题号: B2093
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2093/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int a[10000];
int main() {
    // 定义数组长度变量
    int n;
    // 定义要查找的数
    int x;
    // 输入数组长度
    cin >> n;
    // 循环输入n个数到数组
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // 输入要查找的数
    cin >> x;
    // 遍历数组查找x
    for (int i = 0; i < n; i++) {
        // 找到x则输出下标并结束程序
        if (x == a[i]) {
            cout << i;
            return 0;
        }
    }
    // 未找到则输出-1
    cout << "-1";
    return 0;
}
