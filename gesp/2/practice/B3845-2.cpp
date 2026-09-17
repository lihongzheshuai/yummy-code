/**
 * 题目: 【GESP】C++二级练习 luogu-B3845, [GESP样题 二级] 勾股数
 * 题号: B3845
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b3845/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int n; // 定义变量n
    cin >> n; // 读取n的值
    int count = 0; // 初始化计数器
    for (int i = 1; i <= n; i++) { // 外层循环，控制i的值
        for (int j = i; j <= n; j++) { // 内层循环，控制j的值
            int c = sqrt(i * i + j * j); // 计算c的值
            if (c * c == j * j + i * i && c <= n) { // 判断是否为勾股数
                count++; // 如果是，计数器加1
            }
        }
    }
    cout << count; // 输出计数器的值
    return 0; // 返回程序执行成功
}
