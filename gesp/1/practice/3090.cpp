/**
 * 题目: 【GESP】C++一级练习BCQM3090，奇偶数判断
 * 题号: 3090
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3090/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a;
    cin >> a;
    if (a % 2 != 0) {
        cout << "odd";
    } else {
        cout << "even";
    }
    return 0;
}
