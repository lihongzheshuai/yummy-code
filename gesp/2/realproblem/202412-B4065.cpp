/**
 * 题目: 【GESP】C++二级真题 luogu-B4065 [GESP202412 二级] 数位和
 * 题号: B4065
 * 归属: GESP2级 (202412认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b4065/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 读取测试数据的数量
    cin >> n;
    long long a; // 读取正整数 a
    long long max = 0; // 初始化最大数位和为0
    for (int i = 1; i <= n; i++) {
        cin >> a; // 读取每个正整数
        int ans = 0; // 初始化当前数的数位和为0
        while (a != 0) {
            int j = a % 10; // 取出当前数的最后一位
            ans += j; // 将最后一位加到数位和中
            a /= 10; // 移除当前数的最后一位
        }
        if (ans > max) {
            max = ans; // 如果当前数的数位和大于最大数位和，则更新最大数位和
        }
    }
    cout << max; // 输出最大数位和
    return 0;
}
