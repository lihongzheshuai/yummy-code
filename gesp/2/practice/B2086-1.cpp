/**
 * 题目: 【GESP】C++二级练习 luogu-B2086, 不定方程求解
 * 题号: B2086
 * 归属: GESP2级
 * 解法: 解法 1 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b2086/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, c; // 定义三个整数变量a, b, c
    cin >> a >> b >> c; // 从输入流中读取a, b, c的值
    int count = 0; // 初始化计数器为0
    for (int i = 0; i <= 1000; i++) { // 外层循环，遍历i从0到1000
        for (int j = 0; j <= 1000; j++) { // 内层循环，遍历j从0到1000
            if (a * i + b * j == c) { // 判断是否满足方程条件
                count++; // 如果满足，则计数器加1
            }
        }
    }
    cout << count; // 输出计数器的值，即解的个数
    return 0;
}
