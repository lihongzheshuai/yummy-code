/**
 * 题目: 【GESP】C++二级练习 luogu-B2085, 第 n 小的质数
 * 题号: B2085
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2085/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n; // 输入的正整数
    cin >> n; // 读取输入的正整数
    for (int i = 2;; i++) { // 从2开始，循环直到找到第n个质数
        bool flag = true; // 初始化标志为真，表示i可能是质数
        if (i == 2) {
            flag = true; // 2是质数
        } else {
            for (int j = 2; j <= sqrt(i); j++) { // 检查i是否有除1和自身以外的因数
                if (i % j == 0) {
                    flag = false; // 如果i有除1和自身以外的因数，则不是质数
                    break; // 跳出循环
                }
            }
        }
        if (flag) { // 如果i是质数
            n--; // 计数减1
            if (n == 0) { // 如果计数为0，则i是第n个质数
                cout << i; // 输出第n个质数
                break; // 跳出循环
            }
        }
    }
    return 0;
}
