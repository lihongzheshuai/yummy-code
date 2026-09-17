/**
 * 题目: 【GESP】C++一级练习BCQM3055，4位数间隔输出
 * 题号: 3055
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3055/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int j;
    cin >> j;
    int a, b, c, d;
    a = j % 10;
    b = j / 10 % 10;
    c = j / 10 / 10 % 10;
    d = j / 10 / 10 / 10;
    cout << d << " " << c << " " << b << " " << a;
    return 0;
}
