/**
 * 题目: 【GESP】C++二级练习 luogu-b3669, [语言月赛202210] 购物节
 * 题号: B3669
 * 归属: GESP2级
 * 博客: https://www.coderli.com/gesp-2-luogu-b3669/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <cmath>
#include <iostream>

using namespace std;
int main() {
    int x, y; // 定义变量x和y
    int n; // 定义变量n
    cin >> x >> y >> n; // 读取输入的x, y, n
    long long result_only_1 = 0; // 初始化result_only_1为0
    result_only_1 = (x - 1) * (long long)n; // 计算result_only_1的值
    int count = n / 10; // 计算n除以10的整数部分
    int count_2 = n % 10; // 计算n除以10的余数
    long long result_1, result_2 = 0; // 定义变量result_1和result_2
    result_1 = (y - 1) * (long long)count; // 计算result_1的值
    result_2 = (x - 1) * (long long)count_2; // 计算result_2的值
    long long result = result_1 + result_2; // 计算result的值
    result = min(result_only_1, result); // 计算result的最小值
    cout << result; // 输出result的值

    return 0;
}
