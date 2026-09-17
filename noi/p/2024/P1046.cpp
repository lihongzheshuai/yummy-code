/**
 * 题目: 【GESP】C++一级练习 luogu-P1046, [NOIP2005 普及组] 陶陶摘苹果
 * 题号: P1046
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-p1046/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 初始化答案变量
    int ans = 0;
    // 定义10个苹果的高度变量
    int a, b, c, d, e, f, g, h, i, j;
    // 从输入流中读取10个苹果的高度
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j;
    // 定义陶陶能够达到的最大高度变量
    int n;
    // 从输入流中读取陶陶能够达到的最大高度
    cin >> n;
    // 将陶陶能够达到的最大高度加上板凳的高度
    n += 30;
    // 检查每个苹果的高度是否在陶陶能够达到的范围内
    if (n >= a) {
        ans++;
    }
    if (n >= b) {
        ans++;
    }
    if (n >= c) {
        ans++;
    }
    if (n >= d) {
        ans++;
    }
    if (n >= e) {
        ans++;
    }
    if (n >= f) {
        ans++;
    }
    if (n >= g) {
        ans++;
    }
    if (n >= h) {
        ans++;
    }
    if (n >= i) {
        ans++;
    }
    if (n >= j) {
        ans++;
    }
    // 输出能够摘到的苹果的数目
    cout << ans;
    return 0;
}
