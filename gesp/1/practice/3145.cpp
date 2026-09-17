/**
 * 题目: 【GESP】C++一级练习BCQM3145，奇数求和
 * 题号: 3145
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3145/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int i = 0;
    for (m; m <= n; m++) {
        if (m % 2 != 0) {
            i += m;
        }
    }
    cout << i;
    return 0;
}
