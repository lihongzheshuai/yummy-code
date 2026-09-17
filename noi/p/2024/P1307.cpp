/**
 * 题目: 【GESP】C++三级练习 luogu-P1307, [NOIP2011 普及组] 数字反转
 * 题号: P1307
 * 归属: GESP3级
 * 博客: https://www.coderli.com/gesp-3-luogu-p1307/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    // 定义变量a用于存储输入的整数
    int a;
    cin >> a;
    // 定义数组用于存储每一位数字
    int* array = new int[10];
    // index记录数组中数字的个数
    int index = 0;
    // tmp用于存储最终结果
    int tmp = 0;
    // 处理输入为0的特殊情况
    if (a == 0) {
        cout << 0;
        return 0;
    }
    // 循环取出每一位数字存入数组
    while (a != 0) {
        // 取出最后一位数字
        int ans = a % 10;
        array[index] = ans;
        // 去掉最后一位数字
        a /= 10;
        if (a == 0) {
            break;
        } else {
            index++;
        }
    }
    // y用于计算每一位的权重(1,10,100...)
    int y = 1;
    // 从数组末尾开始,重新组合数字
    for (int i = index; i >= 0; i--) {
        tmp += array[i] * y;
        y *= 10;
    }
    // 输出结果
    cout << tmp;
    return 0;
}
