/**
 * 题目: 【GESP】C++二级练习 luogu-B3698 [语言月赛202301] 一次函数
 * 题号: B3698
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3698/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 声明变量n(点的个数)、k(斜率)、b(截距)
    int n, k, b;
    cin >> n >> k >> b;
    // 声明变量x、y用于存储每个点的坐标
    int x, y;
    // ans用于统计在直线上的点的个数
    int ans = 0;
    // 循环读入n个点的坐标
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        // 判断点是否在直线y=kx+b上
        if (y == k * x + b) {
            // 如果在直线上，计数器加1
            ans++;
        }
    }
    // 输出在直线上的点的个数
    cout << ans;
    return 0;
}
