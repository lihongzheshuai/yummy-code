/**
 * 题目: 【GESP】C++一级练习BCQM3056，等差数列末项计算
 * 题号: 3056
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3056/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    cout << a + (n - 1) * (b - a);
    return 0;
}
