/**
 * 题目: 【GESP】C++二级模拟 luogu-p1179, [NOIP 2010 普及组] 数字统计
 * 题号: P1179
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-p1179/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int l, r; // 定义两个整型变量l和r，用于存储输入的范围
    cin >> l >> r; // 从标准输入流中读取l和r的值
    int ans = 0; // 定义一个整型变量ans，初始化为0，用于存储答案
    for (int i = l; i <= r; i++) { // 从l开始循环，直到i不大于r
        int j, re = i; // 定义一个整型变量j和re，re初始化为i
        while (re != 0) { // 当re不为0时循环
            j = re % 10; // 计算re除以10的余数，并赋值给j
            if (j == 2) { // 如果j等于2
                ans++; // 将ans加1
            }
            re /= 10; // 将re除以10
        }
    }
    cout << ans; // 输出ans的值
    return 0; // 返回0，表示程序正常结束
}
