/**
 * 题目: 【GESP】C++三级练习 luogu-B2064, 斐波那契数列
 * 题号: B2064
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-b2064/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n，用于存储测试数据的组数
    cin >> n; // 从输入流中读取n的值
    int* inputs = new int[n]; // 动态分配一个大小为n的整数数组，用于存储输入的数据
    int an = 0; // 定义变量an，用于临时存储输入的数据
    for (int i = 1; i <= n; i++) { // 循环n次，读取每个测试数据
        cin >> an; // 从输入流中读取an的值
        inputs[i - 1] = an; // 将读取到的数据存储到inputs数组中
    }
    for (int i = 1; i <= n; i++) { // 循环n次，处理每个测试数据
        if (inputs[i - 1] == 1 || inputs[i - 1] == 2) { // 如果输入的数据是1或2
            cout << 1 << endl; // 直接输出1，因为斐波那契数列的第1和第2个数都是1
        } else { // 如果输入的数据不是1或2
            int ans = 0; // 定义变量ans，用于存储计算的结果
            int a1 = 1; // 定义变量a1，用于存储斐波那契数列的第一个数
            int a2 = 1; // 定义变量a2，用于存储斐波那契数列的第二个数
            for (int j = 3; j <= inputs[i - 1]; j++) { // 从3开始，计算到输入的数据为止
                ans = a2 + a1; // 计算斐波那契数列的下一个数
                a1 = a2; // 更新a1的值
                a2 = ans; // 更新a2的值
            }
            cout << ans << endl; // 输出计算的结果
        }
    }
    return 0; // 返回0，表示程序执行成功
}
