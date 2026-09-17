/**
 * 题目: 【GESP】C++一级练习BCQM3086，判断数正负
 * 题号: 3086
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3086/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int k;
    cin >> k;
    if (k > 0) {
        cout << "positive";
    } else if (k == 0) {
        cout << "zero";
    } else {
        cout << "negative";
    }
    return 0;
}
