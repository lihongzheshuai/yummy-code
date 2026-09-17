/**
 * 题目: 【GESP】C++一级真题 luogu-B4034 [GESP202409 一级] 小杨购物
 * 题号: B4034
 * 归属: GESP1级 (202409认证真题)
 * 博客: https://www.coderli.com/gesp-1-luogu-b4034/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;

int main() {
    int n, a, b; // 定义变量n, a, b
    cin >> n >> a >> b; // 从输入流中读取n, a, b的值
    cout << n / (a + b); // 输出n除以a+b的结果
    return 0; // 返回0，表示程序执行成功
}
