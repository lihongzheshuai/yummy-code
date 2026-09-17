/**
 * 题目: 【GESP】C++二级练习 luogu-B3764, 计算阶乘
 * 题号: B3764
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3764/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int t, n; // t为测试用例的数量，n为每个测试用例的输入数
    cin >> t; // 输入测试用例的数量
    for (int i = 0; i < t; i++) { // 遍历每个测试用例
        cin >> n; // 输入当前测试用例的数
        unsigned long long result = 1; // 初始化结果为1
        if (n & 1) { // 如果n是奇数
            for (int i = 2; i <= n; i += 2) { // 从2开始，每次增加2，直到n
                result *= i; // 将当前数乘入结果
            }
        } else { // 如果n是偶数
              for (int i = 1; i <= n; i += 2) { // 从1开始，每次增加2，直到n
                result *= i; // 将当前数乘入结果
            }
        }
        cout << result * 2 << endl; // 输出结果乘以2
    }
    return 0;
}
