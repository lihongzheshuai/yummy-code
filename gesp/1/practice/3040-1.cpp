/**
 * 题目: 【GESP】C++一级练习BCQM3040，初识条件语句if，求幸运数
 * 题号: 3040
 * 归属: GESP1级
 * 解法: 解法 1 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3040/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, k;               // 定义变量n存储上限，k存储除数
    cin >> n >> k;          // 从标准输入读取n和k的值
    // 从n开始倒序遍历到1，寻找能被k整除的最大数
    for (int i = n; i >= 1; i--) {
        if (i % k == 0) {   // 若当前数i能被k整除，则i即为所求幸运数
            cout << i;      // 输出该幸运数
            break;          // 找到后立即退出循环
        }
    }
    return 0;               // 程序正常结束
}
