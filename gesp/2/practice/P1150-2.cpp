/**
 * 题目: 【GESP】C++二级模拟 luogu-p1150, Peter 的烟
 * 题号: P1150
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-p1150/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    long long n, k; // 定义两个长整型变量n和k
    cin >> n >> k; // 从标准输入流中读取n和k的值
    long long ans = 0; // 定义一个长整型变量ans，初始化为0，用于存储答案
    for (long long i = 1; i <= n; i++) { // 从1开始循环，直到i不大于n
        if (i % k == 0) { // 如果i能够被k整除
            n++; // 增加n的值
        }
        ans += 1; // 每次循环都增加ans的值
    }
    cout << ans; // 输出ans的值
    return 0; // 返回0，表示程序正常结束
}
