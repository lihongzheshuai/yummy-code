/**
 * 题目: 【GESP】C++二级真题 luogu-b3840, [GESP202306 二级] 找素数
 * 题号: B3840
 * 归属: GESP2级 (202306认证真题)
 * 博客: https://www.coderli.com/gesp-2-luogu-b3840/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int a, b; // 定义两个整数变量a和b
    cin >> a >> b; // 从输入流中读取a和b的值
    int ans = 0; // 初始化答案变量ans为0

    for (int i = a; i <= b; i++) { // 从a到b遍历所有数
        bool flag = true; // 初始化标志变量flag为true，表示i是否为素数
        for (int j = 2; j <= sqrt(i); j++) { // 从2到i的平方根遍历所有可能的因数
            if (i % j == 0) { // 如果i能被j整除
                flag = false; // 则i不是素数，设置flag为false
                break;
            }
        }
        if (flag) { // 如果i是素数
            ans++; // 则答案加1
        }
    }
    cout << ans; // 输出答案
    return 0; // 返回0，表示程序执行成功
}
