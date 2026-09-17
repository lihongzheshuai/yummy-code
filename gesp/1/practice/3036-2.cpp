/**
 * 题目: 【GESP】C++一级练习BCQM3036，数字交换，国庆七天乐
 * 题号: 3036
 * 归属: GESP1级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3036/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    int b, c, d;
    b = a / 100;
    c = a % 100 / 10;
    d = a % 100 % 10;
    int e;
    e = d * 100 + c * 10 + b;
    cout << e;
    return 0;
}
