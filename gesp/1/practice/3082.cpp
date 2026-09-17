/**
 * 题目: 【GESP】C++一级练习BCQM3082，最大数输出
 * 题号: 3082
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3082/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b && a > c) {
        cout << a;
    } else if (b > a && b > c) {
        cout << b;
    } else {
        cout << c;
    }
    return 0;
}
