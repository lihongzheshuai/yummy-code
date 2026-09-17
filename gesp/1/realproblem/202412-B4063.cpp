/**
 * 题目: 【GESP】C++一级真题 luogu-b4063, [GESP202412 一级] 奇数和偶数
 * 题号: B4063
 * 归属: GESP1级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4063/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 读取正整数个数
    int n;
    cin >> n;
    // 初始化偶数和奇数的个数
    int even = 0;
    int odd = 0;
    // 循环读取每个正整数
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        // 判断奇偶性并更新计数
        if (num % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    // 输出奇数和偶数的个数
    cout << odd << " " << even;
    return 0;
}
