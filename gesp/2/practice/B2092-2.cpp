/**
 * 题目: 【GESP】C++二级练习 luogu-B2092, 开关灯
 * 题号: B2092
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2092/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i * i <= n; i++) {
        cout << i * i << " ";

    }
    return 0;
}
