/**
 * 题目: 【GESP】C++一级练习 luogu-B2077, 角谷猜想
 * 题号: B2077
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2077/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    long long n;  // 用 long long 类型来存储输入的数，防止大数溢出
    scanf("%lld", &n);  // 读取输入的整数，使用 %lld 来处理 long long 类型

    long long ans = 0;  // ans 用来存储当 n 是奇数时 3n + 1 的结果
    long long sum = 0;  // sum 用来存储当 n 是偶数时 n / 2 的结果

    // 当 n 不等于 1 时，继续进行计算
    while (n != 1) {
        if (n % 2 != 0) {  // 如果 n 是奇数
            ans = n * 3 + 1;  // 奇数时执行 3n + 1
            cout << n << "*3+1=" << ans << "\n";  // 输出当前操作的过程
            n = ans;  // 更新 n 为计算后的值
        } else {  // 如果 n 是偶数
            sum = n / 2;  // n / 2
            cout << n << "/2=" << sum << "\n";  // 输出当前操作的过程
            n = sum;  // 更新 n 为计算后的值
        }
    }

    // 当 n == 1 时，输出 "End" 表示结束
    printf("End");
    return 0;
}
