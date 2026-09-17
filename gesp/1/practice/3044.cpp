/**
 * 题目: 【GESP】C++一级练习BCQM3044，字符形状输出
 * 题号: 3044
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3044/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    char a;
    cin >> a;
    cout << " " << " " << a << endl;
    cout << " " << a << a << a << endl;
    cout << a << a << a << a << a << endl;
    cout << " " << a << a << a << endl;
    cout << " " << " " << a;
    return 0;
}
