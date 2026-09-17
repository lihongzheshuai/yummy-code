/**
 * 题目: 【GESP】C++一级练习BCQM3023，输入-计算-输出-4
 * 题号: 3023
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-bcqm3023/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义三个整型变量，分别存储大、中、小盒子的数量
    int a, b, c;
    // 从标准输入读取三个整数
    cin >> a >> b >> c;
    // 计算总盒子数:
    // 大盒子数量 + (大盒子数量 × 中盒子数量) + (大盒子数量 × 中盒子数量 × 小盒子数量)
    cout << a + a * b + a * b * c;
    return 0;
}
