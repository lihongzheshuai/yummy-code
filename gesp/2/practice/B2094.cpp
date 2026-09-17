/**
 * 题目: 【GESP】C++二级练习 luogu-B2094, 不与最大数相同的数字之和
 * 题号: B2094
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b2094/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n; // 定义一个整数变量n
    cin >> n; // 从输入流中读取n的值
    int ans = 0; // 定义一个整数变量ans，用于存储数字之和
    int a; // 定义一个整数变量a，用于存储每个数
    int max = 0; // 定义一个整数变量max，用于存储最大数
    int max_times = 0; // 定义一个整数变量max_times，用于存储最大数出现的次数
    for (int i = 1; i <= n; i++) { // 循环n次，读取每个数
        cin >> a; // 从输入流中读取a的值
        if (i == 1) { // 如果是第一个数
            max = a; // 将a赋值给max
            max_times = 1; // 最大数出现的次数为1
        } else { // 如果不是第一个数
            if (a > max) { // 如果a大于max
                max = a; // 将a赋值给max
                max_times = 1; // 最大数出现的次数为1
            } else if (a == max) { // 如果a等于max
                max_times++; // 最大数出现的次数加1
            }
        }
        ans += a; // 将a加到ans上
    }
    cout << ans - max * max_times; // 输出ans减去max乘以max_times的值
    return 0; // 返回0，表示程序执行成功
}
