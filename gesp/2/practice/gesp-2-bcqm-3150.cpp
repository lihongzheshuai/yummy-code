/**
 * 题目: 【GESP】C++二级练习 bcqm-3150, 26个兄弟姐妹2
 * 题号: 
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-bcqm-3150/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a = 97;
    for (int i = 0; i < 26; i++) {
        cout << (char)a << " ";
        a += 1;
    }
    cout << endl;
    int b = 90;
    for (int i = 26; i > 0; i--) {
        cout << (char)b << " ";
        b -= 1;
    }
    return 0;
}
