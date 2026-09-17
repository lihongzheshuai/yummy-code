/**
 * 题目: 【GESP】C++一级模拟练习luogu-B3847，当天的第几秒
 * 题号: B3847
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b3847/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    char d;
    cin >> a >> b >> c >> d;
    if (d == 'A') {
        cout << a * 3600 + b * 60 + c;
    }
    if (d == 'P') {
        cout << (a + 12) * 3600 + b * 60 + c;
    }
    return 0;
}
