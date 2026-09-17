/**
 * 题目: 【GESP】C++二级练习 luogu-b2084, 质因数分解
 * 题号: B2084
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2084/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 读取输入的n
    for (int i = n - 1; i >= 2; i--) { // 从n-1开始向下遍历，直到i>=2
        if (n % i == 0) { // 如果n能被i整除
            int j = n / i; // 计算n/i的商
            bool flag = true; // 初始化标志为真
            for (int k = 2; k <= sqrt(i); k++) { // 从2开始遍历到i的平方根
                if ((i % k == 0 && i != k) || (j % k == 0 && j != k)) { // 如果i或j能被k整除，但不是k本身
                    flag = false; // 标志为假
                    break; // 跳出循环
                }
            }
            if (flag) { // 如果标志为真
                cout << i; // 输出i
                break; // 跳出循环
            }
        }
    }
    return 0;
}
