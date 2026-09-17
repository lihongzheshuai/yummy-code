/**
 * 题目: 【GESP】C++二级真题 luogu-b4036 [GESP202409 二级] 数位之和
 * 题号: B4036
 * 归属: GESP2级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4036/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 输入的正整数个数
    cin >> n;
    int a; // 每个正整数

    for (int i = 1; i <= n; i++) {
        cin >> a; // 读取每个正整数
        int ans = 0; // 初始化答案
        while (a != 0) {
            int j = a % 10; // 获取当前数字的最后一位
            ans += j; // 将最后一位加到答案中
            a /= 10; // 移除当前数字的最后一位
        }
        if (ans % 7 == 0) { // 如果答案能被7整除
            cout << "Yes" << endl; // 输出Yes
        } else {
            cout << "No" << endl; // 否则输出No
        }
    }
}
