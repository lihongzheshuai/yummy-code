/**
 * 题目: 【GESP】C++二级练习 luogu-B2073 求小数的某一位
 * 题号: B2073
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2073/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std; // 使用标准命名空间

int main() {
    int a, b, n; // 定义变量a、b、n
    cin >> a >> b >> n; // 从输入流中读取a、b、n的值
    if (a == b) { // 如果a等于b
        cout << 0; // 输出0
        return 0; // 退出程序
    }
    int c; // 定义变量c
    for (int i = 1; i <= n; i++) { // 从1到n遍历
        a = a * 10; // 将a乘以10
        c = a / b; // 计算a除以b的商
        a = a % b; // 计算a除以b的余数
    }
    cout << c; // 输出c的值
    return 0; // 退出程序
}
