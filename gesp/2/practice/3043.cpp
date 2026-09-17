/**
 * 题目: 【GESP】C++二级练习BCQM3043，大小写转换
 * 题号: 3043
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-bcqm3043/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    char a;
    cin >> a;
    int ans;
    ans = a - 32;
    cout << (char)ans;
    return 0;
}
