/**
 * 题目: 【GESP】C++一级练习 luogu-B3659，[语言月赛202209] 课程QQ群
 * 题号: B3659
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b3659/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, k; // 定义变量n和k
    cin >> n >> k; // 从输入流中读取n和k的值
    int ans = 0; // 定义变量ans并初始化为0
    int b; // 定义变量b
    for (int i = 1; i <= n; i++) { // 循环n次
        cin >> b; // 从输入流中读取b的值
        if (b == k) { // 如果b的值等于k
            ans += 1; // ans加1
        } else {
            ans += 0; // 否则ans加0
        }
    }
    cout << ans; // 输出ans的值
    return 0; // 返回0，表示程序执行成功
}
