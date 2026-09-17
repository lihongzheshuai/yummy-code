/**
 * 题目: 【GESP】C++一级练习BCQM3147，for循环求和
 * 题号: 3147
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3147/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int h = 0;
    for (int i = 1; i <= n; i++) {
        h += i;
    }
    cout << h;
    return 0;
}
