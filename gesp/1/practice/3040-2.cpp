/**
 * 题目: 【GESP】C++一级练习BCQM3040，初识条件语句if，求幸运数
 * 题号: 3040
 * 归属: GESP1级
 * 解法: 解法 2 / 共 3 种解法
 * 博客: https://www.coderli.com/gesp-1-bcqm3040/
 * 标准: C++11 (CCF GESP / CSP 官方规范)
 */

#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;          // 读取上限N和除数K
    int max;                // 用于记录当前找到的最大幸运数
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {   // 若i能被K整除，则i是一个候选幸运数
            max = i;        // 更新最大幸运数（因为i递增，故每次直接覆盖即可）
        }
    }
    cout << max;            // 输出最终找到的最大幸运数
    return 0;
}
