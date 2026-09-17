/**
 * 题目: 【GESP】C++二级练习 luogu-B2075 幂的末尾
 * 题号: B2075
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2075/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int a, b; // 定义底数a和指数b
    cin >> a >> b; // 读入底数a和指数b
    int ans = 1; // 初始化结果ans为1
    for (int i = 1; i <= b; i++) { // 循环b次
        int u = ans * a; // 计算当前结果乘以底数a
        ans = u % 1000; // 取乘积的末3位存回ans
    }
    printf("%03d", ans); // 输出结果的3位数字，不足补0
    return 0; // 返回0，表示程序正常结束
}
