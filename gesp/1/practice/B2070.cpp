/**
 * 题目: 【GESP】C++一级练习 luogu-B2070, 计算分数加减表达式的值
 * 题号: B2070
 * 归属: GESP1级
 * 博客: https://www.coderli.com/gesp-1-luogu-b2070/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cstdio>
using namespace std;
int main() {
    int n; // 定义一个整数n，用于存储输入的整数
    scanf("%d", &n); // 从输入流中读取n的值
    double ans = 0; // 初始化变量ans，用于存储结果
    for (int i = 1; i <= n; i++) { // 遍历从1到n的所有整数i
        if (i % 2 != 0) { // 如果i是奇数
            ans += 1.0 / i; // 将1/i加到ans上
        }
        if (i % 2 == 0) { // 如果i是偶数
            ans -= 1.0 / i; // 将1/i减去ans
        }
    }
    printf("%.4f", ans); // 输出ans的值，保留小数点后4位
    return 0; // 返回0，表示程序执行成功
}
