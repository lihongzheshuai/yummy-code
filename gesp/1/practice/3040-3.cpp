/**
 * 题目: 【GESP】C++一级练习BCQM3040，初识条件语句if，求幸运数
 * 题号: 3040
 * 归属: GESP1级
 * 解法: 解法 3 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3040/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, k;           // 定义两个整数变量n和k，分别表示上限N和除数K
    cin >> n >> k;      // 从标准输入读取n和k的值
    cout << n / k * k;  // 利用整数除法向下取整的特性，直接计算不超过n且能被k整除的最大数
    return 0;           // 程序正常结束
}
