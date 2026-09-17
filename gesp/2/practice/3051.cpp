/**
 * 题目: 【GESP】C++二级练习BCQM3051，浮点数余数
 * 题号: 3051
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-bcqm3051/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    double a, b;
    cin >> a >> b;
    int ans;
    ans = a / b;
    double r;
    r = a - ans * b;
    cout << r;
    return 0;
}
