/**
 * 题目: 【GESP】C++一级真题(202403)luogu-B3953，找因数
 * 题号: B3953
 * 归属: GESP1级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b3953/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) {
            cout << i << endl;
        }
    }
}
