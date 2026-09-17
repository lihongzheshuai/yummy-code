/**
 * 题目: 【GESP】C++二级练习 luogu-t259142, 数数字
 * 题号: T259142
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-t259142/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, x, ans = 0; // 定义变量n、x和计数器ans
    cin >> n >> x; // 读取输入的n和x
    for (int i = 1; i <= n; i++) { // 外层循环，从1到n遍历所有整数
        int tmp = i, num; // 定义临时变量tmp和num
        while (tmp != 0) { // 内层循环，对当前整数进行分解
            num = tmp % 10; // 获取当前整数的最后一位数字
            if (num == x) // 如果最后一位数字等于x
                ans++; // 计数器自增1
            tmp = tmp / 10; // 移除当前整数的最后一位数字
        }
    }
    cout << ans; // 输出计数器ans的值，即数字x出现的次数
    return 0;
}
