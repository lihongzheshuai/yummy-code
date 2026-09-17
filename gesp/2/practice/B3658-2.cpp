/**
 * 题目: 【GESP】C++二级练习 luogu-b3658, 口算练习
 * 题号: B3658
 * 归属: GESP2级
 * 解法: 解法 2 / 共 2 种解法
 * 博客: https://www.coderli.com/gesp-2-luogu-b3658/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int x, y; // 定义两个整数变量x和y
    cin >> x >> y; // 从输入流中读取x和y的值
    double temp = (double)x / y; // 计算x除以y的结果，并将结果转换为浮点数
    int result; // 定义整数变量result
    if (temp >= 0) {
        result = (int)temp; // 如果结果非负，则直接取整数部分
    } else {
        if (x % y == 0) {
            result = (int)temp; // 如果x能被y整除，则直接取整数部分
        } else {
            result = ((int)abs(temp) + 1) * -1; // 如果x不能被y整除，则向零取整
        }
    }
    cout << result; // 输出结果
    return 0; // 返回0，表示程序执行成功
}
