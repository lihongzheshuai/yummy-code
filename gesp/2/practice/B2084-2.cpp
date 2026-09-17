/**
 * 题目: 【GESP】C++二级练习 luogu-b2084, 质因数分解
 * 题号: B2084
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2084/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>

using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 读取输入的n
    for (int i = 2; i <= n - 1; i++) { // 从2开始遍历到n-1
        if (n % i == 0) { // 如果n能被i整除
            cout << n / i; // 输出n/i的商
            break; // 跳出循环
        }
    }
    return 0;
}
