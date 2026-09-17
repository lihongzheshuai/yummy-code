/**
 * 题目: 【GESP】C++一级练习 luogu-B2061, 整数的个数
 * 题号: B2061
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2061/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 读取正整数k的个数
    int n;
    cin >> n;
    // 定义三个变量，分别用来记录1，5和10出现的次数
    int k;
    int ans = 0;
    int bns = 0;
    int cns = 0;
    // 循环读取k个正整数
    for (int i = 1; i <= n; i++) {
        cin >> k;
        // 判断当前读取的数是否为1，如果是，ans加1
        if (k == 1) {
            ans += 1;
        }
        // 判断当前读取的数是否为5，如果是，bns加1
        if (k == 5) {
            bns += 1;
        }
        // 判断当前读取的数是否为10，如果是，cns加1
        if (k == 10) {
            cns += 1;
        }
    }
    // 输出1出现的次数
    cout << ans << endl;
    // 输出5出现的次数
    cout << bns << endl;
    // 输出10出现的次数
    cout << cns;
    return 0;
}
