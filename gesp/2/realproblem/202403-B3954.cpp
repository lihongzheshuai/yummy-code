/**
 * 题目: 【GESP】C++二级真题 luogu-b3954, [GESP202403 二级] 乘法问题
 * 题号: B3954
 * 归属: GESP2级 (202403认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3954/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int a; // 定义整数变量a
    cin >> a; // 从输入流读取整数到a
    int b; // 定义整数变量b
    int ans = 1; // 初始化变量ans为1，用于存储结果
    for (int i = 1; i <= a; i++) { // 从1到a进行循环
        cin >> b; // 从输入流读取整数到b
        ans *= b; // 将ans与b相乘
        if (ans <= 1000000) { // 如果ans小于等于1000000
            continue; // 继续下一次循环
        } else { // 否则
            cout << ">1000000"; // 输出">1000000"
            return 0; // 程序结束
        }
    }
    cout << ans; // 输出ans的值
    return 0; // 程序结束
}
