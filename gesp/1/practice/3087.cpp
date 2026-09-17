/**
 * 题目: 【GESP】C++一级练习BCQM3087，判断灯开关
 * 题号: 3087
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3087/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int m;
    cin >> m;
    if (m % 2 != 0) {
        cout << "1";
    } else {
        cout << "0";
    }
    return 0;
}
