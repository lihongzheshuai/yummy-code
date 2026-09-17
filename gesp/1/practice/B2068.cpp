/**
 * 题目: 【GESP】C++一级练习 luogu-B2068,统计满足条件的 4 位数
 * 题号: B2068
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2068/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 从输入流中读取n的值
    int a; // 定义变量a
    int ans = 0; // 定义变量ans并初始化为0
    for (int i = 1; i <= n; i++) { // 循环n次
        cin >> a; // 从输入流中读取a的值
        int b, c, d, e; // 定义变量b, c, d, e
        b = a / 10 / 10 / 10; // 计算a的千位数
        c = a / 10 / 10 % 10; // 计算a的百位数
        d = a / 10 % 10; // 计算a的十位数
        e = a % 10; // 计算a的个位数
        if (e - d - c - b > 0) { // 如果a的个位数减去十位数减去百位数减去千位数的结果大于0
            ans += 1; // ans加1
        }
    }
    cout << ans; // 输出ans的值
    return 0; // 返回0，表示程序执行成功
}
