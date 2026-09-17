/**
 * 题目: 【GESP】C++二级真题 luogu-b3923, [GESP202312 二级] 小杨做题
 * 题号: B3923
 * 归属: GESP2级 (202312认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3923/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a, b, m, n; // 定义四个整数变量a、b、m、n
    cin >> a >> b >> m >> n; // 从输入流读取四个整数到a、b、m、n
    long long sum = a + b; // 初始化一个长整型变量sum，用于记录小杨总共做的题目数
    int day = 0; // 初始化一个整数变量day，用于记录每天小杨做的题目数
    if (a >= m) { // 如果a大于等于m
        cout << a; // 直接输出a
        return 0; // 程序结束
    }
    if (b >= m) { // 如果b大于等于m
        cout << a + b; // 输出a和b的和
        return 0; // 程序结束
    }
    for (int i = 1; i <= n - 2; i++) { // 从1到n-2进行循环
        day = a + b; // 计算当天小杨做的题目数
        sum += day; // 将当天做的题目数加到总和中
        if (day >= m) { // 如果当天做的题目数大于等于m
            break; // 跳出循环
        }
        a = b; // 更新a的值为b
        b = day; // 更新b的值为当天做的题目数
    }
    cout << sum; // 输出小杨总共做的题目数
    return 0; // 程序结束
}
