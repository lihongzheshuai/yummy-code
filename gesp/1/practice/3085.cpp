/**
 * 题目: 【GESP】C++一级练习BCQM3085，最大的数
 * 题号: 3085
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3085/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double max;
    max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    cout << max;
    return 0;
}
